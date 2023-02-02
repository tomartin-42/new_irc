/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:42:49 by tomartin          #+#    #+#             */
/*   Updated: 2023/02/02 20:03:11 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TIME_CONTROL_HPP_
#define _TIME_CONTROL_HPP_

#include <ctime>

class time_control
{
	private:
		time_t	t_ping;
		time_t	t_test;
		bool	kick;
	
	public:
		time_control();
		clock_t				get_t_ping();
		void				set_t_ping(const time_t time);
		void				set_kick(const bool value);
		bool				get_kick();
		static time_t		get_time();
		static void			get_time(time_t* var);
};

#endif

