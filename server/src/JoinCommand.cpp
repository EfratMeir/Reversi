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

	this->game_to_join_name = args[2];
	int client_socket1,client_socket2;
	bool two_players = false;
	for (unsigned int i = 0; i < games_list.size(); i++) {
		const char* this_game_to_join = game_to_join_name.c_str();

		//critical section
		pthread_mutex_lock(&games_list_mutex);
		const char* game_in_list = games_list[i].getName().c_str();
		bool started = games_list[i].getStartedPlaying();
		pthread_mutex_unlock(&games_list_mutex);

		if (strcmp(this_game_to_join, game_in_list) == 0 && !started) {
				sendJoinValid(clientSocket,true);

			//critical section
			pthread_mutex_lock(&games_list_mutex);
			games_list[i].addPlayer(clientSocket);
			games_list[i].setGameStarted();
			two_players = true;
			pthread_mutex_unlock(&games_list_mutex);

			client_socket1 = games_list[i].getClientSocket1();
			client_socket2 = games_list[i].getClientSocket2();

			notifyGameStarts(client_socket1, client_socket2);
		}
	}
	//if there is no game in the list, return false and CLOSE THE SOCKET!!!!!!
	//if its just the end of the game(there WAS a game), continue
	if(!two_players){
		sendJoinValid(clientSocket, false);
		close(clientSocket);
	}
}


void JoinCommand::sendJoinValid(int client_socket, bool join_valid){
	int n = write(client_socket, &join_valid, sizeof(join_valid));
	if (n == -1) {
		cout << "Error writing join_valid" << endl;
		return;
	}
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



	this->play.play(clientSocket1,clientSocket2);
}
JoinCommand::~JoinCommand() {
	// TODO Auto-generated destructor stub
}

