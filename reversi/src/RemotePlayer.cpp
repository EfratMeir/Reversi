/*
 * RemotePlayer.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: efrat
 */
#include "RemotePlayer.h"
#include <stdlib.h>

RemotePlayer::RemotePlayer() {
	this->sign = 'Y'; //not initialize
	set_sign(); //Remote - not initialized
	this->moves_calculator = MovesCalculator();
	this->has_no_moves = false;
	initializeConnecter();
}

RemotePlayer::RemotePlayer(char sign) {
	this->sign = 'Y'; //not initialize
	set_sign();
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
void RemotePlayer::set_sign(char sign){

}
void RemotePlayer::set_sign(){
	int color_player = this->connecter.reciveColorPlayer();
	if(color_player == 1){
		this->sign = 'O';
	}
	else if(color_player == 2){
		this->sign= 'X';
	}
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
