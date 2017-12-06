/*
 * RemotePlayer.h
 *
 *  Created on: Dec 6, 2017
 *      Author: efrat
 */

#ifndef SRC_REMOTEPLAYER_H_
#define SRC_REMOTEPLAYER_H_

#include "Player.h"
#include "Connecter.h"

class RemotePlayer: public Player{
public:
	RemotePlayer();
	RemotePlayer(char sign);
	virtual ~RemotePlayer();
	bool get_no_moves();
	char get_sign();
	Connecter& getConnecter();

private:
	/*
	 * true if the player hsa no more moves, false otherwise.
	 */
	Connecter connecter;
	bool has_no_moves;
	char sign;
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
	int initializeConnecter();

};

#endif /* SRC_REMOTEPLAYER_H_ */
