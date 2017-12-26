/*
 * ListGamesCommand.h
 *
 *  Created on: Dec 25, 2017
 *      Author: efrat
 */

#ifndef SRC_LISTGAMESCOMMAND_H_
#define SRC_LISTGAMESCOMMAND_H_

#include "Command.h"
#include "Game.h"
#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>


namespace std {

class ListGamesCommand: public Command{

public:
	ListGamesCommand(vector<Game>& games_list);
	virtual void execute(int clientSocket, vector<string> args);
	void SendGamesToJoinList( int clientSocket, vector<Game> games_list);
	virtual ~ListGamesCommand();

private:
	vector<Game> games_list;
};

}

#endif /* SRC_LISTGAMESCOMMAND_H_ */
