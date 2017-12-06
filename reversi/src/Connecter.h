/*
 * Connecter.h
 *
 *  Created on: Dec 6, 2017
 *      Author: efrat
 */

#ifndef CONNECTER_H_
#define CONNECTER_H_

#include "Point.h"

class Connecter {
public:
	Connecter();
	Connecter(const char *serverIP, int serverPort);
	void connectToServer();
	int sendMsg(Point p, bool player_has_no_moves);
	Point recivePoint();
	bool reciveNoMoves();

	//int sendExercise(int arg1, char op, int arg2);
private:
	const char *serverIP;
	int serverPort;
	int clientSocket;
	int sendPoint(Point p);
	int sendNoMoves(bool player_has_no_moves);
};

#endif /* CONNECTER_H_ */
