/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies_generator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:52:09 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/20 19:15:30 by tomartin         ###   ########.fr       */
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

std::string replies_generator::invite_away(const user& user)
{
	return (generate_msg(301, user.get_nickname(), 
		user.get_away_msg(), "", ""));
}

std::string replies_generator::ison_ok(const std::string ison_list)
{
	return (generate_msg(303, ison_list, "", "", ""));
}

std::string replies_generator::join_ok(const aux_server& server)
{
	return(generate_msg(332, server.get_chanel_name(), server.get_chanel_topic(),
		"", ""));
}

std::string replies_generator::list_ok(const aux_server& server)
{
	std::string answ;
	answ.append(generate_msg(322, server.get_chanel_name(), 
		server.get_chanel_topic(), "", ""));
	answ.append(generate_msg(323, "", "", "", ""));
	return answ;
}

std::string replies_generator::mode_us_ok(const user& user)
{
	return(generate_msg(221, user.get_modies(), "", "", ""));
}

std::string replies_generator::mode_ch_ok(const aux_channel& channel)
{
	return (generate_msg(324, channel.get_name(), channel.get_mode(),
		channel.get_mod_params(), ""));
}

std::string replies_generator::mode_banlist(const aux_channel& channel)
{
	std::string answ;
	answ.append(generate_msg(367, channel.get_ban_list(), "", "", ""));
	answ.append(generate_msg(368, channel.get_name(), "", "", ""));
	return answ;
}

std::string replies_generator::mode_exceptlist(const aux_channel& channel)
{
	std::string answ;
	answ.append(generate_msg(348, channel.get_name(), channel.get_excep_list(),
		"", ""));
	answ.append(generate_msg(349, channel.get_name(), "", "", ""));
	return(answ);
}

std::string replies_generator::mode_invitelist(const aux_channel& channel)
{
	std::string answ;
	answ.append(generate_msg(346, channel.get_name(), channel.get_invite_list(),
		"", ""));
	answ.append(generate_msg(347, channel.get_name(), "", "", ""));
	return(answ);
}

std::string replies_generator::mode_uniqopis(const aux_channel& channel, const user& user)
{
	return(generate_msg(325, channel.get_name(), user.get_nickname(), "", ""));
}

std::string replies_generator::motd_ok(const aux_server& server)
{
	std::string answ;
	answ.append(generate_msg(375, server.get_name(), "", "", ""));
	answ.append(generate_msg(372, server.get_motd(), "", "", ""));
	answ.append(generate_msg(376, "", "", "", ""));
	return(answ);
}

std::string replies_generator::names_ok(const aux_channel& channel)
{
	std::string answ;
	answ.append(generate_msg(353, channel.get_name(), channel.get_names_list(),
		"", ""));
	answ.append(generate_msg(366, channel.get_name(), "", "", ""));
	return(answ);
}

std::string replies_generator::oper_ok(const aux_server& server)
{
	(void)server;
	return(generate_msg(381, "", "", "", ""));
}

std::string replies_generator::stats_l(const aux_server& server)
{
	std::string answ;
	answ.append(generate_msg(211, server.get_stats_l(), "", "", ""));
	answ.append(generate_msg(219, server.get_stats_letter(), "", "", ""));
	return(answ);
}

std::string replies_generator::stats_m(const aux_server& server)
{
	std::string answ;
	answ.append(generate_msg(212, server.get_stats_m(), "", "", ""));
	answ.append(generate_msg(219, server.get_stats_letter(), "", "", ""));
	return(answ);
}

std::string replies_generator::stats_o(const aux_server& server)
{
	std::string answ;
	answ.append(generate_msg(212, server.get_stats_o(), "", "", ""));
	answ.append(generate_msg(219, server.get_stats_letter(), "", "", ""));
	return(answ);
}

std::string replies_generator::stats_u(const aux_server& server)
{
	std::string answ;
	answ.append(generate_msg(242, server.get_stats_u(), "", "", ""));
	answ.append(generate_msg(219, server.get_stats_letter(), "", "", ""));
	return(answ);
}

std::string replies_generator::time(const aux_server& server)
{
	return(generate_msg(391, server.get_name(), server.get_time(), "", ""));
}
