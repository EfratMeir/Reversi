/*
 * Point.h
 *
 *  Created on: Nov 3, 2017
 *      Author: Efrat Meir
 *      user name: meirefr
 *      ID: 201543253
 */

#ifndef POINT_H_
#define POINT_H_
#include <Sprite.h>
#include <iostream>
using namespace std;

class Point {
public:

	/*
	 * default constructor
	 */
	Point();
	/*
	 * constructor
	 */
	Point(int row, int col, char sign);
	// the points values represented on the board + 1, as for the array starts from 0

	/*
	 * prints the point REAL value (array starts from 0)
	 */
	void printRealValues();

	/*
	 * prints the TO-USER values (+1 from the array that start from 0)
	 */
	void printValuesPlusOne();

	/*
	 * checks if 2 points has the same row & col values
	 */
	bool isSamePoint(Point other);
	/*
	 * prints the current sign of the point
	 */
	void printSign();

	//getters and setters:
	char get_sign();
	int get_row();
	int get_col();
	void set_sign(char sign);


private:
	char sign;
	int row;
	int col;
};

#endif /* POINT_H_ */
