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
	virtual void execute(int clientSocket ,vector<string> args, vector<Game>& games_list);
	void SendGameStartsCommandMsg(int clientSocket, int msg);
	void addGame(int client_socket, Game g, vector<Game>& games_list);
	void setName(const string name);
	virtual ~StartCommand();


private:
	string name;
	bool doesGameExists(string name, vector<Game>& games_list);
	int game_added;

};

#endif /* INCLUDE_STARTCOMMAND_H_ */


