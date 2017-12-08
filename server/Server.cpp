/*
 * Server.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: efrat
 */

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>


using namespace std;
#define MAX_CONNECTED_CLIENTS 2

Server::Server(int port): port(port), serverSocket(0) {
	cout << "Server" << endl;
}

void Server::start() {
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

	while (true)  {
		cout << "Waiting for client connections..." << endl;

		//accept a new client connection:
		int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
		if (clientSocket == -1)
			throw "Error on accept";
		cout << "Client connected" << endl;
		//tell the client he is first
		int  first = 1, second = 2;
		int clientSocket2 = 0;

		while (clientSocket2 == 0){
			//tell the first player that he is first
			int n = write(clientSocket, &first, sizeof(first));
			if (n == -1)
				cout << "Error writing to socket" << endl;
			cout << "Waiting for second player connection" << endl;
			//wait for the second player
			clientSocket2 = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
		}
		cout << "Client2 connected" << endl;
		if (clientSocket == -1)
			throw "Error on accept";
		int n = write(clientSocket2, &second, sizeof(second));
			if (n == -1)
				cout << "Error writing to socket" << endl;
		handleClient(clientSocket, clientSocket2);
		//close communication with the client:
		close(clientSocket);
		close(clientSocket2);
	}

}

void Server::stop() {
	close(serverSocket);
}


void Server::handleClient(int clientSocket1, int clientSocket2) {
	int arg1, arg2;
	char comma;
	//read the first move from the first player and write to the second
	int n = read(clientSocket1, &arg1, sizeof(arg1));
	if (n == -1) {
	cout << "Error reading arg1" << endl;
	return;
	}
	if (n == 0) {
		cout << "Client disconnected" << endl;
		return;
	}
	n = read(clientSocket1, &comma, sizeof(comma));
	if (n == -1) {
		cout << "Error reading operator" << endl;
		return;
	}
	n = read(clientSocket1, &arg2, sizeof(arg2));
	if (n == -1) {
		cout << "Error reading arg2" << endl;
		return;
	}
	n = write(clientSocket2, &arg1, sizeof(arg1));
	if (n == -1) {
		cout << "Error writing arg1" << endl;
		return;
	}
	n = write(clientSocket2, &comma, sizeof(comma));
	if (n == -1) {
		cout << "Error writing " << endl;
		return;
	}
	n = write(clientSocket2, &arg2, sizeof(arg2));
	if (n == -1) {
		cout << "Error reading arg2" << endl;
		return;
	}
	return;
}


