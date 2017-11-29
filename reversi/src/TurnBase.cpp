/*
 * TurnBase.cpp
 */
#include <Player.h>
#include <TurnBase.h>

TurnBase::TurnBase() {
	this->fliper = Fliper();
}
TurnBase::TurnBase(Board& board, Player** players) {
	this->board = board;
	this->players[0] = players[0];
	this->players[1] = players[1];
	this->fliper = Fliper();
}
void TurnBase::play_game() {
	int i = 0;
	cout << "Hello  " << this->players[0]->get_sign() << endl << "Hello  " << players[1]->get_sign() << endl;
	this->board.pPrint();

	while(!board.isFull() && (!(players[0]->get_no_moves() && players[1]->get_no_moves()))) {

		Point chosen_point = players[i]->play_one_turn(board, fliper);
		if (board.getCounter().getBlackCount() == 0 || board.getCounter().getWhiteCount() == 0){
			return;
		}
		fliper.flip(board, chosen_point, chosen_point.get_sign());
		this->board.pPrint();
		i = i > 0 ? 0 : 1;
	}
}

TurnBase::~TurnBase() {

}

