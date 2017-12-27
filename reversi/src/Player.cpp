/*
 * Player.cpp
 */

#include <Board.h>
#include <Player.h>
#include <iostream>
#include<vector>
using namespace std;

Point Player::play_one_turn(Board& board, Fliper& flip, Console& console) {
	vector<Point> options = get_possible_moves(board, this->moves_calculator);
	if (options.size() == 0 || (options[0].get_col() == -1 && options[0].get_row() == -1)) {
		return Point(-1,-1, 'Y'); //no point
	}
	Point chosen_point = choose_best_move(options, flip, board, console);
	play_next_step(board, chosen_point, console);
	return chosen_point;
}

void Player::play_next_step(Board& board, Point& chosen_step, Console& console) {
	board.setPoint(chosen_step);
	board.getCounter().add_one(chosen_step.get_sign());
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}


