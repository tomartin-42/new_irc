/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies_generator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:52:09 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/12 17:09:41 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replies_generator.hpp"

std::string	replies_generator::admin_ok(const user& admin)
{
	std::string	answ;

	answ.append(generate_msg(256, admin.get_server(), void, void, void));
	answ.append(generate_msg(257, admin.get_name(), void, void, void));
	answ.append(generate_msg(258, admin.get_nickname(), void, void, void));
	answ.append(generate_msg(259, admin.get_email(), void, void, void));
	return answ;
}

