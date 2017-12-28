/*
 * Command.h
 *
 *  Created on: Dec 24, 2017
 *      Author: efrat
 */

#ifndef INCLUDE_COMMAND_H_
#define INCLUDE_COMMAND_H_
//#include "Server.h"

#include <iostream>
#include <vector>
#include <vector>
#include "Game.h"

using namespace std;

class Command {
public:
//	virtual void execute(vector<string> args) = 0; //maybe deleete
	virtual void execute(int clientSocket, vector<string> args) = 0;

	virtual ~Command() = 0;
protected:
	pthread_mutex_t games_list_mutex;
	vector<Game> games_list;
private:


};

#endif /* INCLUDE_COMMAND_H_ */