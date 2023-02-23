/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ircserv.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:13:09 by tomartin          #+#    #+#             */
/*   Updated: 2023/02/22 19:06:34 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_IRCSERV_HPP
# define _FT_IRCSERV_HPP

#include <string>
#include <sys/socket.h>

#define	HOST_NAME	"irc.teamA.com"
#define	VERSION		"1.0"
#define	MAX_CONNECTIONS	3
#define	DEFAULT_PORT	4242

//----------------Miscelaneus--------------------//

#define YES 0
#define NO 1

//----------------Send o Recv-------------------//

#define SEND 0
#define RECV 1

//---------------Types users--------------------//

#define SOCKET 'S'
#define UNKNOW 'U'
#define OPERATOR 'O'
#define EXPULSE 'E'

//----------------Kick--------------------------//

#define OK 0
#define KICK 1

//--------------Time values config-----------------//
//--Time in seconds?-------------------------------//
#define	TIME_PING 30
#define TIME_DONT_LOGIN	10
#define TIME_LAST_MSG 200
#define TIME_POLLOUT 300

//---------------Log leve-------------------------//

#define LOG_ENABLE 1
//LOG_ENABLE 0 = disconect logs 

//--------------Template functions----------------//

template<class T>
std::string ft_itoa(T a)
{
	std::string ss = "";   //create empty string
    while(a)
    {
        int x = a%10;
        a /= 10;
        char i = '0';
        i = i + x;
        ss = i + ss;      //append new character at the front of the string!
    }
    return ss;
}

template<typename T>
class my_ptr
{
    private:
        T*  _ptr;

    public:
        my_ptr(T* ptr) { _ptr = ptr; }
        ~my_ptr() { delete _ptr; }
        T& operator * () const { return *_ptr; }
        T* operator -> () const { return _ptr; }
};

//----struct_socket_info--------------------------//
struct sock_storage: public sockaddr_storage
{
	int			fd;
	socklen_t	addr_len;
};

typedef struct sock_storage sock_info;

#endif
