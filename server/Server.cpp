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
	char op;
	//write to each client 1 or 2 Respectively

	int first_player = 1;
	int second_player = 2;
	writeColorNum(first_player, second_player, clientSocket1, clientSocket2);

	//CHANGE TO HANDLE ACORDING TO THE GAME
	int n = read(clientSocket1, &arg1, sizeof(arg1));

	if (n == -1) {
	cout << "Error reading arg1" << endl;
	return;
	}
	if (n == 0) {
		cout << "Client disconnected" << endl;
		return;
	}
	n = read(clientSocket1, &op, sizeof(op));
	if (n == -1) {
		cout << "Error reading operator" << endl;
		return;
	}
	n = read(clientSocket1, &arg2, sizeof(arg2));
	if (n == -1) {
		cout << "Error reading arg2" << endl;
		return;
	}
	cout << "Got exercise: " << arg1 << op << arg2 << endl;
//	int result = calc(arg1, op, arg2);

	// Write the result back to the client
//	n = write(clientSocket1, &result, sizeof(result));
//	if (n == -1) {
//	cout << "Error writing to socket" << endl;
//	return;
//	}
}
void Server:: writeColorNum(int first_player, int second_player,
		int clientSocket1, int clientSocket2 ){
	int n = write(clientSocket1,&first_player, sizeof(first_player));
		if (n == -1)
			cout << "Error writing to socket" << endl;
		n = write(clientSocket2, &second_player, sizeof(second_player));
		if (n == -1)
			cout << "Error writing to socket" << endl;
}
//int Server::calc(int arg1, const char op, int arg2) const {
//
//	switch (op) {
//	case '+':
//	return arg1 + arg2;
//	case '-':
//	return arg1 - arg2;
//	case '*':
//	return arg1 * arg2;
//	case '/':
//	return arg1 / arg2;
//	default:
//	cout << "Invalid operator" << endl;
//	return 0;
//	}
//
//}

