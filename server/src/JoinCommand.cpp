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
	this->game_to_join_name = game_name;
}

void JoinCommand::execute(int clientSocket, vector<string> args, vector<Game>& games_list){
//	setName(args[2]);
	this->game_to_join_name = args[2];
	bool two_players = false;
	for (unsigned int i = 0; i < /*this->*/games_list.size(); i++) {
		const char* this_game_to_join = game_to_join_name.c_str();
		const char* game_in_list = games_list[i].getName().c_str();
		if (strcmp(this_game_to_join, /*this->*/game_in_list) == 0) {
			//pthread_mutex_lock(&games_list_mutex);
			games_list[i].addPlayer(clientSocket);
			two_players = true;
			//pthread_mutex_unlock(&games_list_mutex);
			notifyGameStarts(games_list[i].getClientSocket1(), games_list[i].getClientSocket2());
			games_list[i].setGameStarted();
		}
	}
	//SendTwoPlayersInGameMsg(clientSocket ,two_players);
}

void JoinCommand::SendTwoPlayersInGameMsg(int clientSocket, bool msg) {
		bool msgToClient = msg;
		// if msg == 1 --> game started
		// if msg == -1 --> a game with this name already exists
		int n = write(clientSocket, &msgToClient, sizeof(msgToClient));
		if (n == -1) {
			cout << "Error writing msg to client from start command" << endl;
			return;
		}					//WHATTTTTTTTTTTTTTTTTTTTTTTTTTTTT???????? ITS NOT THE MSG WE SHOULD SEND!
	}



void JoinCommand::notifyGameStarts(int clientSocket1, int clientSocket2) {
	bool start_game = true;
	int n = write(clientSocket1, &start_game, sizeof(start_game));
	if (n == -1) {
		cout << "Error writing start_game" << endl;
		return;
	}

	n = write(clientSocket2, &start_game, sizeof(start_game));
	if (n == -1) {
		cout << "Error writing start_game" << endl;
		return;
	}
}
JoinCommand::~JoinCommand() {
	// TODO Auto-generated destructor stub
}

