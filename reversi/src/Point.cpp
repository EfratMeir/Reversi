/*
 * Point.cpp
 */

#include <Point.h>
#include <iostream>
using namespace std;

Point::Point() {
	this->row = 0;
	this->col = 0;
	this->sign = 'N'; // not initiaized
}
Point::Point(int row, int col, char sign) {
	this->row = row;
	this->col = col;
	this->sign = sign;
}


void Point::printRealValues() {
	cout << "(" << row << "," << col << ")";
}

void Point::printValuesPlusOne() {
	cout << "(" << row + 1 << "," << col + 1 << ")";
}

void Point::printSign() {
	cout << this->sign;
}

int Point::get_row() {
	return this->row;
}

int Point::get_col() {
	return this->col;
}

char Point::get_sign() {
	return this->sign;
}

bool Point::isSamePoint(Point other) {
	if (other.get_row() == row && other.get_col() == col) {
		return true;
	}
	return false;
}

void Point::set_sign(char sign) {
	this->sign = sign;
}
