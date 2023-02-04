/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:53:33 by tomartin          #+#    #+#             */
/*   Updated: 2023/02/04 15:56:41 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/time_control.hpp"
#include <iostream>

time_control::time_control(): t_ping(LONG_MAX), kick(OK)
{ 
	//When connect start the time to last msg
	time_control::get_time(&this->t_last_msg);
	//Control the time not login user
	time_control::get_time(&this->t_not_login);
}

time_t	time_control::get_t_ping() { return this->t_ping; }

void	time_control::set_t_ping(const time_t time)
{
	this->t_ping = time;	
}

time_t	time_control::get_t_last_msg() { return this->t_last_msg; }

void	time_control::set_t_last_msg(const time_t time)
{
	this->t_last_msg = time;	
}

time_t	time_control::get_t_not_login() { return this->t_not_login; }

void	time_control::set_t_not_login(const time_t time)
{
	this->t_not_login = time;	
}
void	time_control::reset_t_not_login() { this->t_not_login = LONG_MAX; }

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

void	time_control::reset_ping_time()
{
	this->t_ping = LONG_MAX;
}

//This function check all time values
//If one value exced the time parametres set kick variable ti KICK
//At the end of cycle all users set to KICK kick
void	time_control::check_if_kick()
{
	time_t	now = time_control::get_time();	

	if ((now - this->t_ping) > TIME_PING)
		this->kick = KICK;
	if((now - this->t_not_login) > TIME_DONT_LOGIN)
		this->kick = KICK;
}
