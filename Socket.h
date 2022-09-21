/*
* Author: Kalvin McCallum
* Student ID: 01879187
* EECE 4830 - Network Design Principals, Protocols, and Applications
* The Socket.h file defines the functions used for the Socket.cpp file. Together these two files make up the Socket class which is
* utilized in the User Datagram Protocol (UDP) program.
* Note:The following code was leveraged from Linux Gazette and was restructured to meet the needs of this Network Design project.
*/


#ifndef Socket_class
#define Socket_class


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>


const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 500;

class Socket //Socket class implementation
{
public: //Public data members
	Socket();
	virtual ~Socket();

	// These public data members initialize the server
	bool create();
	bool bind(const int port);
	bool listen() const;
	bool accept(Socket&) const;

	// These public data members initialize the client
	bool connect(const std::string host, const int port);

	// These public data members facilitate data transimission
	bool send(const std::string) const;
	int recv(std::string&) const;
	void set_non_blocking(const bool);
	bool is_valid() const { return m_sock != -1; }

private: //Private data members
	int m_sock;
	sockaddr_in m_addr;
};


#endif