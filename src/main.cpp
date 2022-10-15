/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:00:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/10/15 19:01:09 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.hpp"
#include "server.hpp"

int	main(void)
{
	server	my_server(4242);

	while(42)
	{
		my_server.sincronizate_polls();
		std::cout << my_server.preparation_com() << std::endl;
		my_server.accept_new_connect();
		my_server.sincronizate_polls();
	}
	return(0);
}
