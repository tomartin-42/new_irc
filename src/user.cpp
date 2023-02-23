/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:17:58 by tomartin          #+#    #+#             */
/*   Updated: 2023/02/23 20:06:44 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/user.hpp"

user::user(int fd, sock_info sock, char type) : _fd(fd), sock(sock), type(type)
{
	(void)_fd;
	//set times
}

void	user::set_nick(const std::string name)
{
	this->nick = name;
}
	
void	user::set_type(const char type)
{
	this->type = type;
}

std::time_t	user::get_start_time() const
{
	return this->start_time;
}

short   user::send_or_recive() const
{
	if(this->type == EXPULSE)
		return POLLRDBAND;
    if(this->msg_out.check_if_empty())
        return POLLIN;
    return POLLOUT;
}

std::string	user::get_host_name() const
{
	char	host[255];

	getnameinfo((struct sockaddr *)&(this->sock), sizeof(this->sock), host, sizeof(host), NULL, 0, 0);
	return std::string(host);
}


