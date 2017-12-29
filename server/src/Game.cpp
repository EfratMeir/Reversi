/*
 * Game.cpp
 *
 *  Created on: Dec 24, 2017
 *      Author: efrat
 */

#include <Game.h>


Game::Game(string name) {
	this->name = name;
	this->clientSocket1 = 0;
	this->clientSocket2 = 0;
	this->num_of_players = 0;
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

string Game::getName() {
	return this->name;
}

int Game::getNumOfplayers() {
	return this->num_of_players;
}

void Game::addPlayer(int clientSocket) {
	if (num_of_players == 0) {
		this->clientSocket1 = clientSocket;
		this->num_of_players++;
	}
	else {
		if(num_of_players == 1) {
			this->clientSocket2 = clientSocket;
			this->num_of_players++;
		}
	}

}
