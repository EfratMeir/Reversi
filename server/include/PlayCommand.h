/*
 * PlayCommand.h
 *
 *  Created on: Dec 26, 2017
 *      Author: efrat
 */

#ifndef INCLUDE_PLAYCOMMAND_H_
#define INCLUDE_PLAYCOMMAND_H_

#include <Command.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

class PlayCommand: public Command {
public:
	PlayCommand();
	virtual void execute(int clientSocket ,vector<string> args, vector<Game>& games_list);
	virtual ~PlayCommand();
private:
	void play(int clientSocket1, int clientSocket2);
};

#endif /* INCLUDE_PLAYCOMMAND_H_ */
