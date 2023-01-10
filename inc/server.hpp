/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:42:55 by tomartin          #+#    #+#             */
/*   Updated: 2023/01/10 19:09:04 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SERVER_HPP_
# define _SERVER_HPP_

#include <map>
#include "server_exceptions.hpp"
#include "com.hpp"
#include "user.hpp"

class server : public com
{
	private:

		std::string a;
		void		insert_new_user(const int fd);
		void		delete_user(const int fd);
		void		delete_users_from_list(std::vector<int>& list);

	public:
		std::map<int, user>	users;

		server(int port);
        void		orchestation();
        void		recv_msgs(const int fd);
		void		send_msgs(const int fd);
		void		accept_new_connect();
        void		read_or_write_all_users();
		void		recv_msg_from_user(const int fd);
		std::string get_msg_of_the_day();
   //   void	send_msg_from_user(const int fd);
};
#endif
