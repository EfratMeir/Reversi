/*
 * test_board.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: efrat
 */

#include "Board.h"
#include "gtest/gtest.h"



TEST(BoardTest, checkFull) {
	int size = 8;
	Board b = Board(size, size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			b.setPoint(Point(i,j, 'X'));
			b.getCounter().add_one('X');
		}
	}
	EXPECT_TRUE(b.isFull());

	b.getCounter().minus_one('X');
	EXPECT_FALSE(b.isFull());

	b.getCounter().add(5, 'O');
	EXPECT_TRUE(b.isFull());

}

