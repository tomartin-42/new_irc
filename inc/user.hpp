/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:14:09 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/20 20:21:17 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _USER_HPP_
# define _USER_HPP_

#include <string>
#include <ctime>
#include <poll.h>
#include "ft_ircserv.hpp" 
#include "msg.hpp"

class user
{
	private:
        int         _fd;
		std::string	nick;
		char		type;
		std::time_t	start_time;	//This time stamp use to don't allow 
								//the connetion open and don't login
								//into the serve. Check for each 10s 
								//if is login ok, do nothing

	public:
		msg			msg_in;
		msg			msg_out;

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
