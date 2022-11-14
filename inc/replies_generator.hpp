/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies_generator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:30:25 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/14 12:53:21 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REPLIES_GENERATOR_HPP_
# define _REPLIES_GENERATOR_HPP_

#include "replies.hpp"
#include "user.hpp"
#include <string>

class replies_generator : public replies
{
	public:
	std::string	admin_ok(const user& admin);	
};

#endif
