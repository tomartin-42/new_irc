/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:05:49 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/08 12:18:45 by tomartin         ###   ########.fr       */
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

void	commands::join(std::chanels, std::passwords)
{
	//The JOIN command is used by client to start listening a specific 
	//channel.
	//The conditions which affect this are as follows:
	//1.  the user must be invited if the channel is invite-only;
	//2.  the user's nick/username/hostname must not match any active bans;
	//3.  the correct key (password) must be given if it is set.
	//
	//These are discussed in more detail under the MODE command 
	//(see section 4.2.3 for more details).
	//Once a user has joined a channel, they receive notice about all
	//commands their server receives which affect the channel. This
	//includes MODE, KICK, PART, QUIT and of course PRIVMSG/NOTICE.
	//
	//If a JOIN is successful, the user is then sent the channel's topic 
	//(using RPL_TOPIC) and the list of users who are on the channel 
	//(using RPL_NAMREPLY), which must include the user joining.
	
	/*Numeric Replies:

           ERR_NEEDMOREPARAMS              ERR_BANNEDFROMCHAN
           ERR_INVITEONLYCHAN              ERR_BADCHANNELKEY
           ERR_CHANNELISFULL               ERR_BADCHANMASK
           ERR_NOSUCHCHANNEL               ERR_TOOMANYCHANNELS
           RPL_TOPIC

   Examples:

   JOIN #foobar                    ; join channel #foobar.

   JOIN &foo fubar                 ; join channel &foo using key "fubar".

   JOIN #foo,&bar fubar            ; join channel #foo using key "fubar"
                                   and &bar using no key.

   JOIN #foo,#bar fubar,foobar     ; join channel #foo using key "fubar".
                                   and channel #bar using key "foobar".

   JOIN #foo,#bar                  ; join channels #foo and #bar.

   :WiZ JOIN #Twilight_zone        ; JOIN message from WiZ
	*/
}

void	command::kick(std::string chanel, std::string user, std::string msg)
{
	//The KICK command can be used to forcibly remove a user from a channel.
	//Only a channel operator may kick another user out of a  channel.
	
	/*Numeric Replies:

           ERR_NEEDMOREPARAMS              ERR_NOSUCHCHANNEL
           ERR_BADCHANMASK                 ERR_CHANOPRIVSNEEDED
           ERR_NOTONCHANNEL

   Examples:

	KICK &Melbourne Matthew         ; Kick Matthew from &Melbourne

	KICK #Finnish John :Speaking English
                                ; Kick John from #Finnish using
                                "Speaking English" as the reason
                                (comment).

	:WiZ KICK #Finnish John         ; KICK message from WiZ to remove John
                                from channel #Finnish

	NOTE:
		 It is possible to extend the KICK command parameters to the
	following:

	<channel>{,<channel>} <user>{,<user>} [<comment>]
	*/
}

void	commands::kill(std::nickname, std::string msg)
{
	//The KILL message is used to cause a client-server connection to be 
	//closed by the server which has the actual connection.  KILL is used 
	//by servers when they encounter a duplicate entry in the list of valid
	//nicknames and is used to remove both entries.  It is also available
	//to operators.

	// NOTE:
	// It is recommended that only Operators be allowed to kill other users
	// with KILL message.

	/*Numeric Replies:

           ERR_NOPRIVILEGES                ERR_NEEDMOREPARAMS
           ERR_NOSUCHNICK                  ERR_CANTKILLSERVER
	*/
}

void	commands::list(std::chanels)
{
	//The list message is used to list channels and their topics.  If  the
	//<channel>  parameter  is  used,  only  the  status  of  that  channel
	//is displayed.  Private  channels  are  listed  (without  their
	//topics)  as channel "Prv" unless the client generating the query is
	//actually on that channel.  Likewise, secret channels are not listed
	//at  all  unless  the client is a member of the channel in question.
	
	/*   Numeric Replies:

           ERR_NOSUCHSERVER                RPL_LISTSTART
           RPL_LIST                        RPL_LISTEND

   Examples:

   LIST                            ; List all channels.

   LIST #twilight_zone,#42         ; List channels #twilight_zone and #42
   */
}

void	commands::mode(std::string chanel, std::string flags, std::string args); //to chanel
{
	/*
	Parameters: <channel> {[+|-]|o|p|s|i|t|n|b|v} [<limit>] [<user>]
               [<ban mask>]

	The MODE command is provided so that channel operators may change the
   characteristics of `their' channel.  It is also required that servers
   be able to change channel modes so that channel operators may be
   created.

   The various modes available for channels are as follows:

           o - give/take channel operator privileges;
           p - private channel flag;
           s - secret channel flag;
           i - invite-only channel flag;
           t - topic settable by channel operator only flag;
           n - no messages to channel from clients on the outside;
           m - moderated channel;
           l - set the user limit to channel;
		   b - set a ban mask to keep users out;
           v - give/take the ability to speak on a moderated channel;
           k - set a channel key (password).

    When using the 'o' and 'b' options, a restriction on a total of three
   per mode command has been imposed.  That is, any combination of 'o'
   and
   */
}

void	commands::mode(std::string user, std::strng flags); //to user
{
	/*
	Parameters: <nickname> {[+|-]|i|w|s|o}

   The user MODEs are typically changes which affect either how the
   client is seen by others or what 'extra' messages the client is sent.
   A user MODE command may only be accepted if both the sender of the
   message and the nickname given as a parameter are both the same.

   The available modes are as follows:

           i - marks a users as invisible;
           s - marks a user for receipt of server notices;
           w - user receives wallops;
           o - operator flag.

   Additional modes may be available later on.

   If a user attempts to make themselves an operator using the "+o"
   flag, the attempt should be ignored.  There is no restriction,
   however, on anyone `deopping' themselves (using "-o").  Numeric
   Replies:

           ERR_NEEDMOREPARAMS              RPL_CHANNELMODEIS
           ERR_CHANOPRIVSNEEDED            ERR_NOSUCHNICK
           ERR_NOTONCHANNEL                ERR_KEYSET
           RPL_BANLIST                     RPL_ENDOFBANLIST
           ERR_UNKNOWNMODE                 ERR_NOSUCHCHANNEL

           ERR_USERSDONTMATCH              RPL_UMODEIS
           ERR_UMODEUNKNOWNFLAG
	

	Examples:

           Use of Channel Modes:

MODE #Finnish +im               ; Makes #Finnish channel moderated and
                                'invite-only'.

MODE #Finnish +o Kilroy         ; Gives 'chanop' privileges to Kilroy on
								 chanel #Finish

MODE #Finnish +v Wiz            ; Allow WiZ to speak on #Finnish.

MODE #Fins -s                   ; Removes 'secret' flag from channel
                                #Fins.

MODE #42 +k oulu                ; Set the channel key to "oulu".

MODE #eu-opers +l 10            ; Set the limit for the number of users
                                on channel to 10.

MODE &oulu +b                   ; list ban masks set for channel.

MODE &oulu +b *!*@*             ; prevent all users from joining.

MODE &oulu +b *!*@*.edu         ; prevent any user from a hostname
                                matching *.edu from joining.

        Use of user Modes:

:MODE WiZ -w                    ; turns reception of WALLOPS messages
                                off for WiZ.

:Angel MODE Angel +i            ; Message from Angel to make themselves
                                invisible.

MODE WiZ -o                     ; WiZ 'deopping' (removing operator
                                status).  The plain reverse of this
                                command ("MODE WiZ +o") must not be
                                allowed from users since would bypass
                                the OPER command.
*/
}

void	commands::motd(std::string server)
{
	//Returns the message of the day on <server> or the current server 
	//if it is omitted.
	
	/*
		Numeric Replies:
           RPL_MOTDSTART                   RPL_MOTD
           RPL_ENDOFMOTD                   ERR_NOMOTD
	*/
}

void	commands::names(std::string chanels)
{
	/*
	    Parameters: [<channel>{,<channel>}]

   By using the NAMES command, a user can list all nicknames that are
   visible to them on any channel that they can see.  Channel names
   which they can see are those which aren't private (+p) or secret (+s)
   or those which they are actually on.  The <channel> parameter
   specifies which channel(s) to return information about if valid.
   There is no error reply for bad channel names.

   If no <channel> parameter is given, a list of all channels and their
   occupants is returned.  At the end of this list, a list of users who
   are visible but either not on any channel or not on a visible channel
   are listed as being on `channel' "*".

   Numerics:

           RPL_NAMREPLY                    RPL_ENDOFNAMES

   Examples:

   NAMES #twilight_zone,#42        ; list visible users on #twilight_zone
                                   and #42 if the channels are visible to
                                   you.

   NAMES                           ; list all visible channels and users
	*/
}

void	commands::nick(std::new_nick)
{
	//NICK message is used to give user a nickname or change 
	//the previous one.
	//If a NICK message arrives at a server which already knows about an
	//identical nickname for another client, a nickname collision occurs. 
	//As a result of a nickname collision, all instances of the nickname 
	//are removed from the server's database, and a KILL command is issued 
	//to remove the nickname from all other server's database. If the NICK 
	//message causing the collision was a nickname change, then the 
	//original (old) nick must be removed as well.
	
	//If the server recieves an identical NICK from a client which is 
	//directly connected, it may issue an ERR_NICKCOLLISION to the local
	//client, drop the NICK command, and not generate any kills.
	
	/*Numeric Replies:

           ERR_NONICKNAMEGIVEN             ERR_ERRONEUSNICKNAME
           ERR_NICKNAMEINUSE               ERR_NICKCOLLISION

   Example:

   NICK Wiz                        ; Introducing new nick "Wiz".

   :WiZ NICK Kilroy                ; WiZ changed his nickname to Kilroy.
   */
}

void	commands::notice(std::string nickname, std::string text)
{
	/*
	The NOTICE message is used similarly to PRIVMSG.  The difference
   between NOTICE and PRIVMSG is that automatic replies must never be
   sent in response to a NOTICE message.  This rule applies to servers
   too - they must not send any error reply back to the client on
   receipt of a notice.  The object of this rule is to avoid loops
   between a client automatically sending something in response to
   something it received.  This is typically used by automatons (clients
   with either an AI or other interactive program controlling their
   actions) which are always seen to be replying lest they end up in a
   loop with another automaton.

   See PRIVMSG for more details on replies and examples.
	*/
}


