# 
# Author: Kalvin McCallum
# Student ID: 01879187
# EECE 4830 - Network Design Principals, Protocols, and Applications
# Makefile utilized for the Network Design socket programming project phase 1
# The Makefile contains a list of Linux commands that are used to build the software program. The purpose of this file is to simplify and automate the setup process of the program.
# Note:The following code was leveraged from Linux Gazette and was restructured to meet the needs of this Network Design project.
# 

simple_server_objects = ServerSocket.o Socket.o simple_server_main.o
simple_client_objects = ClientSocket.o Socket.o simple_client_main.o

# setting up the main files of the User Datagram Protocol client server program
all : simple_server simple_client

# Setting up the main server to execute as a c++ file
simple_server: $(simple_server_objects)
	g++ -o simple_server $(simple_server_objects)

# Setting up the main client to execute as a c++ file
simple_client: $(simple_client_objects)
	g++ -o simple_client $(simple_client_objects)

# List of files needed to execute the main server and client files
Socket: Socket.cpp
ServerSocket: ServerSocket.cpp
ClientSocket: ClientSocket.cpp
simple_server_main: simple_server_main.cpp
simple_client_main: simple_client_main.cpp


clean:
	rm -f *.o simple_server simple_client