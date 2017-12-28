/*
 * ClientHandler.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: efrat
 */

#include "ClientHandler.h"
using namespace std;

ClientHandler::ClientHandler() {

}

void ClientHandler::handleClient(int client_socket) {

	pthread_t new_thread;
	threads_vec.push_back(new_thread);
	int thread = pthread_create(&threads_vec[threads_vec.size()], NULL, goToCommands ,(void*)&client_socket);
	if (thread) {
		cout << "ERROR: unable to create thread: "<< threads_vec.size() << endl;
		return;
	}
	pthread_exit(NULL);
}

ClientHandler::~ClientHandler() {
	// TODO Auto-generated destructor stub
}

void* ClientHandler::goToCommands(void *args) {
//	CommandManeger command_m;
	//int socket = *((int *)client_socket);
									//CALL COMMAND MANAGER TO MAP FROM HERE

}
