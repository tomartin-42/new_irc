#include "../inc/tommy_commands.hpp"

void	command_ping(user& user, replies_generator& replies, aux_server& server)
{
	int	parse = 0;

	if(parse == 0)
	{
		user.msg_out.direct_push(std::string(server.get_name() + ":" + " PONG: "
					+ server.get_name() + " "  + user.get_host_name() + "\r\n"));
	}
	else if(parse == 1)
	{
		user.msg_out.add_msg(replies.ping_noorigin());
	}
	else if(parse == 2)
	{
		user.msg_out.add_msg(replies.ping_nosuchserver(server));
	}
}

void	command_pong(user& user, replies_generator& replies, aux_server& server)
{
	int	parse = 0;

	if(parse == 0)
	{
		user.user_times.reset_t_ping();
	}
	else if(parse == 1)
	{
		user.msg_out.add_msg(replies.ping_noorigin());
	}
	else if(parse == 2)
	{
		user.msg_out.add_msg(replies.ping_nosuchserver(server));
	}
}
		
