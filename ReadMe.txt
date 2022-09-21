Title & Authors: 

Network Design Project Phase One: User Datagram Protocol Client and Server
Kalvin McCallum

Environment:

Operating System: Linux or Windows (I used Linux but I have included instructions for a windows user too)
Programming Languages: C++
Programming Language Version: C++20

List of Files Submitted:

1. Makefile
   The Makefile contains a list of Linux commands that are used to build the software program. The purpose of this file is to simplify and automate the setup process of the program.

2. Socket.h & Socket.cpp
   The purpose of these files is to implement the raw socket API calls. The Socket.h file contains function definitions used in the Socket.cpp file. The Socket.cpp file is the main socket file used to 
   implement the socket class.

3. SocketException.h
   The purpose of this file is to implement a mechanism that can handle exceptions when running the UDP server and client. This header file will prevent the UDP server and client program from terminating
   when an exception occurs.

4. simple_server_main.cpp
   The purpose of this file is to facilitate and implement the main functionalities and executables of the UDP server. This is the main server file of the UDP server client program.

5. ServerSocket.h & ServerSocket.cpp
   The purpose of these files is to implement the server socket API calls. The ServerSocket.h file contains function definitions used in the ServerSocket.cpp file. The ServerSocket.cpp file is the main
   server socket file used to implement the ServerSocket class.

6. simple_client_main.cpp
   The purpose of this file is to facilitate and implement the main functionalities and executables of the UDP client. This is the main client file of the UDP server client program.

7. ClientSocket.h & ClientSocket.cpp
   The purpose of these files is to implement the client socket API calls. The ClientSocket.h file contains function definitions used in the ClientSocket.cpp file. The ClientSocket.cpp file is the main
   client socket file used to implement the ClientSocket class.

Instructions:

1. Open a linux terminal. If using a windows or mac machine you can use a virtual machine such as Oracle VM VirtualBox or Cygwin.

2. Create a new directory. This can be done using the Mkdir command line followed by the desired nomenclature of your new directory.
   Note: This will write a new directory to the operating system on your machine. If you would prefer to have the new directory placed on your desktop then navigate to your desktop before 
   creating the new directory. This can be done by typing "cd Desktop" into the terminal before executing this step.

3. Once the new directory has been made, add the provided files to the new directory. This can be done by natigating to the directory on your machine and copying and pasting the files into the directory.

4. Enter the "Make" command into the terminal to build the software program and link the files you just placed in the new directory.

5. Once the make file has successfully compiled, enter the "clear" command in the terminal.

6. Open a second terminal (you will now have two terminals open).

7. Navigate to your new directory in both terminals. This can be done by entering "cd NameofYourNewDirectory" in each terminal.

8. In one of the two terminals enter "./simple_server". This will run the UDP server. 

9. In the other terminal enter "./simple_client". This will run the UDP client.

10. The client will then send a string "HELLO" to the server and the server will echo the string back to the client and print the message on the client terminal. 
