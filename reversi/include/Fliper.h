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

#include <Board.h>
#include <Point.h>
#include <iostream>
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
	 * gets the board and the chosen point, and each function checks
	 * the direction it responsible of.
	 * @return - vector of points need to be flipped.
	 */
	void checkAndUpdateUp(Point chosen_point, Board board);
	void checkAndUpdateDown(Point chosen_point, Board board);
	void checkAndUpdateRight(Point chosen_point, Board board);
	void checkAndUpdateLeft(Point chosen_point, Board board);
	void checkAndUpdateUpRight(Point chosen_point, Board board);
	void checkAndUpdateUpLeft(Point chosen_point, Board board);
	void checkAndUpdateDownRight(Point chosen_point, Board board);
	void checkAndUpdateDownLeft(Point chosen_point, Board board);

	/**
	 * adds all the points from the "from" vector to "to" vector
	 */
	void addVecToVec(vector<Point> from, vector<Point> &to);

	/**
	 * destructor
	 */
	virtual ~Fliper();


private:
	vector<Point> points_to_flip;
	/*
	 * gets a player sign and returns the opponent sign
	 */
	char FindOpponentSign(char my_sign);
};

#endif /* FLIPER_H_ */
