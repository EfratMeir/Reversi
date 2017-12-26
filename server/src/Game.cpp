/*
 * Game.cpp
 *
 *  Created on: Dec 24, 2017
 *      Author: efrat
 */

#include "Game.h"

Game::Game(char* name) {
	this->name = name;
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

char* Game::getName() {
	return this->name;
}

int Game::getNumOfplayers() {
	return this->num_of_players;
}

void Game::addPlayer(int clientSocket) {
	if (num_of_players == 0) {
		clientSocket1 = clientSocket;
		num_of_players++;
	}
	else {
		if(num_of_players == 1) {
			clientSocket2 = clientSocket;
			num_of_players++;
		}
	}

}
