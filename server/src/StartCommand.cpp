/*
 * StartCommand.cpp
 *
 *  Created on: Dec 24, 2017
 *      Author: efrat
 */
#include <vector>
#include <string.h>

#include <StartCommand.h>
#include <unistd.h>


StartCommand::StartCommand(){
	this->name = 0;
//	this->games_list = ;
	this->game_added = 0;
}
StartCommand::StartCommand(const char* name, vector<Game>& games_list) {
	this->name = name;
	//pthread_mutex_lock(&games_list_mutex);
	//this->games_list = games_list;
	//pthread_mutex_unlock(&games_list_mutex);
	game_added = 0;
}


void StartCommand::setName(const string name){
	const char * game_name = name.c_str();
	this->name = game_name; //PROBLEM IS HERE!! need to strcpy some how. this is only points to game_bame and than it disapperas...
															//but this->name is const. must change not to const
}
void StartCommand::execute(int clientSocket, vector<string> args, vector<Game>& games_list) {
	setName(args[2]);
	if (doesGameExists(this->name, games_list)) {
		game_added = -1; //game with this name is already exists
	}
	else {
		Game game = Game(this->name, clientSocket);
		addGame(clientSocket, game, games_list);		//ADD HERE THE ACTUALLY START GAME...?? THREAD, CONNECTION...??
		this->game_added = 1; //is the cast to int enogh???
	}

	SendGameStartsCommandMsg(clientSocket ,game_added);

}


void StartCommand::addGame(int client_socket, Game g, vector<Game>& games_list) {
	//pthread_mutex_lock(&games_list_mutex);
	/*this->*/games_list.push_back(g);
	//games_list[games_list.size()].addPlayer(client_socket);
	//pthread_mutex_unlock(&games_list_mutex);

}


StartCommand::~StartCommand() {
	// TODO Auto-generated destructor stub
}


bool StartCommand::doesGameExists(const char* name, vector<Game>& games_list) {
	bool the_same = false;
	for (unsigned int i = 0; i < /*this->*/games_list.size(); i++) {
		if (strcmp(name, /*this->*/games_list[i].getName()) == 0) {
		//	pthread_mutex_lock(&games_list_mutex);
			the_same = true;
		//	pthread_mutex_unlock(&games_list_mutex);
			return the_same;
		}
	}
	return the_same;
}

void StartCommand::SendGameStartsCommandMsg(int clientSocket, int msg) {
	int msgToClient = msg;
	// if msg == 1 --> game started
	// if msg == -1 --> a game with this name already exists
	int n = write(clientSocket, &msgToClient, sizeof(msgToClient));
	if (n == -1) {
		cout << "Error writing msg to client from start command" << endl;
		return;
	}
}
