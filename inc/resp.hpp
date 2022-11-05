/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resp.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:11:27 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/05 15:43:18 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RESP_HPP_
# define _RESP_HPP_

#include <string>
#include "ft_ircserv.hpp"
//#include "resp_exceptions.hpp"
#include "rpl.hpp"

class resp
{
	private:
		int	head_len;
		std::string generate_send_code(const int &code);
    
    public:
      std::string generate_msg(const int code, std::string arg1, 
			  std::string arg2, std::string arg3, std::string arg4);
        void	set_head_len(const int i);
        int		get_head_len();
};
#endif

