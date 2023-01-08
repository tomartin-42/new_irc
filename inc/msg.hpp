/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:01:05 by tomartin          #+#    #+#             */
/*   Updated: 2023/01/08 14:46:44 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MSG_HPP_
# define _MSG_HPP_

#include <queue>
#include <string>
#include <iostream>

class msg
{
	private:
		std::queue<std::string>	msg_q;
		std::string				buff_aux;
	
		std::string	get_next_msg();
		std::string	& msg_adecuation(std::string &str);
	public:
		~msg();
		bool			check_if_empty() const;
		int				number_msg() const;
		void			add_msg(const char* str);
		void			add_msg(const std::string str);
		std::string		extract_msg();
		void			print_all_msg();
		int				msg_q_size();
		int				msg_front_len();
		void			pop_msg();
		void			erase_front_msg(const int n_chars);
		void			direct_push(const std::string str);
		void			direct_push(const char* str);
		std::string		fragmentation_msg_send(std::string str, int point);
		//std::istream&	operator>>(const std::string str, msg queue);
};

#endif

