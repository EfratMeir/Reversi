/*
 * HumenPlayer.cpp
 *
 *  Created on: Nov 3, 2017
 *      Author: Efrat Meir
 *      user name: meirefr
 *      ID: 201543253
 */

#include <HumenPlayer.h>

HumenPlayer::HumenPlayer(Board& board, char sign) {
	this->sign = sign;
	this->moves_calculator = MovesCalculator();
	this->no_moves = false;

}

HumenPlayer::HumenPlayer() {
	this->sign = 'H'; //Humen - not initialized
	this->moves_calculator = MovesCalculator();
	this->no_moves = false;
}



Point HumenPlayer::play_one_turn(Board& board) {
	vector<Point> options = get_possible_moves(board, this->moves_calculator, this->sign);
	if (options.size() == 0) {
		return Point(-1,-1, 'Y'); //no point
	}
	Point chosen_point = choose_best_move(options);
	play_next_step(board, chosen_point);
	return chosen_point;
}



vector<Point> HumenPlayer::get_possible_moves(Board& board,
		MovesCalculator moves_calculator, char this_player_sign) {
	this->no_moves = false;
	vector<Point> options = moves_calculator.calc_moves(board, this->sign);
	if (options.size() == 0) {
		cout << sign <<", you have no possible moves." << endl;
		this->no_moves = true;
		return options;
	}
	cout << sign <<", your possible moves are:" << endl;
	for (unsigned int i = 0; i < options.size(); i++) { //might cause a problem! change later to itertor
		options[i].printValuesPlusOne();
		cout <<"  ";
	}
	cout << endl;
	return options;

}

Point HumenPlayer::choose_best_move(vector<Point> options_list) {
	cout << "please choose your next step (row,column)";
	char dummy;
	int x;
	int y;
	unsigned int i = 0;
	Point chosen_step;
	while (true) {
	x = 0;
	y = 0;
	cin >> dummy >> x >> dummy >> y >> dummy; //  (x,y)
	chosen_step = Point(x - 1, y - 1, this->sign);
	if (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "you have entered an inValid point. please enter one of your options." << endl;
			cout << sign <<", your possible moves are:" << endl;
			for (i = 0; i < options_list.size(); i++) {
				options_list[i].printValuesPlusOne();
				cout <<"  ";
			}
			cout << endl;
	}
	else {
		if(isAnOption(chosen_step, options_list)) {
			return chosen_step;
		}
		else {
			cout << "you have entered an inValid point. please enter one of your options." << endl;
				cout << sign <<", your possible moves are:" << endl;
				for (i = 0; i < options_list.size(); i++) {
					options_list[i].printValuesPlusOne();
					cout <<"  ";
				}
				cout << endl;
		}
	}
	}
}

char HumenPlayer::get_sign() {
	return this->sign;
}

void HumenPlayer::play_next_step(Board& board, Point chosen_step) {
	board.setPoint(chosen_step);
}

HumenPlayer::~HumenPlayer() {
	// TODO Auto-generated destructor stub
}

bool HumenPlayer::isAnOption(Point p, vector<Point> options) {
	for (unsigned int i = 0; i < options.size(); i++) {
		if (p.get_row() == options[i].get_row()
				&& p.get_col() == options[i].get_col()) {
			return true;
		}
	}
	return false;
}
