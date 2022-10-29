/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:53:28 by tomartin          #+#    #+#             */
/*   Updated: 2022/10/29 17:34:09 by tomartin         ###   ########.fr       */
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
		std::cout << "CONEXION IN" << std::endl;
		send_msg(fd, "HOLA\n");
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

//This function send msgs from msg_out queue in users
//Only send if msg_out queue have any msg
//If msg can't send all chars, it resize msg and erase
//the character send suscefull
void	server::send_msgs()
{
	std::map<int, user>::iterator	usr_it = users.begin();
	int								send_leng;

	while(usr_it != users.end())
	{
		if(usr_it->second.msg_out.msg_q_size() != 0)
		{
			send_leng = send_msg(usr_it->first, usr_it->second.msg_out.extract_msg());
			if(send_leng < usr_it->second.msg_out.msg_front_len())
				usr_it->second.msg_out.erase_front_msg(send_leng);
			else
				usr_it->second.msg_out.pop_msg();
		}
		usr_it++;
	}
}

//This funciton sen a msg from user
//If the msg dont sent complety put the fd in POLLOUT
//and risize the msg to next send
void	server::send_msg_from_user(const int fd)
{
	std::string						msg;
    std::map<int, user>::iterator   usr = users.find(fd);
    int								b_send;

	msg = usr->second.msg_out.extract_msg();
	b_send = send_msg(fd, msg);
	if(b_send == static_cast<int>(msg.size()))
		usr->second.msg_out.pop_msg();
	else
    {
		set_value_poll_list(fd, POLLOUT);
    }
}

/*void	server::recv_msg_from_user(const int fd)
{
	std::string	msg;

	msg = recv_msg(fd);
	this->users.find(fd)->second.msg_int.add_msg(msg);
}*/
