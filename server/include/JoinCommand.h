/*
 * JoinCommand.h
 *
 *  Created on: Dec 28, 2017
 *      Author: keren
 */

#ifndef SRC_JOINCOMMAND_H_
#define SRC_JOINCOMMAND_H_
#include "Command.h"
#include <string.h>
#include <unistd.h>

/*
 *
 */
class JoinCommand : public Command{
public:
	JoinCommand();
	void setName(string name);
	virtual void execute(int clientSocket, vector<string> args, vector<Game>& games_list);
	bool doesGameExists(const char* name);
//	pthread_mutex_t games_list_mutex;
	void SendTwoPlayersInGameMsg(int clientSocket, bool msg);
	void notifyGameStarts(int clientSocket1, int clientSocket2);

	virtual ~JoinCommand();
private:
	const char* game_to_join_name;
};

#endif /* SRC_JOINCOMMAND_H_ */
