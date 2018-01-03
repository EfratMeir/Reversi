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

#define MAX_NAME 50
using namespace std;

Connecter::Connecter() {
	this->serverIP = 0;//not initialize
	this->serverPort = 0; //not initialize
	this->clientSocket = 0;
	this->players_exist = false;

}
Connecter::Connecter(char *serverIP, int serverPort): //CHANGE FROM CONST CHAR* TO CHAR*
		serverIP(serverIP), serverPort(serverPort), clientSocket(0) {
	this->players_exist = false;
	cout << "Client" << endl;
}
void Connecter::setPlayers(Player* players_list[2]){
	this->players[0] = players_list[0];
	this->players[1] = players_list[1];
	this->players_exist = true;
}
void Connecter::connectToServer() {

	//create a socket point:
	this->clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->clientSocket == -1) {
		//throw "Error opening socket";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
	}

	//convert the ip string to a network address
	struct in_addr address;
	if (!inet_aton(serverIP, &address)) {
		//throw "Can't parse IP address";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
	}
	// Get a hostent structure for the given host address
	struct hostent *server;
	server = gethostbyaddr((const void *)&address, sizeof
	address, AF_INET);
	if (server == NULL) {
		//throw "Host is unreachable";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
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
		//throw "Error connecting to server";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
	}

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
	if (n == -1 || n == 0) {
		//throw "Error writing row to socket";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
	}
	n = write(clientSocket, &col, sizeof(col));
	if (n == -1 || n == 0) {
		//throw "Error writing col to socket";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
	}
	return 0;
}

int Connecter::sendNoMoves(bool player_has_no_moves) {
	int n = write(clientSocket, &player_has_no_moves, sizeof(player_has_no_moves));
	if (n == -1 || n == 0) {
		//throw "Error writing player_has_no_moves to socket";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
	}
	return 0;
}
int Connecter::receiveNumPlayer(){

	//read the number that say if you are black player or white player.
	int color;
	int n = read(clientSocket, &color, sizeof(color));
	if (n == -1 || n == 0) {
		//throw "Error reading point from socket";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
	}

	return color;
}
Point Connecter::receivePoint() {
	// Read the point sent from the server
	int row, col;
	int n = read(clientSocket, &row, sizeof(row));
	if (n == -1 || n == 0) {
		//throw "Error reading row from sockcet";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
	}


	//check if the other client disconnect, if so - now the server will know,
	//cause the read command will return 0.

	n = read(clientSocket, &col, sizeof(col));
	if (n == -1 || n == 0) {
		//throw "Error reading col from socket";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
	}
	Point p(row,col,'L'); //the remotePlayer setSign accordingly right after he gets the step.
	return p;
}

bool Connecter::receiveNoMoves() {

	// Read the boolean sent from the server
	bool player_has_no_moves;
	int n = read(clientSocket, &player_has_no_moves, sizeof(player_has_no_moves));

	if (n == -1 || n == 0) {
		//throw "Error reading boolean has_no_moves from socket";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
	}
	return player_has_no_moves;
}


bool Connecter::receieveStartGame() {

	// Read the boolean sent from the server
	bool start_the_game;

	int n = read(clientSocket, &start_the_game, sizeof(start_the_game));
	if (n == -1 || n == 0) {
		//throw "Error reading boolean start_the_game from socket";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
	}


	return start_the_game;
}

void Connecter::receieveGamesTojoinList(vector<string>& games_to_join_list) {
	int num;

	int n = read(clientSocket, &num, sizeof(num));
	if (n == -1 || n == 0) {
		//throw "Error reading num of games to join from socket";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
	}
	cout << "num of games in list: " << num << endl;
	char name[MAX_NAME];

	for (int i = 0; i < num; i++) {
		int n = read(clientSocket, &name, sizeof(name)); //WORKS THIS WAY? OR ITS GO OVER THE PREVIOUS NAME? CHECK.
		if (n == -1 || n == 0) {
			//throw "Error reading a game to join name from socket";
			cout << "server is disconnected." << endl;
			deletePlayers();
			close(this->clientSocket);
			exit(0);
		}
		string stringName = string(name);

		games_to_join_list.push_back(stringName);
	}
}
bool Connecter::receiveJoinValid(){
	bool join_valid;
	int n = read(clientSocket, &join_valid, sizeof(join_valid));
	if (n == -1 || n == 0) {
		//throw "Error reading the start command msg from socket";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
	}
	return join_valid;
}
int Connecter::receiveStartCommandMsg() {
	int game_started;

	int n = read(clientSocket, &game_started, sizeof(game_started));
	if (n == -1 || n == 0) {
		//throw "Error reading the start command msg from socket";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
	}
	return game_started;

}
//send the command to the server
int Connecter::sendCommand(char command[MAX_COMMAND_SIZE]){
	int n = write(clientSocket, command, MAX_COMMAND_SIZE);
	if (n == -1 || n == 0) {
		//throw "Error writing command to socket";
		cout << "server is disconnected." << endl;
		deletePlayers();
		close(this->clientSocket);
		exit(0);
	}
	return 0;
}
void Connecter::deletePlayers(){
	if (players_exist){
		delete this->players[0];
		delete this->players[1];
	}

}
