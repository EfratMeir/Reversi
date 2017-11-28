/*
 * ComputerPlayer.h
 *
 *  Created on: Nov 3, 2017
 *      Author: Efrat Meir
 *      user name: meirefr
 *      ID: 201543253
 */

#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_
#include "Player.h"
#include "HumenPlayer.h"
#include <iostream>


class ComputerPlayer: public Player {
public:
	ComputerPlayer();

	bool get_no_moves();
	char get_opp_sign(char sign);
	virtual char get_sign();
	HumenPlayer* rival;
	ComputerPlayer(char sign);
	MovesCalculator moves_calculator;
//	virtual Point play_one_turn(Board& board);
//	virtual char get_sign();
	~ComputerPlayer();
	int rate_move(Point point, Fliper fliper, Board& board);



private:
	bool no_moves;
	char sign;
	char computer_sign;
	char rival_sign;
	bool rival_turn;
	virtual vector<Point> get_possible_moves(Board& board, MovesCalculator moves_calculator, char this_player_sign);
	virtual Point choose_best_move(vector<Point> options_list, Fliper fliper, Board& board);
//	virtual void play_next_step(Board& board, Point chosen_step);

};

#endif /* COMPUTERPLAYER_H_ */
