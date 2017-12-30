/*
 * ClientHandler.h
 *
 *  Created on: Dec 26, 2017
 *      Author: efrat
 */

#ifndef INCLUDE_CLIENTHANDLER_H_
#define INCLUDE_CLIENTHANDLER_H_
//#define MAX_THREADS 15


#include <sstream>

#include <pthread.h>
#include <vector>
#include <iostream>
#include <CommandManeger.h>
#include <Game.h>

//#include <stddef.h>

using namespace std;

//pthread_mutex_t games_list_mutex;
static vector<Game> static_games_list;

class ClientHandler {
public:
	ClientHandler();
	void handleClient(int client_socket, char commandsAndArgs[50]);
	void setArgs(int client_socket, char commandsAndArgs[50]);
	CommandManeger& getCommandManeger(){ //deleteeeeee
		return this->command_maneger;
	}
	static vector<Game>& getGamesList(){
		return static_games_list;
	}
	virtual ~ClientHandler();

private:
	vector<string> args_and_command;
	vector<pthread_t> threads_vec;
	CommandManeger command_maneger;
	static void* goToCommands(void *);

};



#endif /* INCLUDE_CLIENTHANDLER_H_ */
