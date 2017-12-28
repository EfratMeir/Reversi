/*
 * PlayCommand.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: efrat
 */

#include <PlayCommand.h>
#include <iostream>
PlayCommand::PlayCommand() {
	// TODO Auto-generated constructor stub

}

void PlayCommand::execute(int clientSocket, vector<string> args) {



}

PlayCommand::~PlayCommand() {
	// TODO Auto-generated destructor stub
}

void PlayCommand::play(int clientSocket1, int clientSocket2) {

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
