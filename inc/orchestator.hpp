/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:42:55 by tomartin          #+#    #+#             */
/*   Updated: 2023/03/05 18:10:47 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ORCHESTATOR_HPP_
# define _ORCHESTATOR_HPP_

#include <map>
#include "orchestator_exceptions.hpp"
#include "com.hpp"
#include "user.hpp"
#include "../inc/commands.hpp"

class orchestator : public com, public commands
{
	private:
		std::string name;
		void		insert_new_user(const int fd);
		void		delete_user(const int fd);
		void		delete_users_from_list(std::vector<int>& list);

	public:
		std::map<int, user>	users;

		orchestator(int port);
        void	orchestation();
        void	recv_msgs(const int fd);
		void	send_msgs(const int fd);
		void	accept_new_connect();
        void	read_or_write_all_users();
		void	recv_msg_from_user(const int fd);
		void	send_msg_from_user(const int fd);
		void	check_status();
};
#endif
