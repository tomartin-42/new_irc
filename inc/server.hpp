/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:42:55 by tomartin          #+#    #+#             */
/*   Updated: 2022/10/18 21:06:10 by tomartin         ###   ########.fr       */
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
		server(int port);
		void	accept_new_connect();
        void	read_or_write_all_users();
        void	send_all(std::string msg);
};
#endif
