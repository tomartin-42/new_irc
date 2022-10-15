/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_exceptions.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:09:37 by tomartin          #+#    #+#             */
/*   Updated: 2022/10/11 11:40:53 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COM_EXCEPTION_HPP_
# define _COM_EXCEPTION_HPP_

#include <exception>
#include <iostream>
#include <cstdlib>

class com_exceptions : public std::exception
{
	private:

		void	open_socket_fail();
		void	fcntl_fail();
		void	bind_fail();
		void	listen_fail();
		void	poll_fail();

	public:
		com_exceptions(const int num);
		const char*	what() const throw();

};
#endif
