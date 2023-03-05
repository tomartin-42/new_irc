/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:05:49 by tomartin          #+#    #+#             */
/*   Updated: 2023/03/05 19:41:59 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/commands.hpp"

void	commands::ping(user& user, std::string host_name)
{
	user.msg_out.direct_push(std::string(":" + host_name + " PING" + "\x0d\x0a"));
	user.user_times.launch_t_ping();
	user.user_times.set_s_ping(true);
}

void	commands::pong(user& user)
{
	user.user_times.reset_t_ping();
}

