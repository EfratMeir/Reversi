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


void ClientHandler::closeAllClientsSockets() {
	for (unsigned int i = 0; i < static_games_list.size(); i++) {
		if(static_games_list[i]. getClientSocket1() != 0) {
			close(static_games_list[i].getClientSocket1());
		}
		if(static_games_list[i]. getClientSocket2() != 0) {
			close(static_games_list[i].getClientSocket2());
		}
	}
}

void ClientHandler::handleClient(int client_socket, char commandsAndArgs[50]) {	setArgs(client_socket,commandsAndArgs);
pthread_t new_thread;
threads_vec.push_back(new_thread);
int thread = pthread_create(&threads_vec[threads_vec.size() - 1], NULL, goToCommands ,(void*)&this->args_and_command);
//int thread = pthread_create(&new_thread, NULL, goToCommands ,(void*)&this->args_and_command);
if (thread) {
	cout << "ERROR: unable to create thread: "<< threads_vec.size() << endl;
	return;
}
//threads_vec.push_back(new_thread);

//	pthread_exit(NULL);
	return;
}

void ClientHandler::setArgs(int client_socket, char commandsAndArgs[50]) {
	this->args_and_command.erase(this->args_and_command.begin(), this->args_and_command.end());
	stringstream ss;
	ss << client_socket;
	string str_socket = ss.str();

//	string str_socket = ss.str();
	this->args_and_command.push_back(str_socket);
	// split all the args of the command
	char* pch;
	pch = strtok (commandsAndArgs," ");
//	string command = pch;
//		string command = strtok(NULL, " ");
//	pch = strtok (NULL, " ");
	while (pch != 0){
		this->args_and_command.push_back(pch);
		pch = strtok (NULL, " ");
	}
}

vector<pthread_t>& ClientHandler::getThreads() {
	return this->threads_vec;
}



void* ClientHandler::goToCommands(void* args) {
	CommandManeger command_m = CommandManeger(static_games_list);
	cout<< "im in threadddddddddd" << endl;
	vector<string> args_and_command = *((vector<string>*)args);
	//CALL COMMAND MANAGER TO MAP FROM HERE
	command_m.executeCommand(args_and_command, static_games_list);
	return NULL; //finishes and STUCK here.

}
ClientHandler::~ClientHandler() {
	// TODO Auto-generated destructor stub
}

