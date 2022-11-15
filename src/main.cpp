/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:04:23 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/15 18:56:47 by tomartin         ###   ########.fr       */
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


	load.msg_out.print_all_msg();
}


