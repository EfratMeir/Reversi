
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
	this->rival_sign = get_opp_sign();
	//this->rival = new HumenPlayer('X');
	this->rival_turn = false;

}

ComputerPlayer::ComputerPlayer(char sign) {
	this->sign = sign;
	this->moves_calculator = MovesCalculator();
	this->no_moves = false;
	this->computer_sign = this->sign;
	//this->rival = new HumenPlayer('X');
	this->rival_sign = get_opp_sign();
	this->rival_turn = false;

}
bool ComputerPlayer::get_no_moves(){
	return this->no_moves;
}
char ComputerPlayer::get_sign() {
	return this->sign;
}
void ComputerPlayer::set_sign(char sign){
	this->sign = sign;
}
void ComputerPlayer::play_next_step(Board& board, Point chosen_step) {
	board.setPoint(chosen_step);
}
char ComputerPlayer::get_opp_sign(){
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

}
vector<Point> ComputerPlayer::get_possible_moves(Board& board,
	MovesCalculator moves_calculator) {
	this->no_moves = false;
	vector<Point> options = moves_calculator.calc_moves(board, sign);
	if (options.size() == 0 && !rival_turn) {
		cout << sign <<", you have no possible moves." << endl;
		this->no_moves = true;
		return options;
	}
	return options;
}

void ComputerPlayer::setOpponentLastMove(Point opponent_last_move) {
	int row = opponent_last_move.get_row();
	int col = opponent_last_move.get_col();
	Point p = Point(row,col, opponent_last_move.get_sign());
	this->opponent_last_move = p;
}

Point ComputerPlayer::choose_best_move(vector<Point> options_list, Fliper fliper, Board& board) {
	vector<Point>::iterator it;
	cout << "its O's turn"<< endl;
	//the best score the rival(human) can get is 64
	int low_score_human = 64;
	Point best_move_comp = Point(0, 0, this->sign);
	for (it = options_list.begin(); it != options_list.end(); ++it ) {
		Point point = *it;
		int score = rate_move(point, fliper, board);
		//if the human got less points in this move, make this move to be the best move for the computer
		if (score < low_score_human){
			low_score_human = score;
			best_move_comp = point;
		}
	}
	best_move_comp = Point(best_move_comp.get_row(),best_move_comp.get_col(), this->sign);
	cout << "O' chose to play " << "(" << best_move_comp.get_row() + 1<< "," << best_move_comp.get_col() + 1 << "): " << endl;
	return best_move_comp;
}
int ComputerPlayer::rate_move(Point point, Fliper fliper, Board& board){
	Board temp_b = Board();
	temp_b = board;
	point.set_sign(this->sign);
	play_next_step(temp_b, point);
	fliper.flip(temp_b, point, this->sign);
	//now its the rival turn
	rival_turn = true;
	this->sign = this->rival_sign;
	//check the option moves of the rival player (the human player)
	vector<Point> rival_options = get_possible_moves(temp_b, this->moves_calculator);
	vector<Point>::iterator it;
	//the lowest score the rival(human) can get is 64
	int best_score = -64;
	if (rival_options.size() == 0){
		best_score = temp_b.getCounter().getBlackCount() - temp_b.getCounter().getWhiteCount();
	}
	// for every rival's move, calculate the points he can get.
	//and check which move have the best score
	for (it = rival_options.begin(); it != rival_options.end(); ++it ) {
		Board initial_b = temp_b;
		Point p = *it;
		p.set_sign(this->sign);
		play_next_step(initial_b, p);
		fliper.flip(initial_b, p, p.get_sign());
		//initial_b.pPrint();
		int score = initial_b.getCounter().getBlackCount() - initial_b.getCounter().getWhiteCount();
		if (score > best_score){
			best_score = score;
		}
	}
	this->sign = this->computer_sign;
	this->rival_turn = false;
	return best_score;

}

Point ComputerPlayer::getOpponentLastMove() {
	return this->opponent_last_move;
}

