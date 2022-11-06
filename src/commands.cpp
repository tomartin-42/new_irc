/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:05:49 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/06 18:50:53 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.hpp"

void	commands::admin(minstd::string target)
{
	//Instructs the server to return information about the administrators
	//of the server specified by <target>, where <target> is either 
	//a server or a user. If <target> is omitted, the server should 
	//return information about the administrators of the current server.
	
	/*Numeric Replies:

           ERR_NOSUCHSERVER
           RPL_ADMINME                     RPL_ADMINLOC1
           RPL_ADMINLOC2                   RPL_ADMINEMAIL
	*/
}

void	commands::away(std::string message)
{
	//   With the AWAY message, clients can set an automatic reply 
	//   string for any PRIVMSG commands directed at them 
	//   (not to a channel they are on).
	//	The automatic reply is sent by the server to client sending the
	//	PRIVMSG command.  The only replying server is the one to which the
	//	sending client is connected to.

	//	The AWAY message is used either with one parameter (to set an AWAY
	//	message) or with no parameters (to remove the AWAY message).

	/*   Numeric Replies:

           RPL_UNAWAY                      RPL_NOWAWAY
	*/

	/* Examples:

   AWAY :Gone to lunch.  Back in 5 ; set away message to "Gone to lunch.
                                   Back in 5".

   :WiZ AWAY                       ; unmark WiZ as being away.
	*/
}

void	commands::die(void)
{
	//Instructs the server to shut down.
	//Only server operators
}

void	commands::error(std::string message)
{
	//This command is for use by servers to report errors to other servers. 
	//It is also used before terminating client connections.
}

void	commands::help(void)
{
	//Print help file
	//Not formally RFC command but is funny
}

void	commands::info(std::string target)
{
	//Returns information about the <target> server, or the current 
	//server if <target> is omitted.
	//Information returned includes the server's version, when it was
	//compiled, the patch level, when it was started, and any other 
	//information which may be considered to be relevant.
	
	/* Numeric Replies:

           ERR_NOSUCHSERVER
           RPL_INFO                        RPL_ENDOFINFO
	*/
	/*
	Examples:

   INFO csd.bu.edu                 ; request an INFO reply from
   csd.bu.edu

   :Avalon INFO *.fi               ; INFO request from Avalon for first
                                   server found to match *.fi.
    */
}


