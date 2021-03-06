/*
 * ListGamesCommand.cpp
 *
 *  Created on: Dec 25, 2017
 *      Author: efrat
 */

#include <ListGamesCommand.h>


using namespace std;
ListGamesCommand::ListGamesCommand(){

}
ListGamesCommand::ListGamesCommand(vector<Game>& games_list) {

	pthread_mutex_lock(&games_list_mutex);
	this->games_list = games_list;
	pthread_mutex_unlock(&games_list_mutex);

}

void ListGamesCommand::execute(int clientSocket, vector<string> args, vector<Game>& games_list) {
	SendGamesToJoinList(clientSocket, games_list);
}

void ListGamesCommand::SendGamesToJoinList(int clientSocket,
		vector<Game>& games_list) {
	vector<string> games_to_join;

		//critical section (mutex here must be on the entire loop)
		pthread_mutex_lock(&games_list_mutex);
	for (unsigned int i = 0; i < games_list.size(); i++) {
		if (games_list[i].getNumOfplayers() == 1) {
			games_to_join.push_back(games_list[i].getName());
		}
	}
		pthread_mutex_unlock(&games_list_mutex);


	int num = games_to_join.size();

	int n = write(clientSocket, &num, sizeof(num));
	if (n == -1) {
		cout << "Error writing num of games_to_join_list" << endl;
		return;
	}

	char game_name[50];
	for ( int i = 0; i < num; i++) {

		//critical section
		pthread_mutex_lock(&games_list_mutex);
		strcpy(game_name, games_to_join[i].c_str());
		pthread_mutex_unlock(&games_list_mutex);

		n = write(clientSocket, game_name, sizeof(game_name));
		if (n == -1) {
			cout << "Error writing games_to_join_list, game num:" << i << endl;
			return;
		}
	}
}

ListGamesCommand::~ListGamesCommand() {
	// TODO Auto-generated destructor stub
}



