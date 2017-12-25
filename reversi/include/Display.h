/*
 * Display.h
 *
 *  Created on: Dec 23, 2017
 *      Author: keren
 */

#ifndef SRC_DISPLAY_H_
#define SRC_DISPLAY_H_
#include "Board.h"
/*
 *
 */
class Display {
public:
	Display();
	virtual void printBoard(Board& b) = 0;
	virtual ~Display();
};

#endif /* SRC_DISPLAY_H_ */
