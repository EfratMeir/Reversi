/*
 * ClientHandler.h
 *
 *  Created on: Dec 26, 2017
 *      Author: efrat
 */

#ifndef INCLUDE_CLIENTHANDLER_H_
#define INCLUDE_CLIENTHANDLER_H_
//#define MAX_THREADS 15

#include <pthread.h>
#include <vector>
#include <iostream>

#include <CommandManeger.h>
#include <Game.h>

//#include <stddef.h>

using namespace std;

class ClientHandler {
public:
	ClientHandler();
	void handleClient(int client_socket);
	virtual ~ClientHandler();

private:
	vector<Game> games_list;
	pthread_mutex_t games_list_mutex;

	vector<pthread_t> threads_vec;
	CommandManeger command_maneger;
	static void* goToCommands(void *client_socket);
	vector<Game>& getGamesList(){
		return games_list;
	}
};



#endif /* INCLUDE_CLIENTHANDLER_H_ */
