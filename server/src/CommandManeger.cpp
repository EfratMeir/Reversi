/*
 * CommandManeger.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: efrat
 */
//
#include "CommandManeger.h"
using namespace std;

pthread_mutex_t CommandManeger::games_list_mutex;

CommandManeger::CommandManeger() {
	commandsMap["start"] = new StartCommand();
	commandsMap["list_games"] = new ListGamesCommand();
	commandsMap["join"] = new JoinCommand();
}
CommandManeger::CommandManeger(vector<Game>& games_list) {
	pthread_mutex_lock(&games_list_mutex);
	static_games_list = games_list;
	pthread_mutex_unlock(&games_list_mutex);
	commandsMap["start"] = new StartCommand();
	commandsMap["list_games"] = new ListGamesCommand();
	commandsMap["join"] = new JoinCommand();
}
void CommandManeger::executeCommand(vector<string> args, vector<Game>& games_list){
	Command* commandObj = commandsMap[args[1]];
	int socket;
	sscanf(args[0].c_str(), "%d", &socket); //take the socket number
	commandObj->execute(socket, args, games_list);
}

CommandManeger::~CommandManeger() {
	map<string, Command*>::iterator it;
	for (it = commandsMap.begin(); it != commandsMap.end(); it++){
		delete it->second;
	}
}
