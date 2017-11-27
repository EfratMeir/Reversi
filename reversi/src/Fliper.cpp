/*
 * Fliper.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: Efrat Meir
 *      user name: meirefr
 *      ID: 201543253
 */

#include "Fliper.h"
#include <iostream>

Fliper::Fliper() {
	int i = 0;

}
int Fliper::flip(Board& board, Point chosen_point, char flip_to) {
	vector<Point> to_flip;
	vector<Point> temp;
	temp = checkDown(chosen_point, board);
	if(temp.size() > 0){
		addVecToVec(temp, to_flip);
	}

	temp = checkUp(chosen_point, board);
	if(temp.size() > 0){
		addVecToVec(temp, to_flip);
	}

	temp = checkRight(chosen_point, board);
	if(temp.size() > 0){
		addVecToVec(temp, to_flip);
	}

	temp = checkLeft(chosen_point, board);
	if(temp.size() > 0){
		addVecToVec(temp, to_flip);
	}


	temp = checkDownRight(chosen_point, board);
	if(temp.size() > 0){
		addVecToVec(temp, to_flip);
	}

	temp = checkDownLeft(chosen_point, board);
	if(temp.size() > 0){
		addVecToVec(temp, to_flip);
	}

	temp = checkUpLeft(chosen_point, board);
	if(temp.size() > 0){
		addVecToVec(temp, to_flip);
	}

	temp = checkUpRight(chosen_point, board);
	if(temp.size() > 0){
		addVecToVec(temp, to_flip);
	}


	for (int i = 0; i < to_flip.size(); i++) {
		to_flip[i].set_sign(flip_to);
		board.setPoint(to_flip[i]);

	}
	int num_fliped = to_flip.size();
	board.getCounter().add(num_fliped, flip_to);
	board.getCounter().minus(num_fliped, FindOpponentSign(flip_to));
	cout << "black counter:" << board.getCounter().getBlackCount() << endl <<
			"white counter:" << board.getCounter().getWhiteCount() << endl;

	return num_fliped;

}

char Fliper::FindOpponentSign(char my_sign) {
	char opp_sign;
	if (my_sign == 'X') {
		opp_sign = 'O';
	}
	if (my_sign == 'O') {
		opp_sign = 'X';
	}
	return opp_sign;
}

vector<Point> Fliper::checkUp(Point chosen_point, Board board) {
	char sign = chosen_point.get_sign();
	char opp_sign = FindOpponentSign(sign);
	vector<Point> temp;
	vector<Point> to_flip;
	int row = chosen_point.get_row();
	int col = chosen_point.get_col();
	int i = 1;
	while (true) {
	if (row - i >= 0 && board.parr[row - i][col].get_sign() == opp_sign) {
		temp.push_back(board.parr[row - i][col]);
		i++;
	}
	else
		break;
	}
	if (row - i >=0 && board.parr[row - i][col].get_sign() == sign) {
		to_flip = temp;
	}
	return to_flip;

}


vector<Point> Fliper::checkDown(Point chosen_point, Board board) {
	char sign = chosen_point.get_sign();
	char opp_sign = FindOpponentSign(sign);
	vector<Point> temp;
	vector<Point> to_flip;
	int row = chosen_point.get_row();
	int col = chosen_point.get_col();
	int i = 1;
	while (true) {
	if (row + i <= board.getNumRows() && board.parr[row + i][col].get_sign() == opp_sign) {
		temp.push_back(board.parr[row + i][col]);
		i++;
	}
	else
		break;
		}
	if (row + i <= board.getNumRows() && board.parr[row + i][col].get_sign() == sign) {
		to_flip = temp;
	}
	return to_flip;
}

vector<Point> Fliper::checkRight(Point chosen_point, Board board) {
	char sign = chosen_point.get_sign();
	char opp_sign = FindOpponentSign(sign);
	vector<Point> temp;
	vector<Point> to_flip;
	int row = chosen_point.get_row();
	int col = chosen_point.get_col();
	int i = 1;
	while (true) {
	if (col + i <= board.getNumCols() && board.parr[row][col + i].get_sign() == opp_sign) {
		temp.push_back(board.parr[row][col + i]);
		i++;
	}
	else
		break;
		}
	if (col + i <= board.getNumCols() && board.parr[row][col + i].get_sign() == sign) {
		to_flip = temp;
	}
	return to_flip;
}

vector<Point> Fliper::checkLeft(Point chosen_point, Board board) {
	char opp_sign = FindOpponentSign(chosen_point.get_sign());
	vector<Point> temp;
	vector<Point> to_flip;
	int row = chosen_point.get_row();
	int col = chosen_point.get_col();
	int i = 1;
	while (true) {
	if (col - i >= 0 && board.parr[row][col - i].get_sign() == opp_sign) {
		temp.push_back(board.parr[row][col - i]);
		i++;
	}
	else
		break;
		}
	if (col - i >= 0 && board.parr[row][col - i].get_sign() == chosen_point.get_sign()) {
		to_flip = temp;
	}
	return to_flip;
}

vector<Point> Fliper::checkUpRight(Point chosen_point, Board board) {
	char opp_sign = FindOpponentSign(chosen_point.get_sign());
	vector<Point> temp;
	vector<Point> to_flip;
	int row = chosen_point.get_row();
	int col = chosen_point.get_col();
	int i = 1;
	while (true) {
	if (row - i >= 0 && col + i <= board.getNumCols() && board.parr[row - i][col + i].get_sign() == opp_sign) {
		temp.push_back(board.parr[row - i][col + i]);
		i++;
	}
	else
		break;
		}
	if (row - i >= 0 && col + i <= board.getNumCols()
			&& board.parr[row - i][col + i].get_sign() == chosen_point.get_sign()) {
		to_flip = temp;
	}
	return to_flip;
}

vector<Point> Fliper::checkUpLeft(Point chosen_point, Board board) {
	char opp_sign = FindOpponentSign(chosen_point.get_sign());
	vector<Point> temp;
	vector<Point> to_flip;
	int row = chosen_point.get_row();
	int col = chosen_point.get_col();
	int i = 1;
	while (true) {
	if (row - i >= 0 && col - i >= 0 && board.parr[row - i][col - i].get_sign() == opp_sign) {
		temp.push_back(board.parr[row - i][col - i]);
		i++;
	}
	else
		break;
		}
	if (row - i >= 0 && col - i >= 0 && board.parr[row - i][col - i].get_sign() == chosen_point.get_sign()) {
		to_flip = temp;
	}
	return to_flip;
}

vector<Point> Fliper::checkDownRight(Point chosen_point, Board board) {
	char opp_sign = FindOpponentSign(chosen_point.get_sign());
	vector<Point> temp;
	vector<Point> to_flip;
	int row = chosen_point.get_row();
	int col = chosen_point.get_col();
	int i = 1;
	while (true) {
	if (row + i <= board.getNumRows() && col + i <= board.getNumCols() &&
			board.parr[row + i][col + i].get_sign() == opp_sign) {
		temp.push_back(board.parr[row + i][col + i]);
		i++;
	}
	else
		break;
		}
	if (row + i <= board.getNumRows() && col + i <= board.getNumCols() &&
			board.parr[row + i][col + i].get_sign() == chosen_point.get_sign()) {
		to_flip = temp;
	}
	return to_flip;
}

vector<Point> Fliper::checkDownLeft(Point chosen_point, Board board) {
	char opp_sign = FindOpponentSign(chosen_point.get_sign());
	vector<Point> temp;
	vector<Point> to_flip;
	int row = chosen_point.get_row();
	int col = chosen_point.get_col();
	int i = 1;
	while (true) {
	if (row + i <= board.getNumRows() && col - i >= 0 &&
			board.parr[row + i][col - i].get_sign() == opp_sign) {
		temp.push_back(board.parr[row + i][col - i]);
		i++;
	}
	else
		break;
		}
	if (row + i <= board.getNumRows() && col - i >= 0 &&
			board.parr[row + i][col - i].get_sign() == chosen_point.get_sign()) {
		to_flip = temp;
	}
	return to_flip;

}

void Fliper::addVecToVec(vector<Point> from, vector<Point> &to) {
	for (int i = 0; i < from.size(); i++) {
		to.push_back(from[i]);
	}

}

Fliper::~Fliper() {
	// TODO Auto-generated destructor stub
}

