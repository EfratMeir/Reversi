/*
 * Fliper.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: Efrat Meir
 *      user name: meirefr
 *      ID: 201543253
 */

#include <Fliper.h>
#include <iostream>

Fliper::Fliper() {
//	int i = 0;
//	this->points_to_flip;

}
int Fliper::flip(Board& board, Point chosen_point, char flip_to) {

	this->points_to_flip.erase(this->points_to_flip.begin(), this->points_to_flip.end());
	vector<Point> temp;
	checkAndUpdateDown(chosen_point, board);
	checkAndUpdateUp(chosen_point, board);
	checkAndUpdateRight(chosen_point, board);
	checkAndUpdateLeft(chosen_point, board);
	checkAndUpdateDownRight(chosen_point, board);
	checkAndUpdateDownLeft(chosen_point, board);
	checkAndUpdateUpLeft(chosen_point, board);
	checkAndUpdateUpRight(chosen_point, board);

	for (int i = 0; i < this->points_to_flip.size(); i++) {
		this->points_to_flip[i].set_sign(flip_to);
		board.setPoint(this->points_to_flip[i]);
	}

	int num_fliped = this->points_to_flip.size();
	//the board.setPoint added to the counter everything needed, but fliper needs to distract from the sign-flipped counter:
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

void Fliper::checkAndUpdateUp(Point chosen_point, Board board) {
	char sign = chosen_point.get_sign();
	char opp_sign = FindOpponentSign(sign);
	vector<Point> temp;
//	vector<Point> to_flip;
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
		if (temp.size() > 0) {
		addVecToVec(temp, this->points_to_flip);
		}
	}

}


void Fliper::checkAndUpdateDown(Point chosen_point, Board board) {
	char sign = chosen_point.get_sign();
	char opp_sign = FindOpponentSign(sign);
	vector<Point> temp;
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
		if (temp.size() > 0) {
			addVecToVec(temp, this->points_to_flip);
		}
	}
}

void Fliper::checkAndUpdateRight(Point chosen_point, Board board) {
	char sign = chosen_point.get_sign();
	char opp_sign = FindOpponentSign(sign);
	vector<Point> temp;
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
		if (temp.size() > 0) {
			addVecToVec(temp, this->points_to_flip);
		}
	}
}

void Fliper::checkAndUpdateLeft(Point chosen_point, Board board) {
	char opp_sign = FindOpponentSign(chosen_point.get_sign());
	vector<Point> temp;
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
		if (temp.size() > 0) {
			addVecToVec(temp, this->points_to_flip);
		}
	}
}

void Fliper::checkAndUpdateUpRight(Point chosen_point, Board board) {
	char opp_sign = FindOpponentSign(chosen_point.get_sign());
	vector<Point> temp;
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
		if (temp.size() > 0) {
			addVecToVec(temp, this->points_to_flip);
		}
	}
}

void Fliper::checkAndUpdateUpLeft(Point chosen_point, Board board) {
	char opp_sign = FindOpponentSign(chosen_point.get_sign());
	vector<Point> temp;
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
		if (temp.size() > 0) {
			addVecToVec(temp, this->points_to_flip);
		}
	}
}

void Fliper::checkAndUpdateDownRight(Point chosen_point, Board board) {
	char opp_sign = FindOpponentSign(chosen_point.get_sign());
	vector<Point> temp;
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
		if (temp.size() > 0) {
			addVecToVec(temp, this->points_to_flip);
		}
	}
}

void Fliper::checkAndUpdateDownLeft(Point chosen_point, Board board) {
	char opp_sign = FindOpponentSign(chosen_point.get_sign());
	vector<Point> temp;
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
		if (temp.size() > 0) {
			addVecToVec(temp, this->points_to_flip);
		}
	}
}

void Fliper::addVecToVec(vector<Point> from, vector<Point> &to) {
	for (int i = 0; i < from.size(); i++) {
		to.push_back(from[i]);
	}
}

Fliper::~Fliper() {
	// TODO Auto-generated destructor stub
}

