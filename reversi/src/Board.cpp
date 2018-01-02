/*
 * Board.cpp
 */

#include <Board.h>
#include <Point.h>
#include <iostream>
#include <string.h>
using namespace std;
//#define SIZE 8
#include <vector>

Board::Board() {

}
Board::Board(int board_size) {
	this-> board_size = board_size;
	this->counter = PointsCounter();
	for (int i = 0; i < this->board_size; i++) {
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

bool Board::isFull() {
	int capacity = board_size * board_size;
	return counter.getBlackCount() + counter.getWhiteCount() >= capacity;

}
