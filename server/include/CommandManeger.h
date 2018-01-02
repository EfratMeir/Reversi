/*
 * CommandManeger.h
 *
 *  Created on: Dec 26, 2017
 *      Author: efrat
 */

#ifndef INCLUDE_COMMANDMANEGER_H_
#define INCLUDE_COMMANDMANEGER_H_

#include <string.h>
#include <vector>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <map>
#include <stdio.h>
#include <unistd.h>
#include "StartCommand.h"
#include "ListGamesCommand.h"
#include "JoinCommand.h"

#include "Command.h"
using namespace std;


class CommandManeger {
public:
	CommandManeger();
	CommandManeger(vector<Game>& static_games_list);
	void executeCommand(vector<string> args, vector<Game>& games_list);
	virtual ~CommandManeger();

private:
	map <string, Command*> commandsMap;
	vector<Game> static_games_list;
	static pthread_mutex_t games_list_mutex;


};


#endif /* INCLUDE_COMMANDMANEGER_H_ */
