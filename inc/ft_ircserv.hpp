/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ircserv.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:13:09 by tomartin          #+#    #+#             */
/*   Updated: 2022/10/13 20:01:42 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_IRCSERV_HPP
# define _FT_IRCSERV_HPP

#include <string>

#define	HOST_NAME	"irc.teamA.com"
#define	VERSION		"1.0"
#define	MAX_CONNECTIONS	8
#define	DEFAULT_PORT	4242

//----------------Times-------------------------//

#define TIME_DONT_LOGIN	10

//----------------Send o Recv-------------------//

#define SEND 0
#define RECV 1

//---------------Types users--------------------//

#define SOCKET 'S'
#define UNKNOW 'U'
#define OPERATOR 'O'

//--------------Template functions----------------//

template<class T>
std::string itoa(T a)
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





#endif
