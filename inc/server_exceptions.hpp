/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_exceptions.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:58:57 by tomartin          #+#    #+#             */
/*   Updated: 2022/10/14 20:10:42 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SERVER_EXCEPTION_HPP_
# define _SERVER_EXCEPTION_HPP_

#include "com_exceptions.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>

class server_exceptions : public std::exception
{
	private:
		void    fail_poll_sincr();

	public:
		server_exceptions(const int num);
		const char*	what() const throw();

};
#endif
