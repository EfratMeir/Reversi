/*
 * StartCommand.h
 *
 *  Created on: Dec 24, 2017
 *      Author: efrat
 */

#ifndef SRC_STARTCOMMAND_H_
#define SRC_STARTCOMMAND_H_

#include <vector>
#include "Game.h"
#include "Command.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>

class StartCommand: public Command {
public:
	StartCommand(char* name, vector<Game>& games_list);
	virtual void execute(int clientSocket ,vector<string> args);
	void SendGameStartsCommandMsg(int clientSocket, int msg);
	void addGame(Game g);
	virtual ~StartCommand();

private:

	char* name;
	vector<Game> games_list;
	bool doesGameExists(char* name);
	int game_added;

};

#endif /* SRC_STARTCOMMAND_H_ */


