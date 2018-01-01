/*
 * PlayCommand.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: efrat
 */

#include "Play.h"
#include <pthread.h>
Play::Play() {
	// TODO Auto-generated constructor stub

}

//void Play::execute(int clientSocket, vector<string> args, vector<Game>& games_list) {
//	int client_socket1, client_socket2;
//	//find the game in the list, take the sockets and start play!
//	for (unsigned int i = 0; i < games_list.size(); i++) {
////		const char* this_game = args[2].c_str();
////		const char* game_in_list = games_list[i].getName().c_str();
//		if (clientSocket == games_list[i].getClientSocket1()) {
//			client_socket1 = games_list[i].getClientSocket1();
//			client_socket2 = games_list[i].getClientSocket2();
//		}
//	}
//	play(client_socket1, client_socket2);
//}

Play::~Play() {
	// TODO Auto-generated destructor stub
	}

void Play::play(int clientSocket1, int clientSocket2) {
	cout <<"im playinggggggg" << endl;
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
		pthread_exit(NULL);
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
		if(no_moves){
			return; //maybe close sockets????
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
		pthread_exit(NULL);
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
