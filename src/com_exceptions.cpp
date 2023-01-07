/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_exceptions.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:17:37 by tomartin          #+#    #+#             */
/*   Updated: 2023/01/07 19:12:02 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/com_exceptions.hpp"

com_exceptions::com_exceptions(const int num)
{
	switch(num)
	{
		case 1: //when open socket fail
			this->open_socket_fail();
			break;
		case 2: //when fcntl function fail
			this->fcntl_fail();
			break;
		case 3: //when bind function fail
			this->bind_fail();
			break;
		case 4: //when listen function fail
			this->listen_fail();
			break;
		case 5: //when poll function fail
			this->poll_fail();
			break;
	}
}

const char*	com_exceptions::what() const throw()
{
	return "Custom exception in com_exception";
}

void com_exceptions::open_socket_fail()
{
	std::cerr << "Open socket error" << std::endl;
	std::cerr << this->what() << std::endl;
}

void com_exceptions::fcntl_fail()
{
	std::cerr << "fcntl error" << std::endl;
	std::cerr << this->what() << std::endl;
}

void com_exceptions::bind_fail()
{
	std::cerr << "bind error" << std::endl;
	std::cerr << this->what() << std::endl;
}

void com_exceptions::listen_fail()
{
	std::cerr << "listen error" << std::endl;
	std::cerr << this->what() << std::endl;
}

void com_exceptions::poll_fail()
{
	std::cerr << "poll error" << std::endl;
	std::cerr << this->what() << std::endl;
}
