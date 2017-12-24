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
	this->board_size = 8; //Default size
	this->counter = PointsCounter();
	this->all_players_list = 0;
}
Board::Board(int board_size) {
	this->board_size = board_size;
	this->counter = PointsCounter();
	this->all_players_list = new Point*[this->board_size];
	for (int i = 0; i < this->board_size; i++) {
		all_players_list[i] = new Point[this->board_size];
		for (int j = 0; j < this->board_size; j++) {
			all_players_list[i][j] = Point(i, j, blank);
		}
	}
}

void Board::deleteBoard(){
	for (int i = 0; i < this->board_size; i++) {
		delete[] all_players_list[i];
	}
	delete[] all_players_list;
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
