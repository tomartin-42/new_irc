/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:51:19 by tomartin          #+#    #+#             */
/*   Updated: 2022/10/29 17:20:20 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msg.hpp"

bool	msg::check_if_empty() const
{
	if(this->msg_q.empty())
		return true;
	return false;
}

//This function limit the msg_q front to 512 and
//put the correct end characters 
//Use in get_next_msg
std::string	& msg::msg_adecuation(std::string &str)
{
	if(str.size() > 510)
	{
		str.resize(512);
		str[510] = '\x0d';
		str[511] = '\x0a';
	}
	return str;
}

//Use when ther is more than one msg in one read
//Have a buffer when save all not end msg
std::string	msg::get_next_msg()
{
	std::string::size_type	point;

	point = this->buff_aux.find("\x0d\x0a", 0);
	std::string	ret(this->buff_aux.substr(0, (point)));
	this->buff_aux.erase(0, (point + 2));
	return this->msg_adecuation(ret);
}

void	msg::add_msg(const char* str) 
{
	this->buff_aux.append(str);
	while(this->buff_aux.find("\x0d\x0a", 0) != std::string::npos)
		this->msg_q.push(this->get_next_msg());

}

void	msg::add_msg(const std::string str)
{
	this->buff_aux.append(str);
	while(this->buff_aux.find("\x0d\x0a", 0) != std::string::npos)
		this->msg_q.push(this->get_next_msg());
}

std::string	msg::extract_msg()
{
	return this->msg_q.front();
}

int	msg::number_msg() const
{
	return msg_q.size();
}

msg::~msg()
{
	while(!this->msg_q.empty())
		this->msg_q.pop();
}

//From debug
void	msg::print_all_msg()
{
	std::queue<std::string>	aux(this->msg_q);

	while(!aux.empty())
	{
		std::cout << "MSG: " << aux.front() << std::endl;
		aux.pop();
	}
}

int		msg::msg_q_size()
{
	return (this->msg_q.size());
}

int		msg::msg_front_len()
{
	return (this->msg_q.front().length());
}

void	msg::pop_msg()
{
	this->msg_q.pop();
}

//dell the first n_char from msg_q.front()
void	msg::erase_front_msg(const int n_chars)
{
	msg_q.front().erase(0, n_chars);
}

//This function add str to msg_g
//Only use when the str is ok and dont need parse
void	msg::direct_push(const std::string str)
{
	this->msg_q.push(str);
}

//This function add str to msg_g
//Only use when the str is ok and dont need parse
void	msg::direct_push(const char* str)
{
	this->msg_q.push(std::string(str));
}
