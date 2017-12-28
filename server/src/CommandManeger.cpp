/*
 * CommandManeger.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: efrat
 */
//
#include "CommandManeger.h"
using namespace std;

CommandManeger::CommandManeger() {
	commandsMap["start"] = new StartCommand();
	commandsMap["list_games"] = new ListGamesCommand();
	commandsMap["join"] = new JoinCommand();
	commandsMap["play"] = new PlayCommand();
}
void CommandManeger::executeCommand( vector<string> args){
	Command* commandObj = commandsMap[args[1]];
	int socket;
	sscanf(args[0].c_str(), "%d", &socket); //take ths socket number

	commandObj->execute(socket, args);
}

CommandManeger::~CommandManeger() {
	map<string, Command*>::iterator it;
	for (it = commandsMap.begin(); it != commandsMap.end(); it++){
		delete it->second;
	}
}
