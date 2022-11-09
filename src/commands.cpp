/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:05:49 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/09 18:06:07 by tomartin         ###   ########.fr       */
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

void	commands::notice(std::string nickname, std::string msg)
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

void	commands::oper(std::string user, std::string password)
{
	/*
	 *  OPER message is used by a normal user to obtain operator privileges.
   The combination of <user> and <password> are required to gain
   Operator privileges.

   If the client sending the OPER command supplies the correct password
   for the given user, the server then informs the rest of the network
   of the new operator by issuing a "MODE +o" for the clients nickname.

   The OPER message is client-server only.

   Numeric Replies:

           ERR_NEEDMOREPARAMS              RPL_YOUREOPER
           ERR_NOOPERHOST                  ERR_PASSWDMISMATCH

   Example:

   OPER foo bar                    ; Attempt to register as an operator
                                   using a username of "foo" and "bar" as
                                   the password.
	*/
}

void	commands::part(std::string chanels)
{
	/*
	    The PART message causes the client sending the message to be removed
   from the list of active users for all given channels listed in the
   parameter string.

   Numeric Replies:

           ERR_NEEDMOREPARAMS              ERR_NOSUCHCHANNEL
           ERR_NOTONCHANNEL

   Examples:

   PART #twilight_zone             ; leave channel "#twilight_zone"

   PART #oz-ops,&group5            ; leave both channels "&group5" and
                                   "#oz-ops".
	*/
}

void	commands::pass(std::string password)
{
	/*
	    The PASS command is used to set a 'connection password'.  The
   password can and must be set before any attempt to register the
   connection is made.  Currently this requires that clients send a PASS
   command before sending the NICK/USER combination and servers *must*
   send a PASS command before any SERVER command.  The password supplied
   must match the one contained in the C/N lines (for servers) or I
   lines (for clients).  It is possible to send multiple PASS commands
   before registering but only the last one sent is used for
   verification and it may not be changed once registered.  Numeric
   Replies:

           ERR_NEEDMOREPARAMS              ERR_ALREADYREGISTRED

   Example:

           PASS secretpasswordhere
    */
}

void	commands::ping(std::string user)
{
	/*
	    The PING message is used to test the presence of an active client at
   the other end of the connection.  A PING message is sent at regular
   intervals if no other activity detected coming from a connection.  If
   a connection fails to respond to a PING command within a set amount
   of time, that connection is closed

      Any client which receives a PING message must respond to <server1>
   (server which sent the PING message out) as quickly as possible with
   an appropriate PONG message to indicate it is still there and alive.

    Numeric Replies:

           ERR_NOORIGIN                    ERR_NOSUCHSERVER

   Examples:

   PING tolsun.oulu.fi             ; server sending a PING message to
                                   another server to indicate it is still
                                   alive.

   PING WiZ                        ; PING message being sent to nick WiZ
   */
}

void	commands::pong(std::string to, std::string from)
{
	/*
	    PONG message is a reply to ping message.  If parameter <daemon2> is
   given this message must be forwarded to given daemon.  The <daemon>
   parameter is the name of the daemon who has responded to PING message
   and generated this message.

   Numeric Replies:

           ERR_NOORIGIN                    ERR_NOSUCHSERVER

   Examples:

   PONG csd.bu.edu tolsun.oulu.fi  ; PONG message from csd.bu.edu to
   */
}

void	commands::privmsg(std::string receivers, std::string msg)
{
	/*
	 RIVMSG is used to send private messages between users.  <receiver>
   is the nickname of the receiver of the message.  <receiver> can also
   be a list of names or channels separated with commas.

   The <receiver> parameter may also me a host mask  (#mask)  or  server
   mask  ($mask).   In  both cases the server will only send the PRIVMSG
   to those who have a server or host matching the mask.  The mask  must
   have at  least  1  (one)  "."  in it and no wildcards following the
   last ".".  This requirement exists to prevent people sending messages
   to  "#*"  or "$*",  which  would  broadcast  to  all  users; from
   experience, this is abused more than used responsibly and properly.
   Wildcards are  the  '*' and  '?'   characters.   This  extension  to
   the PRIVMSG command is only available to Operators.

   Numeric Replies:

           ERR_NORECIPIENT                 ERR_NOTEXTTOSEND
           ERR_CANNOTSENDTOCHAN            ERR_NOTOPLEVEL
           ERR_WILDTOPLEVEL                ERR_TOOMANYTARGETS
           ERR_NOSUCHNICK
           RPL_AWAY

   Examples:

:Angel PRIVMSG Wiz :Hello are you receiving this message ?
                                ; Message from Angel to Wiz.

PRIVMSG Angel :yes I'm receiving it !receiving it !'u>(768u+1n) .br ;
                                Message to Angel.

PRIVMSG jto@tolsun.oulu.fi :Hello !
                                ; Message to a client on server
PRIVMSG $*.fi :Server tolsun.oulu.fi rebooting.
                                ; Message to everyone on a server which
                                has a name matching *.fi.

PRIVMSG #*.edu :NSFNet is undergoing work, expect interruptions
                                ; Message to all users who come from a
                                host which has a name matching *.edu.

	*/
}

void	commands::quit(std::string msg)
{
	/*
	A client session is ended with a quit message.  The server must close
   the connection to a client which sends a QUIT message. If a "Quit
   Message" is given, this will be sent instead of the default message,
   the nickname.

   When netsplits (disconnecting of two servers) occur, the quit message
   is composed of the names of two servers involved, separated by a
   space.  The first name is that of the server which is still connected
   and the second name is that of the server that has become
   disconnected.

   If, for some other reason, a client connection is closed without  the
   client  issuing  a  QUIT  command  (e.g.  client  dies and EOF occurs
   on socket), the server is required to fill in the quit  message  with
   some sort  of  message  reflecting the nature of the event which
   caused it to happen.

   Numeric Replies:

           None.

   Examples:

   QUIT :Gone to have lunch        ; Preferred message format.
	*/
}

void	commands::squery(std::string service, std::string text)
{
	/*
	 The SQUERY command is used similarly to PRIVMSG.  The only difference
   is that the recipient MUST be a service.  This is the only way for a
   text message to be delivered to a service.

   See PRIVMSG for more details on replies and example.

   Examples:

   SQUERY irchelp :HELP privmsg
                                   ; Message to the service with
                                   nickname irchelp.

   SQUERY dict@irc.fr :fr2en blaireau
                                   ; Message to the service with name
                                   dict@irc.fr.
    */
}

void	setname(std::string new_name);
{
	/*
	Allows a client to change the "real name" specified when 
	registering a connection.

	This command is not formally defined by an RFC, but is in use by some 
	IRC daemons. 
	Support is indicated in a RPL_ISUPPORT reply (numeric 005) 
	with the SETNAME keyword
	*/
}

void	commands::stats(std::string query)
{
	/*
	he stats message is used to query statistics of certain server.  If
   <server> parameter is omitted, only the end of stats reply is sent
   back.  The implementation of this command is highly dependent on the
   server which replies, although the server must be able to supply
   information as described by the queries below (or similar).

   A query may be given by any single letter which is only checked by
   the destination server (if given as the <server> parameter) and is
   otherwise passed on by intermediate servers, ignored and unaltered.
   The following queries are those found in the current IRC
   implementation and provide a large portion of the setup information
   for that server.  Although these may not be supported in the same way
   by other versions, all servers should be able to supply a valid reply
   to a STATS query which is consistent with the reply formats currently
   used and the purpose of the query.

   The currently supported queries are:

           c - returns a list of servers which the server may connect
               to or allow connections from;
           h - returns a list of servers which are either forced to be
               treated as leaves or allowed to act as hubs;
           i - returns a list of hosts which the server allows a client
               to connect from;
           k - returns a list of banned username/hostname combinations
               for that server;
           l - returns a list of the server's connections, showing how
			   long each connection has been established and the traffic
               over that connection in bytes and messages for each
               direction;
           m - returns a list of commands supported by the server and
               the usage count for each if the usage count is non zero;
           o - returns a list of hosts from which normal clients may
               become operators;
           y - show Y (Class) lines from server's configuration file;
           u - returns a string showing how long the server has been up.
           Numeric Replies:

           ERR_NOSUCHSERVER
           RPL_STATSCLINE                  RPL_STATSNLINE
           RPL_STATSILINE                  RPL_STATSKLINE
           RPL_STATSQLINE                  RPL_STATSLLINE
           RPL_STATSLINKINFO               RPL_STATSUPTIME
           RPL_STATSCOMMANDS               RPL_STATSOLINE
           RPL_STATSHLINE                  RPL_ENDOFSTATS

   Examples:

STATS m                         ; check the command usage for the server
                                you are connected to

:Wiz STATS c eff.org            ; request by WiZ for C/N line
                                information from server eff.org
    */
}

void	commands::time(void)
{
	/*
	 * The time message is used to query local time from the specified
   server. If the server parameter is not given, the server handling the
   command must reply to the query.

   Numeric Replies:

           ERR_NOSUCHSERVER                RPL_TIME

   Examples:

   TIME tolsun.oulu.fi             ; check the time on the server
                                   "tolson.oulu.fi"

   Angel TIME *.au                 ; user angel checking the time on a
                                   server matching "*.au"

	*/
}

void	commands::topic(std::string channel, std::string topic)
{
	/*
	 * The TOPIC message is used to change or view the topic of a channel.
   The topic for channel <channel> is returned if there is no <topic>
   given.  If the <topic> parameter is present, the topic for that
   channel will be changed, if the channel modes permit this action.

   Numeric Replies:

           ERR_NEEDMOREPARAMS              ERR_NOTONCHANNEL
           RPL_NOTOPIC                     RPL_TOPIC
           ERR_CHANOPRIVSNEEDED
    
   Examples:

   :Wiz TOPIC #test :New topic     ;User Wiz setting the topic.

   TOPIC #test :another topic      ;set the topic on #test to "another
                                   topic".

   TOPIC #test                     ; check the topic for #test.
	*/
}



void	commands::user(std::string user, std::string mode, std::string unused, 
		std::string realname);
{
	/*
	 * The USER command is used at the beginning of connection to specify
   the username, hostname and realname of a new user.

   The <mode> parameter should be a numeric, and can be used to
   automatically set user modes when registering with the server.  This
   parameter is a bitmask, with only 2 bits having any signification: if
   the bit 2 is set, the user mode 'w' will be set and if the bit 3 is
   set, the user mode 'i' will be set.  (See Section 3.1.5 "User
   Modes").

   The <realname> may contain space characters.

   Numeric Replies:

           ERR_NEEDMOREPARAMS              ERR_ALREADYREGISTRED

   Example:

   USER guest 0 * :Ronnie Reagan   ; User registering themselves with a
                                   username of "guest" and real name
                                   "Ronnie Reagan".

   USER guest 8 * :Ronnie Reagan   ; User registering themselves with a
                                   username of "guest" and real name
                                   "Ronnie Reagan", and asking to be set
                                   invisible.
	*/
}

void	commands::userhost(std::string names)
{
	/*
	 *    The USERHOST command takes a list of up to 5 nicknames, each
   separated by a space character and returns a list of information
   about each nickname that it found.  The returned list has each reply
   separated by a space.

   Numeric Replies:

           RPL_USERHOST                    ERR_NEEDMOREPARAMS

   Examples:

   USERHOST Wiz Michael Marty p    ;USERHOST request for information on
                                   nicks "Wiz", "Michael", "Marty" and "p"
    */
}

void	commands::userip(std::string nickname)
{
	/*
	 * Requests the direct IP address of the user with the 
	 * specified nickname. This command is often used to obtain the IP 
	 * of an abusive user to more effectively perform a ban. 
	 * It is unclear what, if any, privileges are required to execute 
	 * this command on a server.

	   This command is not formally defined by an RFC, but is in use 
	   by some IRC daemons. Support is indicated in a RPL_ISUPPORT 
	   reply (numeric 005) with the USERIP keyword.
	*/
}

void	commands::users(std::string server);
{
	/*
	 * The USERS command returns a list of users logged into the server in a
   similar  format  to  who(1),  rusers(1)  and finger(1).  Some people
   may disable this command on their server for security related
   reasons.   If disabled, the correct numeric must be returned to
   indicate this.

   Numeric Replies:

           ERR_NOSUCHSERVER                ERR_FILEERROR
           RPL_USERSSTART                  RPL_USERS
           RPL_NOUSERS                     RPL_ENDOFUSERS
           ERR_USERSDISABLED

   Disabled Reply:

           ERR_USERSDISABLED

   Examples:

USERS eff.org                   ; request a list of users logged in on
                                server eff.org

:John USERS tolsun.oulu.fi      ; request from John for a list of users
                                logged in on server tolsun.oulu.fi
    */
}

void	commands::vesion(std::string server)
{
	/*return server version
	 *
	 *   Numeric Replies:

           ERR_NOSUCHSERVER                RPL_VERSION

   Examples:

   :Wiz VERSION *.se               ; message from Wiz to check the version
                                   of a server matching "*.se"

   VERSION tolsun.oulu.fi          ; check the version of server
                                   "tolsun.oulu.fi".
	*/
}

void	commands::wallops(std::string msg)
{
	/*
	 *    The WALLOPS command is used to send a message to all currently
   connected users who have set the 'w' user mode for themselves.  (See
   Section 3.1.5 "User modes").
   After implementing WALLOPS as a user command it was found that it was
   often and commonly abused as a means of sending a message to a lot of
   people.  Due to this, it is RECOMMENDED that the implementation of
   WALLOPS allows and recognizes only servers as the originators of
   WALLOPS.

   Numeric Replies:

           ERR_NEEDMOREPARAMS

   Example:

   :csd.bu.edu WALLOPS :Connect '*.uiuc.edu 6667' from Joshua ; WALLOPS
                                   message from csd.bu.edu announcing a
                                   CONNECT message it received from
                                   Joshua and acted upon.
	*/
}

void	commands::who(std::string name)
{
	/*
	 *   The WHO message is used by a client to generate a query which returns
   a list of information which 'matches' the <name> parameter given by
   the client.  In the absence of the <name> parameter, all visible
   (users who aren't invisible (user mode +i) and who don't have a
   common channel with the requesting client) are listed.  The same
   result can be achieved by using a <name> of "0" or any wildcard which

   will end up matching every entry possible.

   The <name> passed to WHO is matched against users' host, server, real
   name and nickname if the channel <name> cannot be found.

   If the "o" parameter is passed only operators are returned according
   to the name mask supplied.

   Numeric Replies:

           ERR_NOSUCHSERVER
           RPL_WHOREPLY                    RPL_ENDOFWHO

   Examples:

   WHO *.fi                        ; List all users who match against
                                   "*.fi".

   WHO jto* o                      ; List all users with a match against
                                   "jto*" if they are an operator.
	*/
}

void	commands::whois(std::string server, std::string nicknames)
{
	/*
	 * This message is used to query information about particular user.  The
   server will answer this message with several numeric messages
   indicating different statuses of each user which matches the nickmask
   (if you are entitled to see them).  If no wildcard is present in the
   <nickmask>, any information about that nick which you are allowed to
   see is presented.  A comma (',') separated list of nicknames may be
   given.

   The latter version sends the query to a specific server.  It is
   useful if you want to know how long the user in question has been
   idle as only local server (ie. the server the user is directly
   connected to) knows that information, while everything else is
   globally known.

   Numeric Replies:

           ERR_NOSUCHSERVER                ERR_NONICKNAMEGIVEN
           RPL_WHOISUSER                   RPL_WHOISCHANNELS
           RPL_WHOISCHANNELS               RPL_WHOISSERVER
           RPL_AWAY                        RPL_WHOISOPERATOR
           RPL_WHOISIDLE                   ERR_NOSUCHNICK
           RPL_ENDOFWHOIS

     Examples:

   WHOIS wiz                       ; return available user information
                                   about nick WiZ

   WHOIS eff.org trillian          ; ask server eff.org for user
                                   information about trillian
		*/
}

void	commands::whowas(std::string nicknames, std::string count, std::string server);
{
	/*
	 * Whowas asks for information about a nickname which no longer exists.
   This may either be due to a nickname change or the user leaving IRC.
   In response to this query, the server searches through its nickname
   history, looking for any nicks which are lexically the same (no wild
   card matching here).  The history is searched backward, returning the
   most recent entry first.  If there are multiple entries, up to
   <count> replies will be returned (or all of them if no <count>
   parameter is given).  If a non-positive number is passed as being
   <count>, then a full search is done.

   Wildcards are allowed in the <target> parameter.

   Numeric Replies:

           ERR_NONICKNAMEGIVEN           ERR_WASNOSUCHNICK
           RPL_WHOWASUSER                RPL_WHOISSERVER
           RPL_ENDOFWHOWAS

   Examples:

   WHOWAS Wiz                      ; return all information in the nick
                                   history about nick "WiZ";

   WHOWAS Mermaid 9                ; return at most, the 9 most recent
                                   entries in the nick history for
                                   "Mermaid";

   WHOWAS Trillian 1 *.edu         ; return the most recent history for
                                   "Trillian" from the first server
                                   found to match "*.edu".
    */
}


