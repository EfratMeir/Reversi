/*
 * Board.h
 *
 *  Created on: Oct 28, 2017
 *      Author: Efrat Meir
 *      user name meirefr
 *      ID 201543253
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <Point.h>
#include <PointsCounter.h>
#include <iostream>
#define SIZE 8
using namespace std;

class Board {
private:
	PointsCounter counter;
public:

	/**
	 * drfault constructor
	 */
	Board();

	/**
	 * constructor.
	 */
	Board(int rows, int cols);

	Point parr[SIZE][SIZE];
	/**
	 * prints the default game board.
	 */
	void pPrint();

	//getters:

	int getNumCols() const {
		return num_cols;
	}

	int getNumRows() const {
		return num_rows;
	}

	PointsCounter& getCounter() {
		return counter;
	}

	/**
	 * sets point on the board
	 */
	void setPoint(Point p);

	/**
	 * checks if the board is full
	 * @return true / false
	 */
	bool isFull();

	static const char black_player = 'X';
	static const char white_player = 'O';
	static const char blank = ' ';

private:
	int num_rows;
	int num_cols;

};

#endif /* BOARD_H_ */
