/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:33:25 by tomartin          #+#    #+#             */
/*   Updated: 2023/02/04 18:10:36 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/log.hpp"

log::log()
{
	try{
		this->log_file.open(LOG_FILE, std::ios::out | std::ios::trunc);
		this->log_file.close();
	}
	catch(const std::exception &e)
	{
		std::cerr << "File open error" << std::endl;
	}
}

log::~log()
{
	try
	{
		this->log_file.close();
	}
	catch(const std::exception &e)
	{
		std::cerr << "File close error" << std::endl;
	}
}

void	log::open_to_append()
{
	try
	{
		this->log_file.open(LOG_FILE, std::ios::out | std::ios::app);
	}
	catch(const std::exception &e)
	{
		std::cerr << "File open error" << std::endl;
	}
}

void	log::put_msg(const std::string& to, const std::string& at, const std::string& msg)
{
	time_t				now = time_control::get_time();
	std::string			str_now = ctime(&now);
	std::stringstream	str;
	std::string			output;

	this->open_to_append();
	str << "[" << to << "]" << " >> " << "[" << at << "]" << "[TIME]" << str_now << " -- " << msg;
	output = str.str();
	try
	{
		this->log_file << output << std::endl;
		this->log_file.close();
	}
	catch(const std::exception &e)
	{
		std::cerr << "Can't write in log file" << std::endl;
	}
}


