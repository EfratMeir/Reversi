/*
 * HumenPlayer.h
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
	HumenPlayer( char sign);
	/**
	* get the bool 'no_moves' - true if the player have no moves.
	*/
	bool get_no_moves();
	/**
	 * calculates the possible moves.
	 */
	MovesCalculator moves_calculator;
	/**
	 * get the sign of the player.
	 */
	virtual char get_sign();
	virtual void set_sign(char sign);
	virtual void setOpponentLastMove(Point opponent_last_move);
	virtual Point getOpponentLastMove();

	/**
	 * destructor
	 */
	virtual ~HumenPlayer();
private:
	Point opponent_last_move;
	char sign;
	bool no_moves;
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
	 * lets the human player choose the best move out of the possible moves
	 * @param options_list - a vector of all the options
	 * @return - the chosen point
	 */
	virtual Point choose_best_move(vector<Point> options_list, Fliper flip, Board& board);


	/**
	 * checks if a point chosen is a valid option
	 * @ p - point to check
	 * @ options - a vector of all the possible points
	 * @return true / false
	 */
	bool isAnOption(Point p, vector<Point> options);
};

#endif /* HUMENPLAYER_H_ */
