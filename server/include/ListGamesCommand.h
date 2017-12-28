/*
 * ListGamesCommand.h
 *
 *  Created on: Dec 25, 2017
 *      Author: efrat
 */

#ifndef INCLUDE_LISTGAMESCOMMAND_H_
#define INCLUDE_LISTGAMESCOMMAND_H_


#include <pthread.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include "Command.h"
#include "Game.h"



using namespace std;

class ListGamesCommand: public Command{

public:
	ListGamesCommand();
	ListGamesCommand(vector<Game>& games_list);
	virtual void execute(int clientSocket, vector<string> args);
	void SendGamesToJoinList( int clientSocket, vector<Game> games_list);
	virtual ~ListGamesCommand();

private:
	vector<Game> games_list;
	pthread_mutex_t games_list_mutex;
};



#endif /* INCLUDE_LISTGAMESCOMMAND_H_ */