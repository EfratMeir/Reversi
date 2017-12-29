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


Server::Server() {
	cout << "server default constructor called" << endl;
}

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
		cout << "Client connected" << endl; //from here - to change....
		//read a command
		char commandAndArgs[MAX_COMMAND_SIZE];
		int n = read(clientSocket, commandAndArgs, sizeof(commandAndArgs));
		cout << "command is "<< commandAndArgs <<endl; //deleteeeeeeeeeeeee
		if (n == -1) {
		cout << "Error reading a command" << endl;
		return;
		}

		if (n == 0) {
			cout << "Client disconnected" << endl;
			close(clientSocket);
			return;
		}

		//		convert sockent num int to string ant put it as the first arg.
		this->client_handler.handleClient(clientSocket, commandAndArgs);  //open thread
//		this->client_handler.getCommandManeger().executeCommand(command, args);


//		//tell the client he is first
//		int  first = 1, second = 2;
//		int clientSocket2 = 0;

//		while (clientSocket2 == 0){
//			//tell the first player that he is first
//			int n = write(clientSocket, &first, sizeof(first));
//			if (n == -1)
//				cout << "Error writing to socket" << endl;
//			cout << "Waiting for second player connection" << endl;
//			//wait for the second player
//			clientSocket2 = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
//		}
//		cout << "Client2 connected" << endl;
//		if (clientSocket == -1)
//			throw "Error on accept";
//		n = write(clientSocket2, &second, sizeof(second));
//			if (n == -1)
//				cout << "Error writing to socket" << endl;

//		notifyGameStarts(clientSocket, clientSocket2);
//		handleClient(clientSocket, clientSocket2);
		//close communication with the client:

//		/close(clientSocket2);

	}
//	}close(clientSocket);
}

void Server::stop() {
	close(serverSocket);
}
void Server::handleClient(int clientSocket1, int clientSocket2) {
	vector <int> clientsSockets;
	clientsSockets.push_back(clientSocket1);
	clientsSockets.push_back(clientSocket2);

	bool no_moves = false;
	int row = -1, col = -1;
	int i = 0;
	int j = 1;
	//read the first move of the first player
	int n = read(clientsSockets[i], &row, sizeof(row));
	if (n == -1) {
	cout << "Error reading row" << endl;
	return;
	}

	if (n == 0) {
		cout << "Client disconnected" << endl;
		close(clientsSockets[j]);
		return;
	}

	n = read(clientsSockets[i], &col, sizeof(col));
	if (n == -1) {
		cout << "Error reading col" << endl;
		return;
	}

	n = read(clientsSockets[i], &no_moves, sizeof(no_moves));
	if (n == -1) {
		cout << "Error reading no_moves" << endl;
		return;
	}

	while (true) {

	n = write(clientsSockets[j], &row, sizeof(row));
	if (n == -1) {
		cout << "Error writing row" << endl;
		return;
	}
	n = write(clientsSockets[j], &col, sizeof(col));
	if (n == -1) {
		cout << "Error writing col" << endl;
		return;
	}

	n = write(clientsSockets[j], &no_moves, sizeof(no_moves));
		if (n == -1) {
			cout << "Error writing no_moves" << endl;
			return;
		}
		//change "turns" of writing and reading
		i = i > 0 ? 0 : 1;
		j = j > 0 ? 0 : 1;


	int n = read(clientsSockets[i], &row, sizeof(row));
	if (n == -1) {
	cout << "Error reading row" << endl;
	return;
	}

	if (n == 0) {
		cout << "Client disconnected" << endl;
		close(clientsSockets[j]);
		return;
	}

	n = read(clientsSockets[i], &col, sizeof(col));
	if (n == -1) {
		cout << "Error reading col" << endl;
		return;
	}

	n = read(clientsSockets[i], &no_moves, sizeof(no_moves));
	if (n == -1) {
		cout << "Error reading no_moves" << endl;
		return;
	}

	}
	return;
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
