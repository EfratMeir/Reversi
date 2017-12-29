/*
 * Game.cpp
 *
 *  Created on: Dec 24, 2017
 *      Author: efrat
 */

#include <Game.h>


Game::Game(const char* name, int clientSocket1) {
	this->name = name;
	this->clientSocket1 = clientSocket1;
	this->clientSocket2 = 0;
	this->num_of_players = 1;
	this->started_playing = false;
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

const char* Game::getName() {
	return this->name;
}

int Game::getNumOfplayers() {
	return this->num_of_players;
}

void Game::addPlayer(int clientSocket) {
	if (num_of_players == 0) {
		this->clientSocket1 = clientSocket;
		this->num_of_players = 1;
	}
	else {
		if(num_of_players == 1) {
			this->clientSocket2 = clientSocket;
			this->num_of_players = 2;
		}
	}

}

bool Game::getStartedPlaying() {
	return this->started_playing;
}

int Game::getClientSocket1() {
	return this->clientSocket1;
}

int Game::getClientSocket2() {
	return this->clientSocket2;
}


void Game::setGameStarted() {
	this->started_playing = true;
}
