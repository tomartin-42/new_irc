/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:14:09 by tomartin          #+#    #+#             */
/*   Updated: 2023/02/22 19:40:41 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _USER_HPP_
# define _USER_HPP_

#include <string>
#include <ctime>
#include <poll.h>

#include "ft_ircserv.hpp" 
#include "../inc/msg.hpp"
#include "../inc/time_control.hpp"

class user
{
	private:
		time_control	user_times;
        int				_fd;
		std::string		nick;
		char			type;

		user(int fd, char type);
		void		set_nick(const std::string name);
		void		set_type(const char type);
		std::time_t get_start_time() const;
        short       send_or_recive() const;

        //-------------------------------------//
        //-------------------------------------//

//		std::string	get_server() const {return "SERVER NAME";}
		std::string get_name() const {return "USER NAME";}
		std::string get_nickname() const {return "USER NICKNAME";}
		std::string get_email() const {return "USER@EMAIL.COM";}
		std::string get_away_msg() const {return "AWAY MSG ESTOY COMIENDO";}
		std::string get_modies() const {return "+Twx";}
		std::string get_ip() const {return "192.168.10.1";}
};
#endif
