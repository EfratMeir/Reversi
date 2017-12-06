/*
 * TurnBase.cpp
 */
#include <Player.h>
#include <TurnBase.h>
#include <stdlib.h>
#include "RemotePlayer.h"

TurnBase::TurnBase() {
	this->fliper = Fliper();
}
TurnBase::TurnBase(Board& board, Player** players, bool reomte_game) {
	this->board = board;
	this->players[0] = players[0];
	this->players[1] = players[1];
	this->fliper = Fliper();
	this->remote_game = remote_game;

}

//the remote player always will be player[1]!! and human - player[0]
void TurnBase::play_game() {
	int i = 0;
	cout << "Hello  " << this->players[0]->get_sign() << endl << "Hello  " << players[1]->get_sign() << endl;
	this->board.pPrint();

	while(!board.isFull() && (!(players[0]->get_no_moves() && players[1]->get_no_moves()))) {

		Point chosen_point = players[i]->play_one_turn(board, fliper); //needed any changes here?? after adding remote...
		if (remote_game && i == 0) {
			//its the human player turn - send the chosen point to the server:
		//	(RemotePlayer)players[1]->getConnecter().sendMsg(chosen_point, players[i]->get_no_moves()); //maybe do that in the remote player
		}

		if (board.getCounter().getBlackCount() == 0 || board.getCounter().getWhiteCount() == 0){
			return;
		}
		fliper.flip(board, chosen_point, chosen_point.get_sign());
		this->board.pPrint();
		cout << "black counter:" << board.getCounter().getBlackCount() << endl <<
				"white counter:" << board.getCounter().getWhiteCount() << endl;
		i = i > 0 ? 0 : 1;
	}
}

TurnBase::~TurnBase() {

}


