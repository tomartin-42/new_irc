/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:00:12 by tomartin          #+#    #+#             */
/*   Updated: 2023/02/28 19:46:30 by tomartin         ###   ########.fr       */
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
	parse_arg(argc, argv);
	int	port = 4242;

    try 
    {
        orchestator	my_server(port);
		signal(SIGINT, signal_handler);
	    while(42)
	    {
		    my_server.preparation_com();
		    my_server.accept_new_connect();
		    my_server.orchestation();
		    //my_server.read_or_write_all_users();
	    }
	    return(0);
    }
    catch (const com_exceptions &e) 
    {
        exit(e.get_err_code());
    }
}
