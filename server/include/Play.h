/*
 * PlayCommand.h
 *
 *  Created on: Dec 26, 2017
 *      Author: efrat
 */

#ifndef INCLUDE_PLAY_H_
#define INCLUDE_PLAY_H_

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <vector>

using namespace std;
class Play {
public:
	Play();
//	virtual void execute(int clientSocket ,vector<string> args, vector<Game>& games_list);
	void play(int clientSocket1, int clientSocket2);
	 ~Play();
private:
};

#endif /* INCLUDE_PLAY_H_ */
