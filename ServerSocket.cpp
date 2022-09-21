/*
* Author: Kalvin McCallum
* Student ID: 01879187
* EECE 4830 - Network Design Principals, Protocols, and Applications
* The ServerSocket.cpp file utilizes the functions definitions created in the SeverSocket.h file to implement the functionalities of the User Datagram Protocol (UDP) ServerSocket class.
* Note:The following code was leveraged from Linux Gazette and was restructured to meet the needs of this Network Design project.
*/


#include "ServerSocket.h"
#include "SocketException.h"


ServerSocket::ServerSocket(int port) //ServerSocket class implementation
{
    if (!Socket::create())
    {
        throw SocketException("Could not create server socket."); //if the server socket cannot be created this message will be printed
    }

    if (!Socket::bind(port))
    {
        throw SocketException("Could not bind to port."); //if the server socket cannot be connected to the port this message will be printed
    }

    if (!Socket::listen())
    {
        throw SocketException("Could not listen to socket."); //if the server socket cannot listen this message will be printed
    }

}

ServerSocket::~ServerSocket()
{
}


const ServerSocket& ServerSocket::operator << (const std::string& s) const //overloaded << operator implementation
{
    if (!Socket::send(s))
    {
        throw SocketException("Could not write to socket."); //if data cannot be sent by the socket this message will be printed 
    }

    return *this;

}


const ServerSocket& ServerSocket::operator >> (std::string& s) const //overloaded >> operator implementation
{
    if (!Socket::recv(s))
    {
        throw SocketException("Could not read from socket."); //if the socket can not read data this message will be printed
    }

    return *this;
}

void ServerSocket::accept(ServerSocket& sock) //ServerSocket class acception implementation
{
    if (!Socket::accept(sock))
    {
        throw SocketException("Could not accept socket."); //if the socket can not be accepted this message will be printed
    }
}