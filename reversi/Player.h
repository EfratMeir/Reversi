/*
 * Player.h
 *
 *  Created on: Nov 3, 2017
 *      Author: Efrat Meir
 *      user name: meirefr
 *      ID: 201543253
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include "Point.h"
#include "Player.h"
#include "Board.h"
#include "MovesCalculator.h"
#include <vector>
//blalalalal
using namespace std;

/*
 * an abstract class
 */
class Player {
public:

	char sign;
	MovesCalculator moves_calculator;
	/**
	* board - an initialized board reference
	* this function checks for options, chooses and adds the new move to the board
	*/
	virtual Point play_one_turn(Board& board) = 0;

	/*
	 * destructor
	 */
	virtual ~Player() = 0;

private:
	/**
	 * checks for all the possible moves.
	 * @param board - board reference
	 * @param moves_calculator - moves calculator object
	 * @param this_player_sign - char
	 * @return - a vector of points, all the possible moves.
	 */
	virtual vector<Point> get_possible_moves(Board& board, MovesCalculator moves_calculator, char this_player_sign) = 0;

	/**
	* choose the best move out of the possible moves
	* @param options_list - a vector of all the options
	* @return - the chosen point
	*/
	virtual Point choose_best_move(vector<Point> options_list) = 0;

	/**
	* puts the chosen point on the board.
	* (updating the counter will be from fliper)
	* @param board - board reference
	* @param chosen_step - the point that shows the chosen step
	*/
	virtual void play_next_step(Board& board, Point chosen_step) = 0;
};

#endif /* PLAYER_H_ */
