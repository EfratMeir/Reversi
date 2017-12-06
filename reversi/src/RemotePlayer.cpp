/*
 * RemotePlayer.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: efrat
 */
#include "RemotePlayer.h"
#include <stdlib.h>

RemotePlayer::RemotePlayer() {
	this->sign = 'R'; //Remote - not initialized
	this->has_no_moves = false;
	initializeConnecter();
}

RemotePlayer::RemotePlayer(char sign) {
	this->sign = sign;
	this->moves_calculator = MovesCalculator();
	this->has_no_moves = false;
	initializeConnecter();
}


void RemotePlayer::play_next_step(Board& board, Point chosen_step) {
	board.setPoint(chosen_step);
}

vector<Point> RemotePlayer::get_possible_moves(Board& board,
		MovesCalculator moves_calculator) {
	vector<Point> chosen_move;
	chosen_move.push_back(connecter.recivePoint());
	this->has_no_moves = connecter.reciveNoMoves();
	return chosen_move;
}

Point RemotePlayer::choose_best_move(vector<Point> options_list, Fliper fliper,
		Board& board) {
	return options_list[0];
}

Connecter& RemotePlayer::getConnecter() {
	return this->connecter;
}

int RemotePlayer::initializeConnecter() {
	Connecter connecter("127.0.0.1", 8000);
	this->connecter = connecter;
	try {
		connecter.connectToServer();
	} catch (const char *msg) {
		cout << "Failed to connect to server. Reason: " << msg << endl;
		exit(-1);
	}
	return 0;
}

char RemotePlayer::get_sign() {
	return this->sign;
}

bool RemotePlayer::get_no_moves() {
	return this->has_no_moves;
}

RemotePlayer::~RemotePlayer() {
	// TODO Auto-generated destructor stub
}
