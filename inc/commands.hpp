/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:05:01 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/06 20:37:35 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COMMANDS_HPP_
# define _COMMANDS_HPP_

#include <string>

struct commands
{
	void	admin(std::string target);
	void	away(std::string message);
	void	die(void);
	void	error(std::string message);
	void	help(void);
	void	info(std::string target);
	void	invite(std::string nick, std::string chanel);
	void	ison(std::string nicklist);
	
};
#endif
