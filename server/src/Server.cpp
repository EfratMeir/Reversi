/*
 * Server.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: efrat
 */



#include <netinet/in.h>
#include <sys/socket.h>
#include <Server.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define MAX_CONNECTED_CLIENTS 20
#define MAX_COMMAND_SIZE 50

static void* handleClient(void* );

Server::Server() {
	cout << "server default constructor called" << endl;
	this->exitServer = false;
}

Server::Server(int port): port(port), serverSocket(0) {
	this->exitServer = false;
	cout << "Server" << endl;
}

void Server::start() {

	//create thread for exit command:
	threadOpening();

	//create a socket point
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1) {
		throw "Error opening socket";
	}

	//assign a local address to the socket:
	struct sockaddr_in serverAddress;
	bzero((void *)&serverAddress, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_port = htons(port);
	if (bind (serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
		throw "Error on binding";
	}

	//start listening to incoming connections:
	listen(serverSocket, MAX_CONNECTED_CLIENTS);

	//define the client socket's structures:
	struct sockaddr_in clientAddress;
	socklen_t clientAddressLen;
	while (!exitServer)  {
		cout << "Waiting for client connections..." << endl;

		//accept a new client connection:
		int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
		if (clientSocket == -1)
			throw "Error on accept";
		cout << "Client connected" << endl; //from here - to change....
		pthread_t threadID;
		pthread_create(&threadID, NULL, &handleClient, (void*)clientSocket);
	}
	return;
}
static void* handleClient(void* socket){
	long client_socket = (long)socket;
	//read a command
	char commandAndArgs[MAX_COMMAND_SIZE];
	int n = read(client_socket, commandAndArgs, sizeof(commandAndArgs));
	cout << "Received command from client: "<< commandAndArgs <<endl;
	if (n == -1) {
	cout << "Error reading a command" << endl;
	return NULL;
	}

	if (n == 0) {
		cout << "Client disconnected" << endl;
		close(client_socket);
		return NULL;
	}

	//		convert sockent num int to string ant put it as the first arg.
//	this->client_handler.handleClient(client_socket, commandAndArgs);  //open thread and handle request
	ClientHandler:: getInstance()->handleClient(client_socket, commandAndArgs);  //open thread and handle request
	return NULL;
}
void Server::stop() {
	this->exitServer = true;

	vector<pthread_t> threads = client_handler.getThreads();
	//close all the threads:
	for( unsigned int i = 0; i < threads.size(); i++) {
		pthread_cancel(threads[i]);
	}

	//close clients sockets:
	client_handler.closeAllClientsSockets();

	cout << "server is shutting down. bye bye!" << endl;
	close(serverSocket);
	exit(0);
}



void Server::notifyGameStarts(int clientSocket1, int clientSocket2) {
	bool start_game = true;
	int n = write(clientSocket1, &start_game, sizeof(start_game));
	if (n == -1) {
		cout << "Error writing start_game" << endl;
		return;
	}

	n = write(clientSocket2, &start_game, sizeof(start_game));
	if (n == -1) {
		cout << "Error writing start_game" << endl;
		return;
	}

}

void Server::threadOpening() {

	//open thread to listen to exit command:
	pthread_t new_thread;
	server_threads_vec.push_back(new_thread);
	int thread = pthread_create(&server_threads_vec[0], NULL, waitToExitCommand , (void*)this);
	if (thread) {
		cout << "ERROR: unable to create thread for waitToExitCommand" << endl;
		return;
	}
		//pthread_exit(NULL);
	return;

}

void* Server::waitToExitCommand(void* args) {
	cout << "type <exit> to close server" << endl;
	bool exitLoop = false;
	char command[MAX_COMMAND_SIZE];
	while(!exitLoop) {
		cin.getline(command, MAX_COMMAND_SIZE);

		if(strcmp(command, "exit") == 0) {
			cout << "i got exit!" << endl;
			exitLoop = true;
		}
	}
	((Server *) args)->stop();
}
void Server::setExit() {
	this->exitServer = true;
}


