/*
* Author: Kalvin McCallum
* Student ID: 01879187
* EECE 4830 - Network Design Principals, Protocols, and Applications
* The Socket.cpp file utilizes the functions definitions created in the Socket.h file to implement the functionalities of the User Datagram Protocol (UDP) Socket class.
* Note:The following code was leveraged from Linux Gazette and was restructured to meet the needs of this Network Design project.
*/


#include "Socket.h"
#include "string.h"
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <iostream>


Socket::Socket() : //Implementation of a socket
    m_sock(-1)
{
    memset(&m_addr,
        0,
        sizeof(m_addr));
}

Socket::~Socket() //Implementation of closing a socket
{
    if (is_valid())
        ::close(m_sock);
}

bool Socket::create() //Implementation of creating a socket
{
    m_sock = socket(AF_INET,
        SOCK_STREAM,
        0);

    if (!is_valid())
        return false;

    // Implementation of the time wait arguement
    int on = 1;
    if (setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (const char*)&on, sizeof(on)) == -1)
        return false;

    return true;

}



bool Socket::bind(const int port) //Implementation of socket binding to ports
{
    if (!is_valid())
    {
        return false;
    }

    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = INADDR_ANY;
    m_addr.sin_port = htons(port);

    int bind_return = ::bind(m_sock,
        (struct sockaddr*)&m_addr,
        sizeof(m_addr));

    if (bind_return == -1)
    {
        return false;
    }

    return true;
}


bool Socket::listen() const //Implementation of listening for connection between sockets
{
    if (!is_valid())
    {
        return false;
    }

    int listen_return = ::listen(m_sock, MAXCONNECTIONS);

    if (listen_return == -1)
    {
        return false;
    }

    return true;
}


bool Socket::accept(Socket& new_socket) const //Implementation of acceptance between sockets
{
    int addr_length = sizeof(m_addr);
    new_socket.m_sock = ::accept(m_sock, (sockaddr*)&m_addr, (socklen_t*)&addr_length);

    if (new_socket.m_sock <= 0)
        return false;
    else
        return true;
}


bool Socket::send(const std::string s) const //Implementation of sending data between sockets
{
    int status = ::send(m_sock, s.c_str(), s.size(), MSG_NOSIGNAL);
    if (status == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}


int Socket::recv(std::string& s) const //Implementation of receiving data between sockets
{
    char buf[MAXRECV + 1];
    s = "";
    memset(buf, 0, MAXRECV + 1);
    int status = ::recv(m_sock, buf, MAXRECV, 0);

    if (status == -1)
    {
        std::cout << "status == -1   errno == " << errno << "  in Socket::recv\n";
        return 0;
    }

    else if (status == 0)
    {
        return 0;
    }

    else
    {
        s = buf;
        return status;
    }
}



bool Socket::connect(const std::string host, const int port) //Implementation of connecting sockets
{
    if (!is_valid()) return false;

    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons(port);

    int status = inet_pton(AF_INET, host.c_str(), &m_addr.sin_addr);

    if (errno == EAFNOSUPPORT) return false;

    status = ::connect(m_sock, (sockaddr*)&m_addr, sizeof(m_addr));

    if (status == 0)
        return true;
    else
        return false;
}

void Socket::set_non_blocking(const bool b) //Implementation of non blocking characteristic for sockets
{
    int opts;

    opts = fcntl(m_sock,
        F_GETFL);

    if (opts < 0)
    {
        return;
    }

    if (b)
        opts = (opts | O_NONBLOCK);
    else
        opts = (opts & ~O_NONBLOCK);

    fcntl(m_sock,
        F_SETFL, opts);

}