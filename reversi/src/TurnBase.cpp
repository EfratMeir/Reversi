/*
 * TurnBase.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: Efrat Meir
 *      user name: meirefr
 *      ID: 201543253
 */
#include <Player.h>
#include <TurnBase.h>

TurnBase::TurnBase() {
	//this->players;
	this->fliper = Fliper();
}

TurnBase::TurnBase(Board& board, vector<HumenPlayer> players) {
	this->board = board;
	this->players = players;
	if (players.size() != 2) {
		cout << "invalid number of players. expected 2 players (humen or Computer)";
	}
	this->fliper = Fliper();
}

void TurnBase::play_game() {
	int i = 0;
	cout << "Hello  " << players[0].get_sign() << endl << "Hello  " << players[1].get_sign() << endl;
	this->board.pPrint();

	while (!board.isFull() && !(players[0].no_moves && players[1].no_moves)) {
		Point chosen_point;
		if (chosen_point.get_row() >= 0) {
			chosen_point = players[i].play_one_turn(board);
			fliper.flip(board, chosen_point, chosen_point.get_sign());
			this->board.pPrint();
			i = i>0?0:1;
	}
	}



}



TurnBase::~TurnBase() {
	// TODO Auto-generated destructor stub
}

