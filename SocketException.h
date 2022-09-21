/*
* Author: Kalvin McCallum
* Student ID: 01879187
* EECE 4830 - Network Design Principals, Protocols, and Applications
* The SocketException.h file defines the functions used to handle any exceptions experienced will running the User DataGram Protocol client server program. 
* This file helps ensure that when an exception occurs the program does not simply terminate. Rather it will allow the program to continue running until the desired functions occur.
* Note:The following code was leveraged from Linux Gazette and was restructured to meet the needs of this Network Design project.
*/


#ifndef SocketException_class
#define SocketException_class

#include <string>

class SocketException //Defines the theSocketException class
{
public://Public data members used for the exception class
	SocketException(std::string s) : m_s(s) {};
	~SocketException() {};
	std::string description() { return m_s; }

private://Private data members used for the exception class
	std::string m_s;

};

#endif