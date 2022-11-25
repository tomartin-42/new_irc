/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:05:01 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/25 19:38:02 by tomartin         ###   ########.fr       */
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
	void	mode(std::string user, std::strng flags); //to user
	void	mode(std::string chanel, std::string flags, std::string args); //to chanel
	void	motd(std::string server);
	void	names(std::chanels);
	void	nick(std::new_nick);
	void	notice(std::string nickname, std::string msg);
	void	oper(std::string user, std::string password);
	void	part(std::string chanels);
	void	pass(std::string password);
	void	ping(std::string user);
	void	pong(std::string to, std::string from); 
	void	privmsg(std::string receivers, std::string msg);
	void	quit(std::string msg);
	void	squery(std::string service, std::string text);
	void	setname(std::string new_name);
	void	stats(std::string query);
	void	time(void);
	void	topic(std::string channel, std::string topic);
	void	user(std::string user, std::string mode, std::string unused, std::string realname);
	void	userhost(std::string names);
	void	userip(std::string nickname);
	void	users(std::string server);
	void	version(std::string server);
	void	wallops(std::string msg);
	void	who(std::string name);
	void	whois(std::string server, std::string nicknames);
	void	whowas(std::string nicknames, std::string count, std::string server);
};
#endif
