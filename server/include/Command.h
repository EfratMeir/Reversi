/*
 * Command.h
 *
 *  Created on: Dec 24, 2017
 *      Author: efrat
 */

#ifndef INCLUDE_COMMAND_H_
#define INCLUDE_COMMAND_H_
//#include "Server.h"

#include <iostream>
#include <vector>

using namespace std;

class Command {
public:
	virtual void execute(int clientSocket, vector<string> args) = 0;
	virtual ~Command() = 0;
private:
};

#endif /* INCLUDE_COMMAND_H_ */
