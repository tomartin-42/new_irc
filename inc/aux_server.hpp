/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_server.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:52:41 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/15 18:44:01 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AUX_SERVER_HPP_
# define _AUX_SERVER_HPP_

#include <string>

struct aux_server
{
	std::string get_name() const {return("SERVER NAME PATATA");}
	std::string get_info() const {return("SERVER INFO HOLA");}
	std::string get_chanel_name() const {return("#CHANEL");}
	std::string get_chanel_topic() const {return("CHANEL TOPIC");}
};

#endif
