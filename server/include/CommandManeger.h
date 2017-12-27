/*
 * CommandManeger.h
 *
 *  Created on: Dec 26, 2017
 *      Author: efrat
 */

#ifndef INCLUDE_COMMANDMANEGER_H_
#define INCLUDE_COMMANDMANEGER_H_

#include <string.h>
#include <vector>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <map>
#include "Command.h"

using namespace std;

class CommandManeger {
public:
	CommandManeger();
//	void map(int client_socket, vector<string> args);
	void executeCommand(string command, vector<string> args);
	virtual ~CommandManeger();
private:
	map <string, Command*> commandsMap;

};


#endif /* INCLUDE_COMMANDMANEGER_H_ */
