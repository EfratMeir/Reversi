/*
 * MovesCalculator.cpp
 */

#include <Board.h>
#include <MovesCalculator.h>
#include <iostream>
#include <vector>

using namespace std;

MovesCalculator::MovesCalculator() {
//	int i = 0;
}
/**
 * //check if the move is inside the list of the possible moves.
 */
bool MovesCalculator::allreadyInList(int row, int col) {

	vector<Point>::iterator it;
	//check if the move is inside the list of the possible moves.
	for (it = options_list.begin(); it != options_list.end(); ++it ) {
		Point point = *it;
		if (row == point.get_row()  && col == point.get_col()) {
			return true;
		}
	}
	return false;
}

vector<Point> MovesCalculator::calc_moves(Board board, char this_player_sign) {
//	vector<Point> options_list;
	//initialize the list, erase all the last options
	this->options_list.erase(this->options_list.begin(),
				this->options_list.end());
	for (int i = 0; i < board.getNumCols(); i++) {
		for (int j = 0; j < board.getNumRows(); j++) {
			Point p = board.parr[i][j];
			//if p is the opponent sign - check around her for options:
			if (p.get_sign() != this_player_sign && p.get_sign() != board.blank) {
				checkDown(board, p, this_player_sign, options_list);
				checkUp(board, p, this_player_sign, options_list);
				checkRight(board, p, this_player_sign, options_list);
				checkLeft(board, p, this_player_sign, options_list);
				checkDownLeftDiagonal(board, p, this_player_sign, options_list);
				checkDownRightDiagonal(board, p, this_player_sign, options_list);
				checkUpLeftDiagonal(board, p, this_player_sign, options_list);
				checkUpRightDiagonal(board, p, this_player_sign, options_list);
			}
		}
	}
	return options_list;
}

void MovesCalculator::checkRight(Board board, Point current_point,
		char this_playr_sign, vector<Point>& options) {
	if (current_point.get_sign() != this_playr_sign && current_point.get_sign()
			!= board.blank) {
			int row = current_point.get_row();
			int col = current_point.get_col();
			int i = 1;
			//if the LEFT point from this current point is this player sign -
			//continue to check RIGHT
			if (col - 1 >= 0 && board.parr[row][col - 1].get_sign() == this_playr_sign) {
				//keep moving RIGHT as long as its the opponent sign || board borders
				while (col + i <= board.getNumCols() && board.parr[row][col + i].get_sign() == current_point.get_sign()) {
					i++;
				}
				//if this point is outside the boards, return
				if (!(col + i <= board.getNumCols())){
					return;
				}
				if (board.parr[row][col + i].get_sign() == board.blank) {
					if (!allreadyInList(row, col + i)){
						options.push_back(board.parr[row][col + i]);
					}

				}
			}
		}

}

void MovesCalculator::checkLeft(Board board, Point current_point,
		char this_playr_sign, vector<Point>& options) {
	if (current_point.get_sign() != this_playr_sign && current_point.get_sign() != board.blank) {
		int row = current_point.get_row();
		int col = current_point.get_col();
		int i = 1;
		//if the RIGHT point from this current point is this player sign - continue to check LEFT
		if (col + 1 <= board.getNumCols() && board.parr[row][col + 1].get_sign() == this_playr_sign) {
			//keep moving LEFT as long as its the opponent sign || board borders
			while (col - i >= 0 && board.parr[row][col - i].get_sign() == current_point.get_sign()) {
				i++;
			}
			//if this point is outside the boards, return
			if (!(col - i >= 0 )){
				return;
			}
			if (board.parr[row][col - i].get_sign() == board.blank) {
				if (!allreadyInList(row, col - i)){
					options.push_back(board.parr[row][col - i]);
				}


			}
		}
	}
}

void MovesCalculator::checkDown(Board board, Point current_point,
		char this_playr_sign, vector<Point>& options) {
	if (current_point.get_sign() != this_playr_sign && current_point.get_sign() != board.blank) {
		int row = current_point.get_row();
		int col = current_point.get_col();
		int i = 1;
		//if the UP point from this current point is this player sign - continue to check DOWN
		if (row - 1 >= 0 && board.parr[row - 1][col].get_sign() == this_playr_sign) {
			//keep moving DOWN as long as its the opponent sign || board borders
			while (row + i <= board.getNumRows() && board.parr[row + i][col].get_sign() == current_point.get_sign()) {
				i++;
			}
			//if this point is outside the boards, return
			if (!(row + i <= board.getNumRows())){
				return;
			}
			if (board.parr[row + i][col].get_sign() == board.blank) {
				if (!allreadyInList(row + i, col)){
					options.push_back(board.parr[row + i][col]);
				}
			}
		}
	}
}

void MovesCalculator::checkUp(Board board, Point current_point,
		char this_playr_sign, vector<Point>& options) {

	if (current_point.get_sign() != this_playr_sign && current_point.get_sign() != board.blank) {
		int row = current_point.get_row();
		int col = current_point.get_col();
		int i = 1;
		//if the DOWN point from this current point is this player sign - continue to check UP
		if (row + 1 <= board.getNumRows() && board.parr[row + 1][col].get_sign() == this_playr_sign) {
			//keep moving UP as long as its the opponent sign || board borders
			while (row - i >= 0 && board.parr[row - i][col].get_sign() == current_point.get_sign()) {
				i++;
			}
			//if this point is outside the boards, return
			if (!(row - i >= 0)){
				return;
			}
			if (board.parr[row - i][col].get_sign() == board.blank) {
				if (!allreadyInList(row - i, col)){
					options.push_back(board.parr[row - i][col]);
				}
			}
		}
	}
}

void MovesCalculator::checkUpRightDiagonal(Board board, Point current_point,
		char this_playr_sign, vector<Point>& options) {

	if (current_point.get_sign() != this_playr_sign && current_point.get_sign() != board.blank) {
		int row = current_point.get_row();
		int col = current_point.get_col();
		int i = 1;
		//if the DOWN-LEFT point from this current point is this player sign - continue to check UP-RIGHT
		if (row + 1 <= board.getNumRows() && col - 1 >= 0 && board.parr[row + 1][col - 1].get_sign() == this_playr_sign) {
			//keep moving UP-RIGHT as long as its the opponent sign || board borders
			while (row - i >= 0 && col + i <= board.getNumCols() && board.parr[row - i][col + i].get_sign() == current_point.get_sign()) {
				i++;
			}
			//if this point is outside the boards, return
			if (!(row - i >= 0 && col + i <= board.getNumCols())){
				return;
			}
			if (board.parr[row - i][col + i].get_sign() == board.blank) {
				if (!allreadyInList(row - i, col + i)){
					options.push_back(board.parr[row - i][col + i]);
				}

			}
		}
	}
}

void MovesCalculator::checkUpLeftDiagonal(Board board, Point current_point,
		char this_playr_sign, vector<Point>& options) {

	if (current_point.get_sign() != this_playr_sign && current_point.get_sign() != board.blank) {
		int row = current_point.get_row();
		int col = current_point.get_col();
		int i = 1;
		//if the DOWN-RIGHT point from this current point is this player sign - continue to check UP-LEFT
		if (row + 1 <= board.getNumRows() && col + 1 <= board.getNumCols()
				&& board.parr[row + 1][col + 1].get_sign() == this_playr_sign) {
			//keep moving UP-LEFT as long as its the opponent sign || board borders
			while (row - i >= 0 && col - i >= 0 && board.parr[row - i][col - i].get_sign() == current_point.get_sign()) {
				i++;
			}
			//if this point is outside the boards, return
			if (!(row - i >= 0 && col - i >= 0)){
				return;
			}
			if (board.parr[row - i][col - i].get_sign() == board.blank) {
				if (!allreadyInList(row - i, col - i)){
					options.push_back(board.parr[row - i][col - i]);
				}

			}
		}
	}
}

void MovesCalculator::checkDownRightDiagonal(Board board, Point current_point,
		char this_playr_sign, vector<Point>& options) {

	if (current_point.get_sign() != this_playr_sign && current_point.get_sign() != board.blank) {
		int row = current_point.get_row();
		int col = current_point.get_col();
		int i = 1;
		//if the UP-LEFT point from this current point is this player sign - continue to check DOWN-RIGHT
		if (row - 1 >= 0 && col - 1 >= 0 && board.parr[row - 1][col - 1].get_sign() == this_playr_sign) {
			//keep moving DOWN-RIGHT as long as its the opponent sign || board borders
			while (row + i <= board.getNumRows() && col + i <= board.getNumCols() && board.parr[row + i][col + i].get_sign() == current_point.get_sign()) {
				i++;
			}
			//if this point is outside the boards, return
			if (!(row + i <= board.getNumRows() && col + i <= board.getNumCols() )){
				return;
			}
			if (board.parr[row + i][col + i].get_sign() == board.blank) {
				if (!allreadyInList(row + i, col + i)){
					options.push_back(board.parr[row + i][col + i]);
				}
			}
		}
	}
}



void MovesCalculator::checkDownLeftDiagonal(Board board, Point current_point,
		char this_playr_sign, vector<Point>& options) {

	if (current_point.get_sign() != this_playr_sign && current_point.get_sign() != board.blank) {
		int row = current_point.get_row();
		int col = current_point.get_col();
		int i = 1;
		//if the UP-RIGHT point from this current point is this player sign - continue to check DOWN-LEFT
		if (row - 1 >= 0 && col + 1 <= board.getNumCols() && board.parr[row - 1][col + 1].get_sign() == this_playr_sign) {
			//keep moving DOWN-LEFT as long as its the opponent sign || board borders
			while (row + i <= board.getNumRows() && col - i >= 0 && board.parr[row + i][col - i].get_sign() == current_point.get_sign()) {
				i++;
			}
			//if this point is outside the boards, return
			if (!(row + i <= board.getNumRows() && col - i >= 0)){
				return;
			}
			if (board.parr[row + i][col - i].get_sign() == board.blank) {
				if (!allreadyInList(row + i, col - i)){
					options.push_back(board.parr[row + i][col - i]);
				}

			}
		}
	}

}

MovesCalculator::~MovesCalculator() {
}







