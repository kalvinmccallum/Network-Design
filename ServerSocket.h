/*
* Author: Kalvin McCallum
* Student ID: 01879187
* EECE 4830 - Network Design Principals, Protocols, and Applications
* The ServerSocket.h file defines the functions used for the ServerSocket.cpp file. Together these two files make up the ServerSocket class which is
* utilized in the User Datagram Protocol (UDP) program.
* Note:The following code was leveraged from Linux Gazette and was restructured to meet the needs of this Network Design project.
*/


#ifndef ServerSocket_class
#define ServerSocket_class

#include "Socket.h"


class ServerSocket : private Socket // Definition of the ServerSocket class
{
public: //Public Data Members

	ServerSocket(int port);
	ServerSocket() {};
	virtual ~ServerSocket();

	const ServerSocket& operator << (const std::string&) const;
	const ServerSocket& operator >> (std::string&) const;

	void accept(ServerSocket&);

};


#endif