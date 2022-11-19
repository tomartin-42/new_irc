/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_channel.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:52:41 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/19 14:05:55 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AUX_CHANNEL_HPP_
# define _AUX_CHANNEL_HPP_

#include <string>

struct aux_channel
{
	std::string get_name() const {return("CHANEL NAME PIMIENTO");}
	std::string get_info() const {return("CHANEL INFO HELLO");}
	std::string get_topic() const {return("CHANEL TOPIC");}
};

#endif
