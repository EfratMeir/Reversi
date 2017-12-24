/*
 * Player.h
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include <Board.h>
#include <MovesCalculator.h>
#include <Player.h>
#include <Point.h>
#include <Fliper.h>
#include "Console.h"

#include <vector>

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
	virtual Point play_one_turn(Board& board, Fliper fliper, Console& console);
	virtual char get_sign() = 0;
	virtual void set_sign(char sign) = 0;
	virtual bool get_no_moves() = 0;
	virtual Point getOpponentLastMove() = 0;
	virtual void setOpponentLastMove(Point opponent_last_move) = 0;
	Point opponent_last_move;

	/**
		* puts the chosen point on the board.
		* (updating the counter will be from fliper)
		* @param board - board reference
		* @param chosen_step - the point that shows the chosen step
		*/
		virtual void play_next_step(Board& board, Point chosen_step, Console& console) = 0;
	/*
	 * destructor
	 */
	virtual ~Player() = 0;

private:

//	bool no_moves;
	/**
	 * checks for all the possible moves.
	 * @param board - board reference
	 * @param moves_calculator - moves calculator object
	 * @param this_player_sign - char
	 * @return - a vector of points, all the possible moves.
	 */
	virtual vector<Point> get_possible_moves(Board& board,
			MovesCalculator moves_calculator) = 0;

	/**
	* choose the best move out of the possible moves
	* @param options_list - a vector of all the options
	* @return - the chosen point
	*/
	virtual Point choose_best_move(vector<Point> options_list, Fliper flip, Board& board, Console& console) = 0;



};

#endif /* PLAYER_H_ */
