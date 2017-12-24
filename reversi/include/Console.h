/*
 * Console.h
 *
 *  Created on: Dec 23, 2017
 *      Author: keren
 */

#ifndef SRC_CONSOLE_H_
#define SRC_CONSOLE_H_
#include "Display.h"
#include <iostream>
using namespace std;
/*
 *
 */
class Console: public Display {
public:
	Console();
	Console(Board& board);
	void canStart();
	void printConnectToServer();
	void printWaitingToOther();
	virtual void printBoard();
	void printNowTurn(char sign);
	void printChosenMove(char sign, int row, int col);
	char choose_players();
	void printWinner(char winner);
	void connectionFailed(const char *msg);
	void printCounter(PointsCounter counter);
	virtual ~Console();
private:
	Board board;
};

#endif /* SRC_CONSOLE_H_ */
