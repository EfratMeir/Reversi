/*
 * Connector.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: efrat
 */

#include "Connecter.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

using namespace std;

Connecter::Connecter() {
	cout << "connecter default construcor" << endl;
}
Connecter::Connecter(const char *serverIP, int serverPort):
		serverIP(serverIP), serverPort(serverPort), clientSocket(0) {
	cout << "Client" << endl;
}

void Connecter::connectToServer() {

	//create a socket point:
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == -1) {
		throw "Error opening socket";
	}

	//convert the ip string to a network address
	struct in_addr address;
	if (!inet_aton(serverIP, &address)) {
		throw "Can't parse IP address";
	}

	// Get a hostent structure for the given host address
	struct hostent *server;
	server = gethostbyaddr((const void *)&address, sizeof
	address, AF_INET);
	if (server == NULL) {
	throw "Host is unreachable";
	}

	//create a structure for the server address:
	struct sockaddr_in serverAddress;
	bzero((char*)&address, sizeof(address));

	serverAddress.sin_family = AF_INET;

	memcpy((char *)&serverAddress.sin_addr.s_addr, (char
	*)server->h_addr, server->h_length);

	// htons converts values between host and network byte orders
	serverAddress.sin_port = htons(serverPort);

	// Establish a connection with the TCP server
	if (connect(clientSocket, (struct sockaddr*) &serverAddress,
			sizeof(serverAddress)) == -1) {
		throw "Error connecting to server";
	}
	cout << "Connected to server" << endl;
}


//int Connecter::sendExercise(int arg1, char op, int arg2) {
//// Write the exercise arguments to the socket
//int n = write(clientSocket, &arg1, sizeof(arg1));
//if (n == -1) {
//throw "Error writing arg1 to socket";
//}
//n = write(clientSocket, &op, sizeof(op));
//if (n == -1) {
//throw "Error writing op to socket";
//}
//n = write(clientSocket, &arg2, sizeof(arg2));
//if (n == -1) {
//throw "Error writing arg2 to socket";
//}
//// Read the result from the server
//int result;
//n = read(clientSocket, &result, sizeof(result));
//if (n == -1) {
//throw "Error reading result from socket";
//}
//return result;
//}

int Connecter::sendMsg(Point p, bool player_has_no_moves) {
	// Write the chosen point p to the socket
	sendPoint(p);
	sendNoMoves(player_has_no_moves);
	return 0;
}

int Connecter::sendPoint(Point p) {
	int n = write(clientSocket, &p, sizeof(p));

	if (n == -1) {
		throw "Error writing point p to socket";
	}
	return 0;
}



int Connecter::sendNoMoves(bool player_has_no_moves) {
//	char* no_move_msg = "NoMove";
//
//	if (player_has_no_moves == true) {
//		no_move_msg = "NoMove";
//	}
//int n = write(clientSocket, &no_move_msg, sizeof(no_move_msg));

	int n = write(clientSocket, &player_has_no_moves, sizeof(player_has_no_moves));
	if (n == -1) {
		throw "Error writing player_has_no_moves to socket";
	}
	return 0;
}

Point Connecter::recivePoint() {
	// Read the point sent from the server
	Point p;
	int n = read(clientSocket, &p, sizeof(p));

	if (n == -1) {
		throw "Error reading point from socket";
	}
	return p;
}

bool Connecter::reciveNoMoves() {

	// Read the boolean sent from the server
	bool player_has_no_moves;
	int n = read(clientSocket, &player_has_no_moves, sizeof(player_has_no_moves));

	if (n == -1) {
		throw "Error reading boolean has_no_moves from socket";
	}
	return player_has_no_moves;
}
