/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:00:12 by tomartin          #+#    #+#             */
/*   Updated: 2023/01/28 20:13:53 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/com.hpp"
#include "../inc/server.hpp"
#include "../inc/replies.hpp"
#include <signal.h>

void signal_handler(int sig) {
    std::cout << "Recibida señal " << sig << std::endl;
	server::close_port(4242);
}

int	main(void)
{
	int	port = 4242;
    try 
    {
        server	my_server(port);
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
        exit(1);
    }
}
