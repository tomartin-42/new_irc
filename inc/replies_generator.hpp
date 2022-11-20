/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies_generator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:30:25 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/20 19:17:38 by tomartin         ###   ########.fr       */
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
};

#endif
