/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestator.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:53:28 by tomartin          #+#    #+#             */
/*   Updated: 2023/02/23 21:49:52 by tommy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/orchestator.hpp"
#include <iostream>

orchestator::orchestator(int port) : com(port)
{
	int	fd = get_fd_socket();

	socket_lisent();
	//users.insert(std::pair<int, user>(fd, user(fd, SOCKET)));
	set_value_poll_list(fd, POLLIN);
}

void	orchestator::insert_new_user(int fd, sock_info client, char type)
{
	users.insert(std::make_pair(fd, user(fd, client, type)));
}

void	orchestator::delete_user(const int fd)
{
	this->users.erase(fd);
	disconnect_user(fd);	
}

//Accept new incomming comunication
void	orchestator::accept_new_connect()
{
	int				fd = -1;
	sock_info	client;

	client = accept_connection_in_socket();
	fd = client.fd;
	if(fd != -1)
	{
		insert_new_user(client.fd, client, UNKNOW);
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
//It's the heard of send-recv orchestator
void    orchestator::orchestation()
{
	std::map<int, user>::iterator	usr_it = users.begin();
	std::vector<int>				delete_list;

	while(usr_it != users.end())
    {
		if (get_revent(usr_it->first) & POLLHUP)
		{
			delete_list.push_back(usr_it->first);
			//Desconectar
			++usr_it;
			continue;
		}
    	//TO READ
        this->recv_msgs(usr_it->first);
        //TO SEND
        this->send_msgs(usr_it->first);
        ++usr_it;
    }
    delete_users_from_list(delete_list);
}


//This function get the list that is generated in the orchestaton function 
//and contains all sockets that have received a POLLHUP(forcing disconnection) signal
//iterates through the entire list, deleting and removing the sockets in the list
void	orchestator::delete_users_from_list(std::vector<int>& list)
{
	std::vector<int>::iterator	it_list = list.begin();

	while(it_list != list.end())
	{
		disconnect_user(*it_list);
		users.erase(*it_list);
		close_connection(*it_list);
		// To debug
		std::cout << "Desconectado FD: " << *it_list << std::endl;
		it_list++;
	}
	list.clear();
}

//This function send msgs from msg_out queue in user
//Only send if msg_out queue have any msg
//If msg can't send all chars, it resize msg and 
//erase the msg part will be send suscessfull
//If whill be send all chars in msg and the socket is
//set POLLOUT it's set POLLIN because it's restore the connection
void	orchestator::send_msgs(const int fd)
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
			if(get_revent(usr_it->first) & POLLOUT)
				set_value_poll_list(usr_it->first, POLLIN);
    }
}

//This function read and load msg in one user
void    orchestator::recv_msgs(const int fd)
{
    std::map<int, user>::iterator	usr_it = users.find(fd);

    if((get_revent(usr_it->first) & POLLIN))
		usr_it->second.msg_in.add_msg(recv_msg(usr_it->first));
}

/*
//This funciton sen a msg from user
//If the msg dont sent complety put the fd in POLLOUT
void	orchestator::send_msg_from_user(const int fd)
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
void	orchestator::recv_msg_from_user(const int fd)
{
	std::string	msg;

	msg = recv_msg(fd);
	this->users.find(fd)->second.msg_in.add_msg(msg);
}

