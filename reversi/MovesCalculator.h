/*
 * MovesCalculator.h
 *
 *  Created on: Nov 4, 2017
 *      Author: Efrat Meir
 *      user name: meirefr
 *      ID: 201543253
 */

#ifndef MOVESCALCULATOR_H_
#define MOVESCALCULATOR_H_
#include <iostream>
#include "Board.h"
//#include "Player.h"
#include <vector>
#include <list>
using namespace std;

/*
 * calculates for a player the possible moves each turn
 */
class MovesCalculator {
public:
	/*
	 * constructor
	 */
	MovesCalculator();
	/*
	 * gets a board and a player sign and calculates all his
	 * possible moves, using all the "check directions" functions
	 * @return - vector of points - options of moves
	 */
	vector<Point> calc_moves(Board board, char this_player_sign);


/**
 * for all the check_direction functions - assume they get the opponent point as current point, and check around it for possible moves.
 * adds the moves found to 'options'
 * @board - the game board
 * @current point - the opponent point to check around.
 * @this_player_sign - char
 * @options - a vector of options to add to.
 */
	void checkRight(Board board, Point current_point, char this_playr_sign, vector<Point>& options);
	void checkLeft(Board board, Point current_point, char this_playr_sign, vector<Point>& options);
	void checkDown(Board board, Point current_point, char this_playr_sign, vector<Point>& options);
	void checkUp(Board board, Point current_point, char this_playr_sign, vector<Point>& options);
	void checkUpRightDiagonal(Board board, Point current_point, char this_playr_sign, vector<Point>& options);
	void checkUpLeftDiagonal(Board board, Point current_point, char this_playr_sign, vector<Point>& options);
	void checkDownRightDiagonal(Board board, Point current_point, char this_playr_sign, vector<Point>& options);
	void checkDownLeftDiagonal(Board board, Point current_point, char this_playr_sign, vector<Point>& options);

	/*
	 * destructor
	 */
	virtual ~MovesCalculator();
};

#endif /* MOVESCALCULATOR_H_ */
