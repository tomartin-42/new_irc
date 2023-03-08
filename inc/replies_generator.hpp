/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies_generator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:30:25 by tomartin          #+#    #+#             */
/*   Updated: 2023/03/08 13:28:39 by tommy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REPLIES_GENERATOR_HPP_
# define _REPLIES_GENERATOR_HPP_

#include "replies.hpp"
#include "user.hpp"
#include "aux_server.hpp"
#include "aux_channel.hpp"
#include <string>
#include <queue>

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
	std::string join_inviteonlychan(const aux_channel& channel);
	std::string join_badchannelkey(const aux_channel& channel);
	std::string join_channelisfull(const aux_channel& channel);
	std::string join_badchanmask(const aux_channel& channel);
	std::string join_nosuchchannel(const std::string str);
	std::string join_toomanychannels(const aux_channel& channel);
	std::string kick_needmoreparams(const std::string cmd);
	std::string kick_nosuchchannel(const std::string str);
	std::string kick_badchanmask(const aux_channel& channel);
	std::string kick_chanoprivsneeded(const aux_channel& channel);
	std::string kick_notonchannel(const aux_channel& channel);
	std::string kill_noprivileges(void);
	std::string kill_needmoreparams(const std::string cmd);
	std::string kill_nosuchnick(const user& user);
	std::string list_nosuchserver(const aux_server& server);
	std::string mode_needmoreparams(const std::string cmd);
	std::string mode_chanoprovsneeded(const aux_channel& channel);
	std::string mode_nosuchnick(const user& user);
	std::string mode_notonchannel(const aux_channel& channel);
	std::string mode_keyset(const aux_channel& channel);
	std::string mode_unknownmode(const std::string& c, const aux_channel& channel);
	std::string mode_nosuchchannel(const std::string str);
	std::string mode_usersdontmatch(void);
	std::string mode_umodeunknownflag(void);
	std::string modt_nomodtd(void);
	std::string nick_nonicknamegiven(void);
	std::string nick_erroneusnickname(const user& user);
	std::string nick_nicknameinuse(const user& user);
	std::string oper_needmoreparams(const std::string cmd);
	std::string oper_nooperhost(void);
	std::string oper_passwdmismatch(void);
	std::string part_needmoreparams(const std::string cmd);
	std::string part_nosuchchannel(const std::string str);
	std::string part_notonchannel(const aux_channel& channel);
	std::string pass_needmoreparams(const std::string cmd);
	std::string pass_alreadyregistred(void);
	std::string ping_noorigin(void);
	std::string ping_nosuchserver(const aux_server& server);
	std::string pong_noorigin(void);
	std::string pong_nosuchserver(const aux_server& server);
	std::string privmsg_norecipient(const std::string cmd);
	std::string privmsg_notexttosend(void);
	std::string privmsg_cannotsendtochan(const aux_channel& channel);
	std::string privmsg_notoplevel(const std::string mask);
	std::string privmsg_wildtoplevel(const std::string mask);
	//std::string privmsg_toomanytargets(const std::string mask);
	std::string privmsg_nosuchnick(const user& user);
	std::string stats_nosuchserver(const aux_server& server);
	std::string time_nosuchserver(const aux_server& server);
	std::string topic_needmoreparams(const std::string cmd);
	std::string topic_nochanmodes(const aux_channel& channel);
	std::string topic_notonchannel(const aux_channel& channel);
	std::string topic_chanoprivsneeded(const aux_channel& channel);
	std::string user_needmoreparams(const std::string cmd);
	std::string user_alreadyregistred(void);
	std::string userhost_needmoreparams(const std::string cmd);
	std::string users_nosuchserver(const aux_server& server);
	std::string users_fileerror(const std::string f_o, const std::string file);
	std::string users_usersdisabled(void);
	std::string version_nosuchserver(const aux_server& server);
	std::string wallops_needmoreparams(const std::string cmd);
	std::string who_nosuchserver(const aux_server& server);
	std::string whois_nosuchserver(const aux_server& server);
	std::string whois_nonicknamegiven(void);
	std::string whois_nosuchnick(const user& user);
	std::string whowas_nonicknamegiven(void);
	std::string whowas_wasnosuchnick(const user& user);
	
	public:
	void load_reply_to_users(std::queue<user> &user_list, std::string reply);

};

#endif
