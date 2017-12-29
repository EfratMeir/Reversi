/*
 * StartCommand.h
 *
 *  Created on: Dec 24, 2017
 *      Author: efrat
 */

#ifndef INCLUDE_STARTCOMMAND_H_
#define INCLUDE_STARTCOMMAND_H_

#include <vector>
#include <pthread.h>
#include <iostream>

#include <Command.h>
#include <Game.h>

using namespace std;

class StartCommand: public Command {
public:
	StartCommand();
	StartCommand(string name, vector<Game>& games_list);
//	virtual void execute(vector<string> args);
	virtual void execute(int clientSocket ,vector<string> args);
	void SendGameStartsCommandMsg(int clientSocket, int msg);
	void addGame(Game g);
	void setName(string name);
	virtual ~StartCommand();
//	char* name;

private:
	string name;
	bool doesGameExists(string name);
	int game_added;

};

#endif /* INCLUDE_STARTCOMMAND_H_ */


