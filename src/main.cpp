/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:04:23 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/26 19:38:37 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user.hpp"
#include "replies_generator.hpp"
#include "aux_server.hpp"

int main(void)
{
	user	load(99, UNKNOW);
	user	a(100, UNKNOW);

	replies_generator	generator;
	aux_server			serv;
	aux_channel			chan;

	load.msg_out.add_msg(generator.admin_ok(serv, a));
	load.msg_out.add_msg(generator.away_rpy(a));
	load.msg_out.add_msg(generator.away_unaway());
	load.msg_out.add_msg(generator.away_nowaway());
	load.msg_out.add_msg(generator.info_rpy(serv));
	load.msg_out.add_msg(generator.invite_ok(serv, a));
	load.msg_out.add_msg(generator.invite_away(a));
	load.msg_out.add_msg(generator.ison_ok("ISON LIST"));
	load.msg_out.add_msg(generator.join_ok(serv));
	load.msg_out.add_msg(generator.list_ok(serv));
	load.msg_out.add_msg(generator.mode_us_ok(a));
	load.msg_out.add_msg(generator.mode_ch_ok(chan));
	load.msg_out.add_msg(generator.mode_banlist(chan));
	load.msg_out.add_msg(generator.mode_exceptlist(chan));
	load.msg_out.add_msg(generator.mode_invitelist(chan));
	load.msg_out.add_msg(generator.mode_uniqopis(chan, a));
	load.msg_out.add_msg(generator.motd_ok(serv));
	load.msg_out.add_msg(generator.names_ok(chan));
	load.msg_out.add_msg(generator.oper_ok(serv));
	load.msg_out.add_msg(generator.stats_l(serv));
	load.msg_out.add_msg(generator.stats_m(serv));
	load.msg_out.add_msg(generator.stats_o(serv));
	load.msg_out.add_msg(generator.stats_u(serv));
	load.msg_out.add_msg(generator.time(serv));
	load.msg_out.add_msg(generator.topic_ok(chan));
	load.msg_out.add_msg(generator.topic_no(chan));
	load.msg_out.add_msg(generator.user_ok(serv));
	load.msg_out.add_msg(generator.user_empty());
	load.msg_out.add_msg(generator.version_ok(serv));
	load.msg_out.add_msg(generator.version_ok(serv));
	load.msg_out.add_msg(generator.admin_fail(serv));
	load.msg_out.add_msg(generator.die_fail());
	load.msg_out.add_msg(generator.info_fail(serv));
	load.msg_out.add_msg(generator.invite_moreparams("COMANDO"));
	load.msg_out.add_msg(generator.invite_nosuchnick(chan));
	load.msg_out.add_msg(generator.invite_notonchannel(chan));
	load.msg_out.add_msg(generator.invite_useronchannel(a, chan));
	load.msg_out.add_msg(generator.invite_chanoprivsneeded(chan));
	load.msg_out.add_msg(generator.ison_needmoreparams("COMMAND"));
	load.msg_out.add_msg(generator.join_needmoreparams("COMMAND"));
	load.msg_out.add_msg(generator.join_bannedfromchan(chan));






	load.msg_out.print_all_msg();
}


