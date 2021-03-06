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
	this->serverIP = 0;//not initialize
	this->serverPort = 0; //not initialize
	this->clientSocket = 0;
}
Connecter::Connecter(char *serverIP, int serverPort): //CHANGE FROM CONST CHAR* TO CHAR*
		serverIP(serverIP), serverPort(serverPort), clientSocket(0) {
	cout << "Client" << endl;

}

void Connecter::connectToServer() {

	//create a socket point:
	this->clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->clientSocket == -1) {
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

int Connecter::sendMsg(Point p, bool player_has_no_moves) {
	// Write the chosen point p to the socket
	sendPoint(p);
	sendNoMoves(player_has_no_moves);
	return 0;
}

int Connecter::sendPoint(Point p) {
	int row = p.get_row();
	int col = p.get_col();
	int n = write(clientSocket, &row, sizeof(row));
	if (n == -1) {
		throw "Error writing row to socket";
	}
	n = write(clientSocket, &col, sizeof(col));
	if (n == -1) {
		throw "Error writing col to socket";
	}
	return 0;
}



int Connecter::sendNoMoves(bool player_has_no_moves) {
	int n = write(clientSocket, &player_has_no_moves, sizeof(player_has_no_moves));
	if (n == -1) {
		throw "Error writing player_has_no_moves to socket";
	}
	return 0;
}
int Connecter::receiveNumPlayer(){

	//read the number that say if you are black player or white player.
	int color;
	int n = read(clientSocket, &color, sizeof(color));
	if (n == -1) {
		throw "Error reading point from socket";
	}

	return color;
}
Point Connecter::receivePoint() {
	// Read the point sent from the server
	int row, col;
	int n = read(clientSocket, &row, sizeof(row));
	if (n == -1) {
		throw "Error reading row from sockcet";
	}
	//check if the other client disconnect, if so - now the server will know,
	//cause the read command will return 0.
	int dummy;
	n = write(clientSocket, &dummy, sizeof(dummy));

	n = read(clientSocket, &col, sizeof(col));
	if (n == -1) {
		throw "Error reading col from socket";
	}
	Point p(row,col,'L'); //the remotePlayer setSign accordingly right after he gets the step.
	return p;
}

bool Connecter::receiveNoMoves() {

	// Read the boolean sent from the server
	bool player_has_no_moves;
	int n = read(clientSocket, &player_has_no_moves, sizeof(player_has_no_moves));

	if (n == -1) {
		throw "Error reading boolean has_no_moves from socket";
	}
	return player_has_no_moves;
}


bool Connecter::receieveStartGame() {

	// Read the boolean sent from the server
	bool start_the_game;
	int n = read(clientSocket, &start_the_game, sizeof(start_the_game));
	if (n == -1) {
		throw "Error reading boolean start_the_game from socket";
	}
	cout << "2 players are now connected, we can start!" << endl;
	return start_the_game;
}
