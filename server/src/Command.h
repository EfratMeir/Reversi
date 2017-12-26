/*
 * Command.h
 *
 *  Created on: Dec 24, 2017
 *      Author: efrat
 */

#ifndef SRC_COMMAND_H_
#define SRC_COMMAND_H_
#include "Server.h"
#include <string>
#include <vector>
class Command {
public:
	virtual void execute(int clientSocket, vector<string> args) = 0;
	virtual ~Command() = 0;
private:
};

#endif /* SRC_COMMAND_H_ */
