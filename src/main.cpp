/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:00:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/10/18 21:10:47 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.hpp"
#include "server.hpp"

int	main(void)
{
	server	my_server(666);

	while(42)
	{
		my_server.preparation_com();
		my_server.accept_new_connect();
		my_server.read_or_write_all_users();
	}
	return(0);
}
