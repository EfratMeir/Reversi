/*
 * ComputerPlayer.h
 *  Created on: Nov 3, 2017
 */

#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_
#include "Player.h"
#include <iostream>


class ComputerPlayer: public Player {
public:
	/**
	* default constructor
	*/
	ComputerPlayer();
	/**
	 * constructor
	 */
	ComputerPlayer(char sign);
	/**
	 * get the bool 'no_moves' - true if the player have no moves.
	 */
	bool get_no_moves();
	/**
	 * get the sign of the rival player.
	 */
	char get_opp_sign();
	/**
	 * get the sign of the player.
	 */
	virtual char get_sign();
	/**
	 * set the sign of the player
	 * @param sign
	 */
	virtual void set_sign(char sign);
	/**
	 * set the last move of the opponent
	 * @param opponent_last_move
	 */
	virtual void setOpponentLastMove(Point opponent_last_move);
	/**
	 * get the last move of the opponent
	 * @return
	 */
	virtual Point getOpponentLastMove();
	/**
	* calculates the possible moves.
	*/
	MovesCalculator moves_calculator;
	/**
	 * rate the possible moves of the rival.
	 * @param point
	 * @param fliper
	 * @param board
	 * @return the best score the rival can get
	 */
	int rate_move(Point point, Fliper fliper, Board& board);
	/**
	 * destructor
	 */
	~ComputerPlayer();



private:
	//members
	bool no_moves;
	char sign;
	char computer_sign;
	char rival_sign;
	bool rival_turn;
	Point opponent_last_move;

	/**
	 * puts the chosen point on the board.
	 * (updating the counter will be from fliper)
	 * @param board - board reference
	 * @param chosen_step - the point that shows the chosen step
	 */
	virtual void play_next_step(Board& board, Point chosen_step);
	/**
	 * checks for all the possible moves.
	 * @param board - board reference
	 * @param moves_calculator - moves calculator object
	 * @param this_player_sign - char
	 * @return - a vector of points, all the possible moves.
	 */
	virtual vector<Point> get_possible_moves(Board& board, MovesCalculator moves_calculator);
	/**
	 * choose the best move of the computer according the 'minimax' algorithm.
	 * @param options_list - a vector of all the options
	 * @return - the chosen point
	 */
	virtual Point choose_best_move(vector<Point> options_list, Fliper fliper, Board& board);
};

#endif /* COMPUTERPLAYER_H_ */
