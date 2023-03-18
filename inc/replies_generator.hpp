/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies_generator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:30:25 by tomartin          #+#    #+#             */
/*   Updated: 2023/03/18 12:01:15 by tomartin         ###   ########.fr       */
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

using namespace std;
class replies_generator : public replies
{
	public:
	std::string	admin_ok(const string& server_name, const string& admin_name, 
			const string& admin_nick, const string& admin_email);
	std::string info_rpy(const string& server_info);
	std::string invite_ok(const string& channel_name, const string& user_name);
	std::string invite_away(const string& user_nick, const string& away_msg);
	std::string ison_ok(const string& ison_list);
	std::string join_ok(const string& channel_name, string& channel_topic);
	std::string list_ok(const string& channel_list, const string& channel_topic);
	std::string mode_us_ok(const string& user_modies);
	std::string mode_ch_ok(const string& channel_name, const string& channel_mode,
			const string& channel_mod_params);
	std::string mode_banlist(const string& channel_ban_list, const string& channel_name);
	std::string mode_exceptlist(const aux_channel& channel);
	std::string mode_invitelist(const aux_channel& channel);
	std::string mode_uniqopis(const aux_channel& channel, const user& user);
	std::string mode_channelmodeis(const aux_channel& channel);
	std::string motd_ok(const aux_server& server);
	std::string names_ok(const aux_channel& channel);
	std::string oper_ok(void);
	std::string stats_l(const aux_server& server);
	std::string stats_m(const aux_server& server);
	std::string stats_o(const aux_server& server);
	std::string stats_u(const aux_server& server);
	std::string time_ok(const aux_server& server, const std::string hour);
	std::string topic_ok(const aux_channel& channel);
	std::string topic_no(const aux_channel& channel);
	std::string userhost_ok(const aux_server& server);
	std::string userip_ok(const user& user);
	std::string user_ok(const aux_server& server);
	std::string user_empty(void);
	std::string version_ok(const aux_server& server);
	std::string who_ok(const user& user);
	std::string whois_user(const user& user);
	std::string whois_channels(const user& user, const aux_channel& channel);
	std::string whois_away(const user& user);
	std::string whois_idle(const user& user);
	std::string whois_server(const user& user, aux_server& server);
	std::string whois_operator(const user& user);
	std::string ping_nooring(void);
	// std::string whowas_user(const aux_server& serv, const aux_user& user);
	//-----------------ERRORS----------------------//
	//-----------------ERRORS----------------------//
	//-----------------ERRORS----------------------//
	//-----------------ERRORS----------------------//
	std::string admin_nosuchserver(const std::string& server_name);
	std::string die_fail(void);
	std::string info_nosuchserver(const std::string& server_name);
	std::string invite_moreparams(const std::string msg);
	std::string invite_nosuchnick(const user& user);
	std::string invite_notonchannel(const aux_channel& channel);
	std::string invite_useronchannel(const user& user, const aux_channel& channel);
	std::string invite_chanoprivsneeded(const aux_channel& channel);
	std::string ison_needmoreparams(void);
	std::string join_needmoreparams(void);
	std::string join_bannedfromchan(const aux_channel& channel);
	std::string join_inviteonlychan(const aux_channel& channel);
	std::string join_badchannelkey(const std::string msg);
	std::string join_channelisfull(const aux_channel& channel);
	std::string join_badchanmask(const aux_channel& channel);
	std::string join_nosuchchannel(const std::string str);
	std::string join_toomanychannels(const aux_channel& channel);
	std::string join_toomanytargets(const std::string target);
	std::string join_unavailresource(const aux_channel& channel);
	std::string kick_needmoreparams(void);
	std::string kick_nosuchchannel(const std::string str);
	std::string kick_badchanmask(const aux_channel& channel);
	std::string kick_chanoprivsneeded(const aux_channel& channel);
	std::string kick_notonchannel(const aux_channel& channel);
	std::string kick_usernotinchannel(const user& user, aux_channel& channel);
	std::string kill_noprivileges(void);
	std::string kill_needmoreparams(void);
	std::string kill_nosuchnick(const user& user);
	std::string list_nosuchserver(const std::string& server_name);
	std::string list_toomanymatches(void);
	std::string names_nosuchserver(const std::string& server_name);
	std::string names_toomanymatches(void);
	std::string mode_needmoreparams(void);
	std::string mode_chanoprovsneeded(const aux_channel& channel);
	std::string mode_nosuchnick(const user& user);
	std::string mode_usernotinchannel(const user& user, const aux_channel& channel);
	std::string mode_notonchannel(const aux_channel& channel);
	std::string mode_keyset(const aux_channel& channel);
	std::string mode_nochanmodes(const aux_channel& channel);
	std::string mode_unknownmode(const std::string& c, const aux_channel& channel);
	std::string mode_nosuchchannel(const std::string str);
	std::string mode_usersdontmatch(void);
	std::string mode_umodeunknownflag(void);
	std::string motd_nomotd(void);
	std::string nick_nonicknamegiven(void);
	std::string nick_erroneusnickname(const user& user);
	std::string nick_nicknameinuse(const user& user);
	std::string oper_needmoreparams(void);
	std::string oper_nooperhost(void);
	std::string oper_passwdmismatch(void);
	std::string part_needmoreparams(void);
	std::string part_nosuchchannel(const std::string str);
	std::string part_notonchannel(const aux_channel& channel);
	std::string pass_needmoreparams(void);
	std::string pass_alreadyregistred(void);
	std::string ping_noorigin(void);
	std::string ping_nosuchserver(const std::string& server_name);
	std::string pong_noorigin(void);
	std::string pong_nosuchserver(const std::string& server_name);
	std::string privmsg_norecipient(const std::string cmd);
	std::string privmsg_notexttosend(void);
	std::string privmsg_cannotsendtochan(const aux_channel& channel);
	std::string privmsg_notoplevel(const std::string mask);
	std::string privmsg_wildtoplevel(const std::string mask);
	std::string privmsg_toomanytargets(const std::string target);
	//std::string privmsg_toomanytargets(const std::string mask);
	std::string privmsg_nosuchnick(const user& user);
	std::string stats_nosuchserver(const std::string& server_name);
	std::string time_nosuchserver(const std::string& server_name);
	std::string topic_needmoreparams(void);
	std::string topic_nochanmodes(const aux_channel& channel);
	std::string topic_notonchannel(const aux_channel& channel);
	std::string topic_chanoprivsneeded(const aux_channel& channel);
	std::string user_needmoreparams(void);
	std::string user_alreadyregistred(void);
	std::string userhost_needmoreparams(void);
	std::string users_nosuchserver(const std::string& server_name);
	std::string users_fileerror(const std::string f_o, const std::string file);
	std::string users_usersdisabled(void);
	std::string version_nosuchserver(const std::string& server_name);
	std::string wallops_needmoreparams(void);
	std::string who_nosuchserver(const std::string& server_name);
	std::string whois_nosuchserver(const std::string& server_name);
	std::string whois_nonicknamegiven(void);
	std::string whois_nosuchnick(const user& user);
	std::string whowas_nonicknamegiven(void);
	std::string whowas_wasnosuchnick(const user& user);
	
	public:
	void load_reply_to_users(std::queue<user> &user_list, std::string reply);

};

#endif
