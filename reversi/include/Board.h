/*
 * Board.h
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <Point.h>
#include <PointsCounter.h>
#include <iostream>
#define SIZE 8
using namespace std;

class Board {

public:

	/**
	 * drfault constructor
	 */
	Board();

	/**
	 * constructor.
	 */
	Board(int board_size);
//	Board(const Board &cpyB);
//	int size;
	Point all_players_list[SIZE][SIZE];
//	void deleteBoard();
//	Board& cpy();
	/**
	 * prints the default game board.
	 */
	void pPrint();

	//getters:
	int getBoardSize() {
		return board_size;
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
	Point** getAllPlayers();
	static const char black_player = 'X';
	static const char white_player = 'O';
	static const char blank = ' ';

private:
	PointsCounter counter;
	int board_size;
};

#endif /* BOARD_H_ */
