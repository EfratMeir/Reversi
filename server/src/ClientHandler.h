/*
 * ClientHandler.h
 *
 *  Created on: Dec 26, 2017
 *      Author: efrat
 */

#ifndef SRC_CLIENTHANDLER_H_
#define SRC_CLIENTHANDLER_H_

#include <vector>
#include "Game.h"
#include "CommandManeger.h"
#include <iostream>

using namespace std;

class ClientHandler {
public:
	ClientHandler();
	void handleClient();
	virtual ~ClientHandler();

private:
	vector<Game> games_list;
	CommandManeger command_maneger;
	vector<Game>& getGamesList(){
		return games_list;
	}
};



#endif /* SRC_CLIENTHANDLER_H_ */
