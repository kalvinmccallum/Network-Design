/*
* Author: Kalvin McCallum
* Student ID: 01879187
* EECE 4830 - Network Design Principals, Protocols, and Applications
* The simple_client_main.cpp file utilizes the functions definitions created in the ClientSocket.h and SocketException.h files to implement the functionalities of the User Datagram Protocol (UDP) client.
* Additionally, this file implements the phase 1 requirements needed for the program to meet the desired operation of the User Datagram Protocol (UDP) server client program.
* The primary functions of this file is to send a string message to the server and then receive the echoed string from the server as well as handle exceptions that may occur.
* Note:The following code was leveraged from Linux Gazette and was restructured to meet the needs of this Network Design project.
*/


#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

int main(int argc, int argv[])
{
    try
    {

        ClientSocket client_socket("localhost", 30000); //Creates the client socket

        std::string reply; //string variable used to receive echoed message from server

        try
        {
            client_socket << "HELLO"; //string sent from the client to the server
            client_socket >> reply; //echoed message received from the server
        }
        catch (SocketException&) {}

        std::cout << "We received this response from the server:\n\"" << reply << "\"\n";; //outputting the echoed message from the server on the client terminal

    }
    catch (SocketException& e) //Exception handling implementation
    {
        std::cout << "Exception was caught:" << e.description() << "\n"; //output if exception occurs
    }

    return 0;
}