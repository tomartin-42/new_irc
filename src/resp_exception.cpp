/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resp_exception.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:43:53 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/05 15:34:18 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resp_exceptions.hpp"

resp_exceptions::server_exceptions(const int num)
{
	switch(num)
	{
		case 1: //when open socket fail
			this->fail_generate_msg();
			break;
	}
}

const	char* resp_exceptions::what() const throw()
{
	return "Custom exception in resp_exception";
}

void    resp_exception::fail_generate_msg();
{
    std::cerr << "Not found code in rpl list" << std::endl;
   	std::cerr << this->what() << std::endl;
}
