/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:53:33 by tomartin          #+#    #+#             */
/*   Updated: 2023/02/02 20:19:38 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/time_control.hpp"
#include <iostream>

time_control::time_control(): t_ping(0), kick(0)
{ 
	this->t_test = 1;
	this->t_test = this->t_test ^ 1;
	std::cout << "TEST TIME " << this->t_test << std::endl;
}

clock_t	time_control::get_t_ping() { return this->t_ping; }

void	time_control::set_t_ping(const time_t time)
{
	this->t_ping = time;	
}
void	time_control::set_kick(const bool value)
{
	this->kick = value;
}

bool	time_control::get_kick()
{
	return this->kick;
}

time_t	time_control::get_time()
{
	return std::time(NULL);
}

void	time_control::get_time(time_t* var)
{
	std::time(var);
}
