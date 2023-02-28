/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:26:54 by tomartin          #+#    #+#             */
/*   Updated: 2023/02/28 20:02:54 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ircserv.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <iostream>

void	check_parser(std::vector<std::string>& args)
{
	std::string	std_arg;
}

std::string	parse_arg(int argc, char **argv)
{
	std::vector<std::string> args;

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
	{
		args.push_back(std::string(argv[i]));
	}
	
	return std::string("PARSING\n");
		
}
