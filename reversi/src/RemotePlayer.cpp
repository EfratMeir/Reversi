/*
 * RemotePlayer.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: efrat
 */
#include "RemotePlayer.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
RemotePlayer::RemotePlayer(Connecter& connecter, char sign) {


	this->connecter = connecter;
	this->sign = sign; //not initialize
	this->moves_calculator = MovesCalculator();
	this->has_no_moves = false;
	//this->opponent_last_move = Point(0, 0,' ');
	//must initialize for the first move. this is ok because this spot allways empty in the first move...
	this->my_first_move = true;
	this->opponent_has_no_move = false;

}

void RemotePlayer::play_next_step(Board& board, Point& chosen_step, Console& console) {
	int row = chosen_step.get_row();
	int col = chosen_step.get_col();
	board.setPoint(Point(row,col, chosen_step.get_sign()));
	cout << this->get_sign() << " chose to play: ";
	chosen_step.printValuesPlusOne();
	cout << endl;
	console.printBoard(board);
	cout << endl;
}

vector<Point> RemotePlayer::get_possible_moves(Board& board,
		MovesCalculator& moves_calculator) {
	if(!my_first_move || this->sign == 'O') { //MYABE X
		connecter.sendMsg(this->opponent_last_move, opponent_has_no_move);
	}
	my_first_move = false;
	vector<Point> chosen_move;
	chosen_move.clear();
	Point chosen = connecter.receivePoint();
	chosen.set_sign(this->get_sign());
	chosen_move.push_back(chosen);
	this->has_no_moves = connecter.receiveNoMoves();
	return chosen_move;
}

Point RemotePlayer::choose_best_move(vector<Point> options_list, Fliper& fliper,
		Board& board, Console& console) {
	return options_list[0];
}

Connecter& RemotePlayer::getConnecter() {
	return this->connecter;
}

void RemotePlayer::setOpponentHasNoMoves(bool opp_has_no_moves) {
	this->opponent_has_no_move = opp_has_no_moves;
}


void RemotePlayer::set_sign(char sign){

}
void RemotePlayer::set_sign(){
	int color_player = this->getConnecter().receiveNumPlayer();
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

Point RemotePlayer::getOpponentLastMove() {
	return this->opponent_last_move;
}

void RemotePlayer::setOpponentLastMove(Point& opponent_last_move) {
	int row = opponent_last_move.get_row();
	int col = opponent_last_move.get_col();
	Point p = Point(row,col, opponent_last_move.get_sign());
	this->opponent_last_move = p;
}
RemotePlayer::~RemotePlayer() {
	// TODO Auto-generated destructor stub
}
