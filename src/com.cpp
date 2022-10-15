/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:35:15 by tomartin          #+#    #+#             */
/*   Updated: 2022/10/15 19:15:36 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.hpp"
#include <iostream>

com::com(const int port) : port(port)
{
	//Prereserve poll_list 
	//+2 is for socket and conexion over the limit
    this->poll_list.reserve(MAX_CONNECTIONS + 2);
	this->set_data_socket(port);
	this->open_socket();
}

com::~com()
{
	close(this->fd_socket);
}

void	com::set_data_socket(const int port)
{
    this->data_socket.sin_family = AF_INET;
    this->data_socket.sin_addr.s_addr = INADDR_ANY;
    this->data_socket.sin_port = htons(port);
    //this->data_socket_len = sizeof(data_socket);
    //this->port = port;
}

//Open socket. If can't do it launch a exception
//then set values in socket with setsockopt()
//Add to vector poll_list the socket
void	com::open_socket() 
{
    int					enable = 1;
    int					fcntl_control;
    int					bind_control;

    this->fd_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->fd_socket == -1)
    	throw com_exceptions(1);

    setsockopt(this->fd_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &enable, sizeof(enable));    
	
	bind_control = bind(this->fd_socket, (const sockaddr*)&(this->data_socket), sizeof(data_socket));
	if (bind_control == -1)
		throw com_exceptions(3);

	fcntl_control = fcntl(this->fd_socket, F_SETFL, O_NONBLOCK);
	if (fcntl_control == -1)
		throw com_exceptions(2);
	poll_list.push_back((pollfd){this->fd_socket, POLLIN, 0});
}

//Put a socket in lisening
void com::socket_lisent()
{
	int	listen_control;

	listen_control = listen(this->fd_socket, MAX_CONNECTIONS);
	if (listen_control == -1)
		throw com_exceptions(4);
}

//Accept new connection in socket an put on nonblock
//Add to poll_list vector
//Return the new connect fd
int	com::accept_connection_in_socket()
{
	struct sockaddr_storage	client;
	socklen_t				addr_len = sizeof(sockaddr_storage);
	int						new_fd = -1;

	if(this->poll_list[0].revents == 1)
	{
		new_fd = accept(this->fd_socket, (struct sockaddr *)&(client), &addr_len);
		fcntl(new_fd, F_SETFL, O_NONBLOCK);
		this->poll_list.push_back((pollfd){new_fd, 0, 0});
	}
	return new_fd;
}

void    com::reset_to_zero_revents()
{
    std::vector<pollfd>::iterator it = this->poll_list.begin();

    while(it != this->poll_list.end())
    {
        it->revents = 0;
        it++;
    }
}

//This function set all pollfd.revent to 0 and execut poll()
//If poll fail throw a com_exception
int    com::preparation_com()
{
    int answ;

    print_all_pollfd();
    this->reset_to_zero_revents();
    answ = poll(&this->poll_list[0], this->poll_list.size(), 1000);
    if(answ == -1)
    	throw com_exceptions(5);
    return answ;
}

//Rutine to disconnect one user. Close connection and 
//remove form poll_list
//Send a msg send a message with the reason for the disconnection
int	com::disconnect_user(const int fd, std::string reason)
{
	(void)reason;

	//AQUI SE LE ENVIARIA EL RASON//////////////////////////////////
	this->delete_in_poll_list(fd);
	this->close_connection(fd);

	return 1;
}

//Close one connection
//Need the fd to close
void	com::close_connection(const int fd)
{
	close(fd);
}

//Return port value
int	com::get_port() const
{
	return this->port;
}

//Return fd socket
int	com::get_fd_socket() const
{
	return this->fd_socket;
}

//Insert element in poll_list
//Remember the pollfd from socket are inside the poll_list
void	com::insert_in_poll_list(const int fd)
{
	this->poll_list.push_back((pollfd){fd, 0, 0});
}

void	com::delete_in_poll_list(const int fd)
{
    std::vector<pollfd>::iterator it = this->poll_list.begin();
    
    while(it != this->poll_list.end())
	{
		if(it->fd == fd)
		{
			this->poll_list.erase(it);
			return;
		}
		it++;
	}
}

int	com::set_value_poll_list(const int fd, const short event)
{
    std::vector<pollfd>::iterator it = this->poll_list.begin();

    while(it != this->poll_list.end())
    {
    	if(it->fd == fd)
		{
    		it->events = event;
    		return 1;
		}
		it++;
	}
	return -1;
}


//-------------TO DEBUG--------------------//

void	com::print_all_pollfd()
{
	std::vector<pollfd>::iterator it = this->poll_list.begin();

	while(it != this->poll_list.end())
	{
		std::cout << "FD-> " << it->fd << std::endl;
		std::cout << "EVENT-> " << it->events << std::endl;
		std::cout << "REVENT-> " << it->revents << std::endl;
		it++;
	}
}
