/*
 * HumenPlayer.cpp
 */

#include <HumenPlayer.h>

HumenPlayer::HumenPlayer(char sign) {
	this->sign = sign;
	this->moves_calculator = MovesCalculator();
	this->no_moves = false;
}

HumenPlayer::HumenPlayer() {
	this->sign = 'H'; //Humen - not initialized
	this->moves_calculator = MovesCalculator();
	this->no_moves = false;
}
bool HumenPlayer::get_no_moves(){

	return this->no_moves;
}

void HumenPlayer::setOpponentLastMove(Point opponent_last_move) {
	int row = opponent_last_move.get_row();
	int col = opponent_last_move.get_col();
	Point p = Point(row,col, opponent_last_move.get_sign());
	this->opponent_last_move = p;
}


vector<Point> HumenPlayer::get_possible_moves(Board& board,
		MovesCalculator moves_calculator) {
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

Point HumenPlayer::choose_best_move(vector<Point> options_list, Fliper flip, Board& board) {
	cout << "please choose your next step row,column" << endl;
	char dummy;
	int x;
	int y;
	unsigned int i = 0;
	Point chosen_step;
	while (true) {
	x = 0;
	y = 0;
	cin >> x >> dummy >> y; //  x,y
	chosen_step = Point(x - 1, y - 1, this->sign);
	if (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "you have entered an inValid point." << endl << "please enter one of your options." << endl;
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
void HumenPlayer::set_sign(char sign){
	this->sign = sign;
}
void HumenPlayer::play_next_step(Board& board, Point chosen_step) {
	board.setPoint(chosen_step);
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
HumenPlayer::~HumenPlayer() {

}

Point HumenPlayer::getOpponentLastMove() {
	return this->opponent_last_move;
}
