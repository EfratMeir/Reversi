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
	Connecter( char *serverIP, int serverPort); //change from const char to char MAYBE MISTAKE
	void connectToServer();
	int sendMsg(Point p, bool player_has_no_moves);
	int reciveColorPlayer();
	Point recivePoint();
	bool reciveNoMoves();

	//int sendExercise(int arg1, char op, int arg2);
private:
	char *serverIP; //CHANGE FROM CONST CHAR* TO CHAR*
	int serverPort;
	int clientSocket;
	int sendPoint(Point p);
	int sendNoMoves(bool player_has_no_moves);
};

#endif /* CONNECTER_H_ */
