/*
 * StartCommand.cpp
 *
 *  Created on: Dec 24, 2017
 *      Author: efrat
 */
#include <vector>
#include <string.h>
#include <cstring>
#include <StartCommand.h>
#include <unistd.h>


StartCommand::StartCommand(){
	this->game_added = 0;
}
StartCommand::StartCommand( string name, vector<Game>& games_list) {
	this->name = name;
	game_added = 0;
}


void StartCommand::execute(int clientSocket, vector<string> args, vector<Game>& games_list){
	this->name = args[2];
	if (doesGameExists(this->name, games_list)) {
		game_added = -1; //game with this name is already exists
	}
	else {
		Game game = Game(this->name, clientSocket);
		addGame(clientSocket, game, games_list);
		this->game_added = 1;
	}
	SendGameStartsCommandMsg(clientSocket ,game_added);

	if(game_added == -1){ //maybe mistake. if there is already a game name like this,
		//the client will insert a new command with a new socket. so close this socket,!
		close(clientSocket);
	}
}


void StartCommand::addGame(int client_socket, Game g, vector<Game>& games_list) {

	//critical section
	pthread_mutex_lock(&games_list_mutex);
	games_list.push_back(g);
	pthread_mutex_unlock(&games_list_mutex);

}


StartCommand::~StartCommand() {
	// TODO Auto-generated destructor stub
}



bool StartCommand::doesGameExists(string name, vector<Game>& games_list) {
	bool the_same = false;
	for (unsigned int i = 0; i < games_list.size(); i++) {
		const char* this_game_name = name.c_str();

		//critical section
		pthread_mutex_lock(&games_list_mutex);
		const char* game_in_list = games_list[i].getName().c_str();
		pthread_mutex_unlock(&games_list_mutex);

		if (strcmp(this_game_name, game_in_list) == 0) {
			the_same = true;
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
