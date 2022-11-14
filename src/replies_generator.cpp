/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies_generator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:52:09 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/14 15:30:15 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replies_generator.hpp"

std::string	replies_generator::admin_ok(const aux_server& server, const user& admin)
{
	std::string	answ;

	answ.append(generate_msg(256, server.get_name(), "", "", ""));
	answ.append(generate_msg(257, admin.get_name(), "", "", ""));
	answ.append(generate_msg(258, admin.get_nickname(), "", "", ""));
	answ.append(generate_msg(259, admin.get_email(), "", "", ""));
	return answ;
}

std::string replies_generator::away_rpy(const user& user)
{
	return (generate_msg(301, user.get_nickname(), 
		user.get_away_msg(), "", ""));
}

std::string replies_generator::away_unaway(void)
{
	return(generate_msg(305, "", "", "", ""));
}

std::string replies_generator::away_nowaway(void)
{
	return(generate_msg(306, "", "", "", ""));
}

std::string replies_generator::info_rpy(const aux_server& server)
{
	std::string answ;

	answ.append(generate_msg(371, server.get_info(), "", "", ""));
	answ.append(generate_msg(374, "", "", "", ""));
	return answ;
}

std::string replies_generator::invite_ok(const aux_server& server, 
	const user& user)
{
	return(generate_msg(341, server.get_chanel_name(), 
		user.get_name(), "", ""));
}
