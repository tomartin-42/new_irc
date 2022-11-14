/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:04:23 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/14 12:49:57 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user.hpp"
#include "replies_generator.hpp"

int main(void)
{
	user	load(99, UNKNOW);
	user	a(100, UNKNOW);

	replies_generator	generator;

	load.msg_out.add_msg(generator.admin_ok(a));
	load.msg_out.print_all_msg();
}


