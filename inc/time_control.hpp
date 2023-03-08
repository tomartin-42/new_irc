/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:42:49 by tomartin          #+#    #+#             */
/*   Updated: 2023/03/08 14:54:53 by tommy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TIME_CONTROL_HPP_
#define _TIME_CONTROL_HPP_

#include <ctime>
#include <climits>
#include "ft_ircserv.hpp"

class time_control
{
	private:
		std::time_t	t_ping;
		std::time_t	t_no_ping;
		std::time_t	t_not_login;
		std::time_t	t_set_pollout;
		std::time_t	t_last_msg;
		bool		kick;
		bool		s_ping; //sended ping
	
	public:
		time_control();
		std::time_t			get_t_ping() const;
		void				set_t_ping(const std::time_t time);
		void				launch_t_ping();
		void				launch_t_last_msg();
		void				reset_ping_time();
		std::time_t			get_t_last_msg();
		void				set_t_last_msg(const time_t time);
		std::time_t			get_t_not_login();
		void				set_t_not_login(const time_t time);
		void				reset_t_not_login();
		void				reset_t_ping();
		void				set_kick(const bool value);
		bool				get_kick();
		static std::time_t	get_time();
		static void			get_time(std::time_t* var);
		void				check_if_kick();
		bool				launch_send_ping() const;
		void				set_s_ping(bool value);
		bool				get_s_ping() const;
};

#endif

