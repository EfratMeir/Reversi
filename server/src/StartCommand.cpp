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
//	this->games_list = ;
	this->game_added = 0;
}
StartCommand::StartCommand( string name, vector<Game>& games_list) {
	this->name = name;
	pthread_mutex_lock(&games_list_mutex);
	this->games_list = games_list;
	pthread_mutex_unlock(&games_list_mutex);
	game_added = 0;
}

//
////	SendGameStartsCommandMsg(clientSocket ,game_added);
//}
void StartCommand::setName(string name){
//	const char * temp_name = name.c_str();
//	char* game_name;
//	strcpy(this->name, temp_name);
//	strcpy(this->name, game_name);
//	this->name = name;
}
void StartCommand::execute(int clientSocket, vector<string> args) {
	setName(args[2]);
	this->name = args[2];
	if (doesGameExists(this->name)) {
		game_added = -1; //game with this name is already exists
	}
	else {
		Game game = Game(this->name);
		addGame(game);		//ADD HERE THE ACTUALLY START GAME...?? THREAD, CONNECTION...??
		this->game_added += 1;
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


bool StartCommand::doesGameExists( string name) {
	bool the_same = false;
	for (unsigned int i = 0; i < this->games_list.size(); i++) {
		const char* this_game_name = name.c_str();
		const char* game_in_list = this->games_list[i].getName().c_str();
		if (strcmp(this_game_name, game_in_list) == 0) {
			pthread_mutex_lock(&games_list_mutex);
			the_same = true;
			pthread_mutex_unlock(&games_list_mutex);
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
