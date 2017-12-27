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



StartCommand::StartCommand(char* name, vector<Game>& games_list) {
	this->name = name;
	pthread_mutex_lock(&games_list_mutex);
	this->games_list = games_list;
	pthread_mutex_unlock(&games_list_mutex);
	game_added = 0;
}

void StartCommand::StartCommand::execute(int clientSocket, vector<string> args) {
	if (doesGameExists(this->name)) {
		game_added = -1; //game with this name is already exists
	}
	else {
		Game game = Game(this->name);
		addGame(game);		//ADD HERE THE ACTUALLY START GAME...?? THREAD, CONNECTION...??
		game_added = 1;
	}

	SendGameStartsCommandMsg(clientSocket ,game_added);
}


void StartCommand::addGame(Game g) {
	pthread_mutex_lock(&games_list_mutex);
	this->games_list.push_back(g);
	pthread_mutex_unlock(&games_list_mutex);

}


StartCommand::~StartCommand() {
	// TODO Auto-generated destructor stub
}


bool StartCommand::doesGameExists(char* name) {
	bool the_same = false;
	pthread_mutex_lock(&games_list_mutex);
	for (unsigned int i = 0; i < this->games_list.size(); i++) {
		if (strcmp(name, this->games_list[i].getName()) == 0) {
			the_same = true;
			return the_same;
		}
	}
	pthread_mutex_unlock(&games_list_mutex);
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
