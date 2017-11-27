/*
 * Board.cpp
 *
 *  Created on: Oct 28, 2017
 *      Author: Efrat Meir
 *      user name meirefr
 *      ID 201543253
 */

#include <Board.h>
#include <Point.h>
#include <iostream>
using namespace std;
#define SIZE 8
#include <vector>

Board::Board() {
	this->num_cols = SIZE;
	this->num_rows = SIZE;
	this->counter = PointsCounter();


//points arr:

	for (int i = 0; i < this->num_cols; i++) {
		for (int j = 0; j < this->num_rows; j++) {
			parr[i][j] = Point(i, j, blank);
		}
	}


}
Board::Board(int rows, int cols) {

	this-> num_rows = rows;
	this-> num_cols = cols;
	this->counter = PointsCounter();


//points arr:

	for (int i = 0; i < this->num_cols; i++) {
		for (int j = 0; j < this->num_rows; j++) {
			parr[i][j] = Point(i, j, blank);
		}
	}


}



void Board::pPrint() {
	// i - index for rows
	// j - index for columns
	cout << " | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |" << endl
			<< "----------------------------------" << endl;
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE + 1; j++) {  //size + 1 because  of the rows indexes
					if (j == 0) {
						cout << i + 1;
					}
					if (j == SIZE) {
						cout << "| " << endl <<
								"----------------------------------" << endl;
					}
					else {
						cout << "| " << parr[i][j].get_sign() << " ";
					}
				}
			}
}



void Board::setPoint(Point p) {
	int row = p.get_row();
	int col = p.get_col();
	char sign = p.get_sign();

	this->parr[row][col].set_sign(sign);
}

bool Board::isFull() {
	int capacity = num_cols * num_rows;
	if (counter.getBlackCount() + counter.getWhiteCount() >= capacity) {
		return true;
	}
	return false;
}
