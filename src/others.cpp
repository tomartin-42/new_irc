/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:26:54 by tomartin          #+#    #+#             */
/*   Updated: 2023/03/02 20:05:49 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ircserv.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <iostream>
#include <cctype>

void	check_first_arg(std::vector<std::string>& args)
{
	std::string	std_arg(*(args.begin() + 1));
	for(int i = 0 ; std_arg[i] ; i++)
		if(!std::isdigit(std_arg[i]))
		{
			std::cout << "CAN CONECT WITH OTHER SERVER O SERVER ADDRES INCORRECT" << std::endl;
			exit(1);
		}
}

//Get values to init ft_ircserv
//Parse the params
//Make a pair to irc_server port and passw
std::pair<int, std::string>	parse_arg(int argc, char **argv)
{
	std::vector<std::string>	args;
	std::pair<int, std::string>	setings(4242,"");

	if(argc == 1)
	{
		std::cout << "ft_ircserv Port:4242 Pass:OFF" << std::endl;
		return(setings);
	}
	if(argc < 3)
	{
		std::cout << "ARGUMENTS ERROR!!!" << std::endl; 
		exit(1);
	}
	if(argc > 4)
	{
		std::cout << "ARGUMENTS ERROR!!!" << std::endl; 
		exit(1);
	}
	for(int i = 0; i < argc; i++)
		args.push_back(std::string(argv[i]));
	check_first_arg(args);
	return(setings);
}
