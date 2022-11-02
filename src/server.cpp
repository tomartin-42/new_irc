/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:53:28 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/03 10:22:33 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include <iostream>

server::server(int port) : com(port)
{
	int	fd = get_fd_socket();

	socket_lisent();
	//users.insert(std::pair<int, user>(fd, user(fd, SOCKET)));
	set_value_poll_list(fd, POLLIN);
}

void	server::insert_new_user(const int fd)
{
	users.insert(std::make_pair(fd, user(fd, UNKNOW)));
}

void	server::delete_user(const int fd)
{
	this->users.erase(fd);
	disconnect_user(fd);	
}

void	server::accept_new_connect()
{
	int	fd;

	fd = accept_connection_in_socket();
	if(fd != -1)
	{
		insert_new_user(fd);
		std::cout << "CONEXION IN FD " << fd << std::endl;
		send_msg(fd, "HOLA\n");
	}
	if(users.size() > MAX_CONNECTIONS)
	{
		this->users.find(fd)->second.set_type(EXPULSE);
		disconnect_user(fd, "PIRATE SERVER LLENO");
		this->delete_user(fd);
		return;
	}
}


//This function scroll through the entire list of users
//If the user have POLLIN event, it read de msg
//If the user have msg in msg_q_out, it send msg
void    server::orchestation()
{
	std::map<int, user>::iterator	usr_it = users.begin();
	std::map<int, user>::iterator	current_it;

	while(usr_it != users.end())
    {
		if (get_revent(usr_it->first) & POLLHUP)
		{
			//Desconectar
			current_it = usr_it;
			delete_user(current_it->first);
			//disconnect_user(current_it->first);
			++usr_it;
			//users.erase(current_it);
			continue;
		}
    	//TO READ
        this->recv_msgs(usr_it->first);
        //TO SEND
        this->send_msgs(usr_it->first);
        ++usr_it;
    }
}

//This function send msgs from msg_out queue in user
//Only send if msg_out queue have any msg
//If msg can't send all chars, it resize msg and erase
//the character send suscefull
void	server::send_msgs(const int fd)
{
	std::map<int, user>::iterator	usr_it = users.find(fd);
    int                             send_leng;

	if(usr_it->second.msg_out.msg_q_size() == 0)
		return;
	if(!(get_event(usr_it->first) & POLLOUT) || (get_revent(usr_it->first) & POLLOUT)) 
   {
		send_leng = send_msg(usr_it->first, usr_it->second.msg_out.extract_msg());
		if(send_leng < usr_it->second.msg_out.msg_front_len())
			usr_it->second.msg_out.erase_front_msg(send_leng);
		else
		    usr_it->second.msg_out.pop_msg();
    }
}

//This function read and load msg in one user
void    server::recv_msgs(const int fd)
{
    std::map<int, user>::iterator	usr_it = users.find(fd);

    if((get_revent(usr_it->first) & POLLIN))
		usr_it->second.msg_in.add_msg(recv_msg(usr_it->first));
}

/*
//This funciton sen a msg from user
//If the msg dont sent complety put the fd in POLLOUT
void	server::send_msg_from_user(const int fd)
{
	std::string						msg;
    std::map<int, user>::iterator   usr = users.find(fd);
    int								b_send;

	msg = usr->second.msg_out.extract_msg();
	b_send = send_msg(fd, msg);
	if(b_send < static_cast<int>(msg.size()))
		set_value_poll_list(fd, POLLOUT);
}
*/
/*void	server::recv_msg_from_user(const int fd)
{
	std::string	msg;

	msg = recv_msg(fd);
	this->users.find(fd)->second.msg_int.add_msg(msg);
}*/
