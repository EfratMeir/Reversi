/*
 * Console.h
 *
 *  Created on: Dec 23, 2017
 *      Author: keren
 */

#ifndef SRC_CONSOLE_H_
#define SRC_CONSOLE_H_
#include "Display.h"
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;
/*
 *
 */
class Console: public Display {
public:
	Console();
	void canStart();
	void printConnectToServer();
	void printWaitingToOther();
	void printEnterCommand();
	void nameExist();

//	void enterGameName();
	virtual void printBoard(Board& b);
	void printNowTurn(char sign);
	void printChosenMove(char sign, int row, int col);
	void print_hello();
	void printInvalidChar();
	void printWinner(char winner);
	void connectionFailed(const char *msg);
	void printCounter(PointsCounter counter);
	void printGamesList(vector<string> list);
	virtual ~Console();
private:
};

#endif /* SRC_CONSOLE_H_ */
