/*
 * HumenPlayer.h
 *
 *  Created on: Nov 3, 2017
 *      Author: Efrat Meir
 *      user name: meirefr
 *      ID: 201543253
 */

#ifndef HUMENPLAYER_H_
#define HUMENPLAYER_H_

#include <Player.h>
#include <iostream>
using namespace std;

class HumenPlayer: public Player {
public:
	/**
	 * default constructor
	 */
	HumenPlayer();
	/**
	 * constructor:
	 */
	HumenPlayer(Board& board, char sign);
	//class members:
	bool no_moves;
	char sign;
	MovesCalculator moves_calculator;

	/**
	 * board - an initialized board reference
	 * this function checks for options, chooses and adds the new move to the board
	 */
	virtual Point play_one_turn(Board& board);

	// getters and setters:
	virtual char get_sign();

	/**
	 * destructor
	 */
	virtual ~HumenPlayer();



private:
	/**
	 * checks for all the possible moves.
	 * @param board - board reference
	 * @param moves_calculator - moves calculator object
	 * @param this_player_sign - char
	 * @return - a vector of points, all the possible moves.
	 */
	virtual vector<Point> get_possible_moves(Board& board, MovesCalculator moves_calculator, char this_player_sign);

	/**
	 * lets the human player choose the best move out of the possible moves
	 * @param options_list - a vector of all the options
	 * @return - the chosen point
	 */
	virtual Point choose_best_move(vector<Point> options_list);

	/**
	 * puts the chosen point on the board.
	 * (updating the counter will be from fliper)
	 * @param board - board reference
	 * @param chosen_step - the point that shows the chosen step
	 */
	virtual void play_next_step(Board& board, Point chosen_step);

	/**
	 * checks if a point chosen is a valid option
	 * @ p - point to check
	 * @ options - a vector of all the possible points
	 * @return true / false
	 */
	bool isAnOption(Point p, vector<Point> options);
};

#endif /* HUMENPLAYER_H_ */
