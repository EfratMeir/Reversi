/*
 * Board.cpp
 */

#include "Board.h"
#include <Point.h>
#include <iostream>
#include <string.h>
using namespace std;
#include <vector>

Board::Board() {
	this->board_size = 6;
//	this->num_cols = SIZE;
//	this->num_rows = SIZE;
	this->counter = PointsCounter();
	this->all_players_list = new Point*[this->board_size];

	//points arr:

		for (int i = 0; i < this->board_size; i++) {
			all_players_list[i] = new Point[this->board_size];
			for (int j = 0; j < this->board_size; j++) {
				all_players_list[i][j] = Point(i, j, blank);
			}
		}


}
Board::Board(int board_size) {
	this->board_size = board_size;
//this-> num_rows = rows;
//	this-> num_cols = cols;
	this->counter = PointsCounter();
	this->all_players_list = new Point*[this->board_size];

//points arr:

	for (int i = 0; i < this->board_size; i++) {
		all_players_list[i] = new Point[this->board_size];
		for (int j = 0; j < this->board_size; j++) {
			all_players_list[i][j] = Point(i, j, blank);
		}
	}
}


void Board::setPoint(Point p) {
	int row = p.get_row();
	int col = p.get_col();
	char sign = p.get_sign();
	this->all_players_list[row][col].set_sign(sign);

	if (p.get_sign() == 'X' || p.get_sign() == 'O') {
		this->counter.add_one(sign);
	}
}
Point** Board::getAllPlayers(){
	return all_players_list;
}
bool Board::isFull() {
	int capacity = this->board_size * this->board_size ; //* this->board_size;
	return counter.getBlackCount() + counter.getWhiteCount() >= capacity;

}
