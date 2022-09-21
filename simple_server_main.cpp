/*
* Author: Kalvin McCallum
* Student ID: 01879187
* EECE 4830 - Network Design Principals, Protocols, and Applications
* The simple_server_main.cpp file utilizes the functions definitions created in the ServerSocket.h and SocketException.h files to implement the functionalities of the User Datagram Protocol (UDP) server.
* Additionally, this file implements the phase 1 requirements needed for the program to meet the desired operation of the User Datagram Protocol (UDP) server client program.
* The primary functions of this file is to receive a string message from the client and then echo the message back to the client as well as handle exceptions that may occur.
* Note:The following code was leveraged from Linux Gazette and was restructured to meet the needs of this Network Design project.
*/


#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>

int main(int argc, int argv[])
{
	std::cout << "I am the server and I am ready to receive messages from the client...\n"; //Output indicating that the server is running and ready to receive messages from the client

	try
	{
		ServerSocket server(30000); // Creates the server socket

		while (true)
		{
			ServerSocket new_sock; //New object created in the ServerSocket class. This object will be used to receive and echo the string messages from the client
			server.accept(new_sock); //Accepts the message sent from the client

			try
			{
				while (true)
				{
					std::string data; //String variable to store string message sent from client
					new_sock >> data; //Stores string message received from client
					new_sock << data; //Echos the received message back to the client
				}
			}
			catch (SocketException&) {}

		}
	}
	catch (SocketException& e) //Exception implementation
	{
		std::cout << "Exception was caught:" << e.description() << "\nExiting.\n"; //If an exception occurs this message will be printed to the terminal
	}

	return 0;
}