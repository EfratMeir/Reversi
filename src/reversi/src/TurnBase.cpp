/*
 * TurnBase.cpp
 */
#include <Player.h>
#include <TurnBase.h>
#include <stdlib.h>
#include "RemotePlayer.h"
#include "Connecter.h"

TurnBase::TurnBase() {
	this->fliper = Fliper();
	this->remote_game = false;
}
TurnBase::TurnBase(Board& board, Player** players, bool is_reomte_game, Console& console) {
	this->board = board;
	this->players[0] = players[0];
	this->players[1] = players[1];
	this->fliper = Fliper();
	this->remote_game = is_reomte_game;
	this-> console = console;

}
TurnBase::TurnBase(Board& board, Player** players, bool is_reomte_game, Connecter &connecter, Console& console) {
	this->board = board;
	this->players[0] = players[0];
	this->players[1] = players[1];
	this->fliper = Fliper();
	this->remote_game = is_reomte_game;
	this->connecter = connecter;
	this-> console = console;

}

void TurnBase::play_game() {
	int i = 0;
	int j = 1;

	cout << "this is the initial board:" << endl;
	//this->board.pPrint();
	this->console.printBoard();
	while(!board.isFull() && (!(players[0]->get_no_moves() && players[1]->get_no_moves()))) {
		this->console.printNowTurn( players[i]->get_sign());
		//cout << "its " << players[i]->get_sign() << "'s turn." << endl;
		Point chosen_point = players[i]->play_one_turn(board, fliper, this->console); //needed any changes here?? after adding remote...
		if (remote_game) {
			//update the other player about what the human played:
			players[j]->setOpponentLastMove(chosen_point);
		}
		if (board.getCounter().getBlackCount() == 0 || board.getCounter().getWhiteCount() == 0){
			this->connecter.sendPoint(Point(-1,-1,' ')); //send no point
			this->connecter.sendNoMoves(1);
			return;
		}
		fliper.flip(board, chosen_point, chosen_point.get_sign());
		this->console.printBoard();
		this->console.printCounter(board.getCounter());
	//	this->board.pPrint();
//		cout << "black counter:" << board.getCounter().getBlackCount() << endl <<
//				"white counter:" << board.getCounter().getWhiteCount() << endl;
		i = i > 0 ? 0 : 1;
		j = j > 0 ? 0 : 1;
	}
	if (this->remote_game){
		this->connecter.sendPoint(Point(-1,-1,' '));
		this->connecter.sendNoMoves(true);

	}
}
TurnBase::~TurnBase() {

}


