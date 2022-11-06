/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:05:49 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/06 19:34:10 by tomartin         ###   ########.fr       */
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


void	commands::invite(std::string nick, std::string chanel)
{
	//Invites <nickname> to the channel <channel>.[9] <channel>
	//does not have to exist, but if it does, only members of 
	//the channel are allowed to invite other clients. If the channel 
	//mode i is set, only channel operators may invite other clients.
	
	/* Numeric Replies:

           ERR_NEEDMOREPARAMS              ERR_NOSUCHNICK
           ERR_NOTONCHANNEL                ERR_USERONCHANNEL
           ERR_CHANOPRIVSNEEDED
           RPL_INVITING                    RPL_AWAY

   Examples:

   :Angel INVITE Wiz #Dust         ; User Angel inviting WiZ to channel
                                   #Dust

   INVITE Wiz #Twilight_Zone       ; Command to invite WiZ to
                                   #Twilight_zone
    */
}

void	commands::ison(std::string nicklist)
{
	//The ISON command was implemented to provide  a  quick  and  efficient
	//means  to get a response about whether a given nickname was currently
	//on IRC. ISON only takes one (1) parameter: a space-separated list of
	//nicks.  For  each  nickname in the list that is present, the server
	//adds that to its reply string.  Thus the reply string may return
	//empty (none  of  the given  nicks are present), an exact copy of the
	//parameter string (all of them present) or as any other subset of the
	//set of nicks  given  in  the parameter.  The only limit on the number
	//of nicks that may be checked is that the combined length must not be
	//too large as to cause the server to chop it off so it fits in 512
	//characters.

	//ISON is only be processed by the server local to the client sending 
	//the command and thus not passed onto other servers for further
	//processing.
	
	/*Numeric Replies:

           RPL_ISON                ERR_NEEDMOREPARAMS

   Examples:

   ISON phone trillian WiZ jarlek Avalon Angel Monstah
                                   ; Sample ISON request for 7 nicks.
	*/
}



