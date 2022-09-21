/*
* Author: Kalvin McCallum
* Student ID: 01879187
* EECE 4830 - Network Design Principals, Protocols, and Applications
* The ClientSocket.h file defines the functions used for the ClientSocket.cpp file. Together these two files make up the ClientSocket class which is 
* utilized in the User Datagram Protocol (UDP) program.
* Note:The following code was leveraged from Linux Gazette and was restructured to meet the needs of this Network Design project.
*/


#ifndef ClientSocket_class
#define ClientSocket_class

#include "Socket.h"


class ClientSocket : private Socket //Definition of the ClientSocket class
{
public: //Public Data Members

	ClientSocket(std::string host, int port);
	virtual ~ClientSocket() {};

	const ClientSocket& operator << (const std::string&) const;
	const ClientSocket& operator >> (std::string&) const;

};


#endif