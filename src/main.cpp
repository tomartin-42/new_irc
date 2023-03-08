/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:00:12 by tomartin          #+#    #+#             */
/*   Updated: 2023/03/08 11:54:08 by tommy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/com.hpp"
#include "../inc/ft_ircserv.hpp"
#include "../inc/orchestator.hpp"
#include "../inc/replies.hpp"
#include <signal.h>

void signal_handler(int sig) {
    std::cout << "Recibida señal " << sig << std::endl;
	orchestator::close_port(4242);
}

int	main(int argc, char **argv)
{
	std::pair<int, std::string> args = parse_arg(argc, argv);
    try 
    {
        orchestator	my_server(args.first);
		signal(SIGINT, signal_handler);
	    while(42)
	    {
		    my_server.preparation_com();
		    my_server.accept_new_connect();
		    my_server.orchestation();
		    my_server.check_status();
		    my_server.clean_up();
		    //my_server.read_or_write_all_users();
	    }
	    return(0);
    }
    catch (const com_exceptions &e) 
    {
        exit(e.get_err_code());
    }
}
