/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:05:01 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/08 12:05:25 by tomartin         ###   ########.fr       */
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
	void	join(std::string chanels, std::passwords);
	void	kick(std::string chanel, std::string user, std::string msg);
	void	kill(std::nickname, std::string msg);
	void	list(std::chanels);
	void	mode(std::string chanel, std::string flags, std::string args); //to chanel
	void	mode(std::string user, std::strng flags); //to user
	void	motd(std::string server);
	void	names(std::chanels);
	void	nick(std::new_nick);
	
};
#endif
