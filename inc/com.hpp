/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:22:56 by tomartin          #+#    #+#             */
/*   Updated: 2022/10/15 19:12:54 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COM_HPP_
# define _COM_HPP_

#include <sys/socket.h>
#include <string>
#include <fcntl.h>
#include <vector>
#include <netinet/in.h>
#include <poll.h>
#include <unistd.h>
#include <poll.h>
#include "com_exceptions.hpp"
#include "ft_ircserv.hpp"

class com
{
    private:
        const int				port;
        struct sockaddr_in		data_socket;
        int						fd_socket;
		std::vector<pollfd>		poll_list;

		void	open_socket();
        void	set_data_socket(const int port);
        void    reset_to_zero_revents();
    	void	close_connection(const int fd);
    	void	insert_in_poll_list(const int fd);
    	void	delete_in_poll_list(const int fd);

    public:
    	com(const int);
		~com();	
    	void	socket_lisent();
    	int		accept_connection_in_socket();
        int		preparation_com();
    	int		disconnect_user(const int fd, std::string reason);
    	int		get_port() const;
    	int		get_fd_socket() const;
		int		set_value_poll_list(const int fd, const short event);

		void	print_all_pollfd();
	};
#endif
