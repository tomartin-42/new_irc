/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:07:13 by tomartin          #+#    #+#             */
/*   Updated: 2023/02/04 17:43:32 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LOG_HPP_
# define _LOG_HPP_

#include <iostream>
#include <fstream>
#include "time_control.hpp"
#include "ft_ircserv.hpp"
#include <exception>
#include <sstream>

class log
{
	private:
		std::fstream	log_file;

		void			open_to_append();
	
	public:
		log();
		~log();
		void	put_msg(const std::string& to, const std::string& at, const std::string& msg);
};

#endif
