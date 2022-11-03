/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resp.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:51:30 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/04 12:21:26 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resp.hpp"

std::string	resp::generate_send_code(const int &code)
{
	std::string	true_code;

	true_code = itoa(code);
    if(code < 100)
        true_code.insert(0,'0');
    if(code < 10)
        true_code.insert(0,'0');
    return true_code;
}

std::string resp::generate_msg(const int code, std::string arg1, std::string arg2, std::string arg3, std::string arg4);
{
    std::string send_code(generate_send_code(code));


}
void	resp::set_head_len(const int i)
{
	this->head_len = i;
}

int		resp::get_head_len()
{
	return this->head_len;
}
