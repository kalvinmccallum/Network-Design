/* 
* Author: Kalvin McCallum
* Student ID: 01879187
* EECE 4830 - Network Design Principals, Protocols, and Applications
* The ClientSocket.cpp file utilizes the functions definitions created in the ClientSocket.h file to implement the functionalities of the User Datagram Protocol (UDP) ClientSocket class. 
* Note:The following code was leveraged from Linux Gazette and was restructured to meet the needs of this Network Design project.
*/ 

#include "ClientSocket.h"
#include "SocketException.h"


ClientSocket::ClientSocket(std::string host, int port) //ClientSocket Class Implementation
{
    if (!Socket::create())
    {
        throw SocketException("Could not create client socket."); //if the client socket cannot be created this message will be printed
    }

    if (!Socket::connect(host, port))
    {
        throw SocketException("Could not bind to port."); //if the client socket cannot be connected to the port this message will be printed
    }

}


const ClientSocket& ClientSocket::operator << (const std::string& s) const //overloaded << operator implementation
{
    if (!Socket::send(s))
    {
        throw SocketException("Could not write to socket."); //if data cannot be sent by the socket this message will be printed 
    }

    return *this;

}


const ClientSocket& ClientSocket::operator >> (std::string& s) const //overloaded >> operator implementation
{
    if (!Socket::recv(s))
    {
        throw SocketException("Could not read from socket."); //if the socket can not read data this message will be printed
    }

    return *this;
}