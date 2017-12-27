/*
 * CommandManeger.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: efrat
 */
//
#include <CommandManeger.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include "StartCommand.h"
using namespace std;

CommandManeger::CommandManeger() {
	commandsMap["start"] = new StartCommand();

}
void CommandManeger::executeCommand(string command, vector<string> args){
	Command* commandObj = commandsMap[command];

	int socket;
	sscanf(args[0].c_str(), "%d", &socket); //take ths socket number

	commandObj->execute(socket, args);
}
//void CommandManeger::map(int client_socket, vector<string> args) {
//	//read request:
//	string request;
//	int n = read(client_socket, &request, sizeof(request));
//	if (n == -1) {
//		cout << "Error reading request from user" << endl;
//		return;
//}


	//CONTINUE MAPING HERE...
	// ...
	// ...
	// ...

//}



CommandManeger::~CommandManeger() {
	map<string, Command*>::iterator it;
	for (it = commandsMap.begin(); it != commandsMap.end(); it++){
		delete it->second;
	}
}
