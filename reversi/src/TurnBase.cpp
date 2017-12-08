/*
 * TurnBase.cpp
 */
#include <Player.h>
#include <TurnBase.h>
#include <stdlib.h>
#include "RemotePlayer.h"

TurnBase::TurnBase() {
	this->fliper = Fliper();
	this->remote_game = false;
}
TurnBase::TurnBase(Board& board, Player** players, bool is_reomte_game) {
	this->board = board;
	this->players[0] = players[0];
	this->players[1] = players[1];
	this->fliper = Fliper();
	this->remote_game = is_reomte_game;

}

//the remote player always will be player[1]!! and human - player[0]
void TurnBase::play_game() {
	int i = 0;
	int j = 1;
	cout << "Hello  " << this->players[0]->get_sign() << endl << "Hello  " << players[1]->get_sign() << endl;
	this->board.pPrint();


	while(!board.isFull() && (!(players[0]->get_no_moves() && players[1]->get_no_moves()))) {
		Point chosen_point = players[i]->play_one_turn(board, fliper); //needed any changes here?? after adding remote...
		if (remote_game) {
			//update the other player about what the human played:
			players[j]->setOpponentLastMove(chosen_point);
		}
		if (board.getCounter().getBlackCount() == 0 || board.getCounter().getWhiteCount() == 0){
			return;
		}
		fliper.flip(board, chosen_point, chosen_point.get_sign());
		this->board.pPrint();
		cout << "black counter:" << board.getCounter().getBlackCount() << endl <<
				"white counter:" << board.getCounter().getWhiteCount() << endl;
		i = i > 0 ? 0 : 1;
		j = j > 0 ? 0 : 1;
	}
}

TurnBase::~TurnBase() {

}


