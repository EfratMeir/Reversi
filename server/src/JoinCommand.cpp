/*
 * JoinCommand.cpp
 *
 *  Created on: Dec 28, 2017
 *      Author: keren
 */

#include <JoinCommand.h>

JoinCommand::JoinCommand() {


}
void JoinCommand::setName(string name){
	const char* game_name = name.c_str();
	this->name = game_name;
}
void JoinCommand::execute(int clientSocket, vector<string> args){
//	setName(args[2]);
	this->name = args[2];
	bool two_players = false;
	for (unsigned int i = 0; i < this->games_list.size(); i++) {
		const char* this_game_name = name.c_str();
		const char* game_in_list = this->games_list[i].getName().c_str();
		if (strcmp(this_game_name, game_in_list) == 0) {
			pthread_mutex_lock(&games_list_mutex);
			games_list[i].addPlayer(clientSocket);
			two_players = true;
			pthread_mutex_unlock(&games_list_mutex);
		}
	}
	SendTwoPlayersInGameMsg(clientSocket ,two_players);
}
void JoinCommand::SendTwoPlayersInGameMsg(int clientSocket, bool msg) {
		bool msgToClient = msg;
		// if msg == 1 --> game started
		// if msg == -1 --> a game with this name already exists
		int n = write(clientSocket, &msgToClient, sizeof(msgToClient));
		if (n == -1) {
			cout << "Error writing msg to client from start command" << endl;
			return;
		}
	}
JoinCommand::~JoinCommand() {
	// TODO Auto-generated destructor stub
}

