/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resp_exceptions.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:41:20 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/05 13:43:09 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REP_EXCEPTION_HPP_
# define _REP_EXCEPTION_HPP_

#include <exception>
#include <iostream>
#include <cstdlib>

class resp_exceptions : public std::exception
{
	private:
		void    fail_generate_msg();

	public:
		resp_exceptions(const int num);
		const char*	what() const throw();
};
#endif
