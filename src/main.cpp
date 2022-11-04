/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:00:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/05 15:05:42 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.hpp"
#include "server.hpp"
#include "resp.hpp"

int	main(void)
{
    try 
    {
        server	my_server(4242);

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
