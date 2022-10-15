/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_exceptions.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:02:04 by tomartin          #+#    #+#             */
/*   Updated: 2022/10/14 20:01:21 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_exceptions.hpp"

server_exceptions::server_exceptions(const int num)
{
	switch(num)
	{
		case 1: //when open socket fail
			this->fail_poll_sincr();
			break;
	}
}

void    server_exceptions::fail_poll_sincr()
{
    std::cerr << "Error when set pollfd struct" << std::endl;
    std::cerr << "Maybe not found fd in vector pollfd" << std::endl;
    std::cerr << "At sometime the pollfd vector has not been update" << std::endl;
   	std::cerr << this->what() << std::endl;
}
