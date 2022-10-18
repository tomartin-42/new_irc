/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:53:28 by tomartin          #+#    #+#             */
/*   Updated: 2022/10/18 20:22:32 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include <iostream>

server::server(int port) : com(port)
{
	int	fd = get_fd_socket();

	this->n_connections = 0;
	socket_lisent();
	users.insert(std::pair<int, user>(fd, user(fd, SOCKET)));
	set_value_poll_list(fd, POLLIN);
}

void	server::insert_new_user(const int fd)
{
		users.insert(std::make_pair(fd, user(fd, UNKNOW)));
}

void	server::delete_user(const int fd)
{
		users.erase(fd);
}

void	server::accept_new_connect()
{
	int	fd;

	fd = accept_connection_in_socket();
	if(fd != -1)
	{
		insert_new_user(fd);
		this->n_connections++;
		std::cout << "HOLA" << std::endl;
		send_msg(fd, "HOLA\n");
	}
	if(n_connections > MAX_CONNECTIONS)
	{
		this->users.find(fd)->second.set_type(EXPULSE);
	//	disconnect_user(fd, "PIRATE SERVER LLENO");
		this->n_connections--;
		this->delete_user(fd);
		return;
	}
}

//This function is in charge of reading the revents
//and makes the decision if it sends or reads a msg
void	server::read_or_write_all_users()
{
    std::map<int, user>::iterator   it = users.begin();
    short							revent;
    
    while(it != users.end())
    {
    	if(it->first != get_fd_socket())
		{
			revent = get_revent(it->first);
			if(revent & POLLIN)
    		//To Read
			//	it->second.msg_in.add_msg(recv_msg(it->first));
				send_all(recv_msg(it->first));
			if(revent & POLLOUT)
    		//To Write
				send_msg(it->first, it->second.msg_out.extract_msg());
		}
		it++;
    }
}

void	server::send_all(std::string msg)
{
    std::map<int, user>::iterator   it = users.begin();
    int	num;
    
    while(it != users.end())
    {
    	if(it->first != get_fd_socket())
		{
			it->second.msg_out.add_msg(msg);
			num = send_msg(it->first, it->second.msg_out.extract_msg());
			std::cout << "NUM " << num << " " << it->first << std::endl; 
			it->second.msg_out.pop_msg();
		}
		it++;
	}
}
