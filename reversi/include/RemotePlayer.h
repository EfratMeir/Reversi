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
	/**
	 * constructor
	 * @param connecter
	 */
	RemotePlayer(Connecter& connecter);

	/**
	 * return 1 if ther's no moves, else 0
	 * @return
	 */
	bool get_no_moves();
	/**
	 * set the sign of the opponent player.
	 * @param sign
	 */
	virtual void set_sign(char sign);
	/**
	 * set the sign of the remote player from the server (X if he is first)
	 */
	void set_sign();
	/**
	 * get the sign of the player
	 * @return
	 */
	virtual char get_sign();
	/**
	 * get the connecter
	 * @return
	 */
	Connecter& getConnecter();
	/**
	 * set the 'opponent ha no move' bool of the opponent player.
	 * @param opp_has_no_moves
	 */
	void setOpponentHasNoMoves(bool opp_has_no_moves);
	/**
	 * set the last move of the opponent player.
	 * @param opponent_last_move
	 */
	virtual void setOpponentLastMove(Point opponent_last_move);
	/**
	 * get the last move of the opponent player.
	 * @return
	 */
	virtual Point getOpponentLastMove();
	/**
	 * destructor
	 */
	virtual ~RemotePlayer();

private:
	/*
	 * true if the player has no more moves, false otherwise.
	 */
	bool has_no_moves;
	char sign;
	Point opponent_last_move;
	bool opponent_has_no_move;
	bool my_first_move;
	Connecter connecter;
	int port;
    const char * IP;
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
