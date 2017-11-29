/*
 * ComputerPlayer.cpp
 */

#include "ComputerPlayer.h"
#include "Player.h"

ComputerPlayer::ComputerPlayer() {
	this->sign = 'C'; //Computer - not initialized
	this->moves_calculator = MovesCalculator();
	this->no_moves = false;
	this->computer_sign = this->sign;
	this->rival_sign = get_opp_sign(sign);
	//this->rival = new HumenPlayer('X');
	this->rival_turn = false;

}

ComputerPlayer::ComputerPlayer(char sign) {
	this->sign = sign;
	this->moves_calculator = MovesCalculator();
	this->no_moves = false;
	this->computer_sign = this->sign;
	//this->rival = new HumenPlayer('X');
	this->rival_sign = get_opp_sign(sign);
	this->rival_turn = false;

}
bool ComputerPlayer::get_no_moves(){
	return this->no_moves;
}
char ComputerPlayer::get_sign() {
	return this->sign;
}
void ComputerPlayer::play_next_step(Board& board, Point chosen_step) {
	board.setPoint(chosen_step);
}
char ComputerPlayer::get_opp_sign(char sign){
	char opp_sign;
		if (this->sign == 'X') {
			opp_sign = 'O';
		}
		if (this->sign == 'O') {
			opp_sign = 'X';
		}
		return opp_sign;
}
ComputerPlayer::~ComputerPlayer() {
	// TODO Auto-generated destructor stub
}
vector<Point> ComputerPlayer::get_possible_moves(Board& board,
	MovesCalculator moves_calculator, char this_player_sign) {
	this->no_moves = false;
	vector<Point> options = moves_calculator.calc_moves(board, sign);
	if (options.size() == 0 && !rival_turn) {
		cout << sign <<", you have no possible moves." << endl;
		this->no_moves = true;
		return options;
	}

	return options;
}

Point ComputerPlayer::choose_best_move(vector<Point> options_list, Fliper fliper, Board& board) {
	vector<Point>::iterator it;
	cout << "its O's turn"<< endl;
	int low_score_human = 1000;
	Point best_move_comp = Point(0, 0, this->sign);
	for (it = options_list.begin(); it != options_list.end(); ++it ) {
		Point point = *it;
		int best_score_humen = rate_move(point, fliper, board);
		//if the human player got less points in this move, make this move to be the best move for the computer:
		if (best_score_humen < low_score_human){
			low_score_human = best_score_humen;
			best_move_comp = point;
		}
	}
	best_move_comp = Point(best_move_comp.get_row(),best_move_comp.get_col(), this->sign);
	cout << " O chose to play: ";
	//<< "(" << best_move_comp.get_row() << "," << best_move_comp.get_col() << "): " << endl;
	best_move_comp.printValuesPlusOne();
	cout << endl;
	return best_move_comp;
}
int ComputerPlayer::rate_move(Point point, Fliper fliper, Board& board){
	Board temp_b = Board();
	temp_b = board;
	point.set_sign(this->sign);
	play_next_step(temp_b, point);

	//temp_b.setPoint(point);
	fliper.flip(temp_b, point, this->sign);
	//temp_b.pPrint();

	//its the rival turn:
	rival_turn = true;
	this->sign = this->rival_sign;
	//check possible moves for the rival player (the human player):
	vector<Point> rival_options = get_possible_moves(temp_b, this->moves_calculator, this->rival_sign);
	vector<Point>::iterator it;
	int best_score_humen = 0;
	//calculate the points of each rival's possible move,
	//and take the max-point-move as the best human-player move:

	for (it = rival_options.begin(); it != rival_options.end(); ++it ) {
		Board initial_b = temp_b;
		Point p = *it;
		p.set_sign(this->sign);
		play_next_step(initial_b, p);
		fliper.flip(initial_b, p, p.get_sign());
		//initial_b.pPrint();
		int score = initial_b.getCounter().getBlackCount() - initial_b.getCounter().getWhiteCount();
		if (score > best_score_humen) {
			best_score_humen = score;
		}
	}
	this->sign = this->computer_sign;
	this->rival_turn = false;
	return best_score_humen;

}

