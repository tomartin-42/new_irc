/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:53:28 by tomartin          #+#    #+#             */
/*   Updated: 2022/10/17 10:21:00 by tomartin         ###   ########.fr       */
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
	std::cout << "accep_new_connect in server fd= " << fd << std::endl;
	if(fd != -1)
	{
		insert_new_user(fd);
		this->n_connections++;
		std::cout << "HOLA" << std::endl;
	}
	if(n_connections > MAX_CONNECTIONS)
	{
		this->users.find(fd)->second.set_type(EXPULSE);
		disconnect_user(fd, "PIRATE SERVER LLENO");
		this->n_connections--;
		this->delete_user(fd);
		return;
	}
}

//This function sincronizate all user with the need to
//send or recive to pollfd struct in com
//Them set socket_fd to POLLIN
void    server::sincronizate_polls()
{
    std::map<int, user>::iterator   it = users.begin();
    int                             control = 1;
    
    while(it != users.end())
    {
        control = set_value_poll_list(it->first, it->second.send_or_recive());
        it++;
    }
    set_value_poll_list(get_fd_socket(), POLLIN);
}
