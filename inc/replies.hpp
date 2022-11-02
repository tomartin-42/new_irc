/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:04:42 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/02 22:12:30 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REPLIES_HPP_
# define _REPLIES_HPP_

//This is the list of numeric replies difines

//The server sends Replies 001 to 004 to a user upon successful registration
# define RPL_WELLCOME "001 "
# define RPL_WELLCOME_STR1 "Welcome to the Internet Relay Network "

# define RPL_YOURHOST "002 "
# define RPL_YOURHOST_STR1 "Your host is "
# define RPL_YOURHOST_STR2 ", running version "

# define RPL_CREATED "003 "
# define RPL_CREATED_STR1 "This server was created "

# define RPL_MYINFO "004 "


