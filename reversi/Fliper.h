/*
 * Fliper.h
 *
 *  Created on: Nov 6, 2017
 *      Author: Efrat Meir
 *      user name: meirefr
 *      ID: 201543253
 */

#ifndef FLIPER_H_
#define FLIPER_H_

#include <iostream>
#include "Board.h"
#include "Point.h"
#include <vector>
using namespace std;

class Fliper {

public:
	Fliper();
	/**
	 * flips all the points needs to be flipped according to the game logic,
	 * using all the "helper functions"
	 * @return - the number of points flipped
	 * @flip_to - the sign to change to.
	 */
	int flip(Board& board, Point chosen_point, char flip_to);
	// helper functions
	/**
	 * gets the board and he chosen point, and each function checks
	 * the direction it responsible of.
	 * @return - vector of points need to be flipped.
	 */
	vector<Point> checkUp(Point chosen_point, Board board);
	vector<Point> checkDown(Point chosen_point, Board board);
	vector<Point> checkRight(Point chosen_point, Board board);
	vector<Point> checkLeft(Point chosen_point, Board board);
	vector<Point> checkUpRight(Point chosen_point, Board board);
	vector<Point> checkUpLeft(Point chosen_point, Board board);
	vector<Point> checkDownRight(Point chosen_point, Board board);
	vector<Point> checkDownLeft(Point chosen_point, Board board);

	/**
	 * adds all the points from the "from" vector to "to" vector
	 */
	void addVecToVec(vector<Point> from, vector<Point> &to);

	/**
	 * destructor
	 */
	virtual ~Fliper();


private:
	/*
	 * gets a player sign and returns the opponent sign
	 */
	char FindOpponentSign(char my_sign);
};

#endif /* FLIPER_H_ */
