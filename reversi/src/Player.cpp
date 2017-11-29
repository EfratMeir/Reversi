/*
 * Player.cpp
 */

#include <Board.h>
#include <Player.h>
#include <iostream>
#include<vector>
using namespace std;

Point Player::play_one_turn(Board& board, Fliper flip) {
	vector<Point> options = get_possible_moves(board, this->moves_calculator, sign);
	if (options.size() == 0) {
		return Point(-1,-1, 'Y'); //no point
	}
	Point chosen_point = choose_best_move(options, flip, board);
	play_next_step(board, chosen_point);
	return chosen_point;
}

void Player::play_next_step(Board& board, Point chosen_step) {
	board.setPoint(chosen_step);
	board.getCounter().add_one(chosen_step.get_sign());
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}


