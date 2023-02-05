/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_exceptions.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:17:37 by tomartin          #+#    #+#             */
/*   Updated: 2023/02/05 20:21:23 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/com_exceptions.hpp"

com_exceptions::com_exceptions(const std::string& msg, int num)
{
	this->type = "com.cpp";
}

void com_exceptions::print_error()
{
	std::cerr << "Error in " << this->type << std::endl;
	std::cerr << this->msg << " " << this->err_code << std::endl;
}
