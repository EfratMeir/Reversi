/*
 * test_board.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: efrat
 */

#include "Board.h"
#include "gtest/gtest.h"


	int size = 8;
	Board b = Board(size, size);
TEST(BoardTest, checkIsFull) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			b.setPoint(Point(i,j, 'X'));
		}
	}
	EXPECT_TRUE(b.isFull());

	b.getCounter().minus_one('X');
	EXPECT_FALSE(b.isFull());

	b.getCounter().add(5, 'O');
	EXPECT_TRUE(b.isFull());

}

TEST(BoardTest, counterUpdatedWhenSetPoint) {
	int size = 8;
	Board b = Board(size, size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			b.setPoint(Point(i,j, 'X'));
		}
	}
	EXPECT_EQ(b.getCounter().getBlackCount(), size*size);
}
