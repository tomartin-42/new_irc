/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tommy_commands.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:35:13 by tomartin          #+#    #+#             */
/*   Updated: 2023/03/12 19:02:34 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replies_generator.hpp"
#include "user.hpp"
#include "aux_server.hpp"


void	command_ping(user& user, replies_generator& replies, aux_server& server);
void	command_pong(user& user, replies_generator& replies, aux_server& server);

