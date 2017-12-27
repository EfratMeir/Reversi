/*
 * Game.h
 *
 *  Created on: Dec 24, 2017
 *      Author: efrat
 */

#ifndef GAME_H_
#define GAME_H_
#include <string.h>

using namespace std;

class Game {

public:
	Game(char* name);
	virtual ~Game();
	char* getName();
	int getNumOfplayers();
	void addPlayer(int clientSocket);
private:
	char* name;
	int num_of_players;
	int clientSocket1;
	int clientSocket2;

};

#endif /* GAME_H_ */
