/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:42:55 by tomartin          #+#    #+#             */
/*   Updated: 2022/10/30 09:36:22 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SERVER_HPP_
# define _SERVER_HPP_

#include <map>
//#include "server_exceptions.hpp"
#include "com.hpp"
#include "user.hpp"

class server : public com
{
	private:
		int					n_connections;
		std::map<int, user>	users;

		void	insert_new_user(const int fd);
		void	delete_user(const int fd);

	public:
        void    orchestation();
        void    recv_msgs(const int fd);
		void	send_msgs(const int fd);
		server(int port);
		void	accept_new_connect();
        void	read_or_write_all_users();
        void	send_msg_from_user(const int fd);
};
#endif
