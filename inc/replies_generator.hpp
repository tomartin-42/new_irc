/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies_generator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:30:25 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/26 18:41:16 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REPLIES_GENERATOR_HPP_
# define _REPLIES_GENERATOR_HPP_

#include "replies.hpp"
#include "user.hpp"
#include "aux_server.hpp"
#include "aux_channel.hpp"
#include <string>

class replies_generator : public replies
{
	public:
	std::string	admin_ok(const aux_server&, const user& admin);	
	std::string away_rpy(const user& user);
	std::string away_unaway(void);
	std::string away_nowaway(void);
	std::string info_rpy(const aux_server& server);
	std::string invite_ok(const aux_server& server, const user& user);
	std::string invite_away(const user& user);
	std::string ison_ok(const std::string ison_list);
	std::string join_ok(const aux_server& server);
	std::string list_ok(const aux_server& server);
	std::string mode_us_ok(const user& user);
	std::string mode_ch_ok(const aux_channel& chanel);
	std::string mode_banlist(const aux_channel& channel);
	std::string mode_exceptlist(const aux_channel& channel);
	std::string mode_invitelist(const aux_channel& channel);
	std::string mode_uniqopis(const aux_channel& channel, const user& user);
	std::string motd_ok(const aux_server& server);
	std::string names_ok(const aux_channel& channel);
	std::string oper_ok(const aux_server& server);
	std::string stats_l(const aux_server& server);
	std::string stats_m(const aux_server& server);
	std::string stats_o(const aux_server& server);
	std::string stats_u(const aux_server& server);
	std::string time(const aux_server& server);
	std::string topic_ok(const aux_channel& channel);
	std::string topic_no(const aux_channel& channel);
	std::string userhost_ok(const aux_server& server);
	std::string userip_ok(const user& user);
	std::string user_ok(const aux_server& server);
	std::string user_empty(void);
	std::string version_ok(const aux_server& server);
	std::string who_ok(const aux_server& server);
	// std::string whois_ok() // pending
	// std::string whowas_user(const aux_server& serv, const aux_user& user);
	//-----------------ERRORS----------------------//
	//-----------------ERRORS----------------------//
	//-----------------ERRORS----------------------//
	//-----------------ERRORS----------------------//
	std::string admin_fail(const aux_server& server);
	std::string die_fail(void);
	std::string info_fail(const aux_server& server);
	std::string invite_moreparams(const std::string msg);
	std::string invite_nosuchnick(const aux_channel& channel);
	std::string invite_notonchannel(const aux_channel& channel);
	std::string invite_useronchannel(const user& user, const aux_channel& channel);
	std::string invite_chanoprivsneeded(const aux_channel& channel);
	std::string ison_needmoreparams(const std::string msg);
	std::string join_needmoreparams(const std::string msg);
	std::string join_bannedfromchan(const aux_channel& channel);
};

#endif
