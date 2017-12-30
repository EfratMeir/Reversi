/*
 * Game.h
 *
 *  Created on: Dec 24, 2017
 *      Author: efrat
 */

#ifndef GAME_H_
#define GAME_H_
#include <string.h>
#include <string.h>
#include <iostream>

using namespace std;

class Game {

public:

	Game(string name, int clientSocket1);
	virtual ~Game();
	string getName();
	int getNumOfplayers();
	void addPlayer(int clientSocket);
	bool getStartedPlaying();
	int getClientSocket1();
	int getClientSocket2();
	void setGameStarted();

private:
	string name;
	bool started_playing;
	int num_of_players;
	int clientSocket1;
	int clientSocket2;

};

#endif /* GAME_H_ */
