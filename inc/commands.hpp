/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:05:01 by tomartin          #+#    #+#             */
/*   Updated: 2023/03/05 19:37:37 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COMMANDS_HPP_
# define _COMMANDS_HPP_

#include <string>
#include "user.hpp"

struct commands
{
	void	ping(user& user, std::string host_name);
	void	pong(user& user, std::string host_name);
};
#endif
