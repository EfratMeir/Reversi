/*
 * testFliper.h
 *
 *  Created on: Nov 29, 2017
 *      Author: efrat
 */

#ifndef TEST_TEST_FLIPER_H_
#define TEST_TEST_FLIPER_H_
#include "Fliper.h"
#include <gtest/gtest.h>


class test_Fliper: public testing::Test {
public:
	virtual void setUp() {
		this->f = Fliper();
	}

	void initializeMiddlePoints8X8(Board& b) {
		Point p1(4 - 1,4 - 1, 'O'), p2(5 -1, 5 -1, 'O');
		Point p3(5 - 1, 4 - 1, 'X'), p4(4 - 1, 5 - 1, 'X');
		b.setPoint(p1);
		b.setPoint(p2);
		b.setPoint(p3);
		b.setPoint(p4);
	}

	void initializeMiddlePoints4X4(Board& b) {
		Point p1(2 - 1,2 - 1, 'O'), p2(3 -1, 3 -1, 'O');
		Point p3(3 - 1, 2 - 1, 'X'), p4(2 - 1, 3 - 1, 'X');
		b.setPoint(p1);
		b.setPoint(p2);
		b.setPoint(p3);
		b.setPoint(p4);
	}
protected:
	Fliper f;
};

TEST_F(test_Fliper, testitest) {
	EXPECT_EQ(3,3);
}


TEST_F(test_Fliper, testCheckRight) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	f.flip(b, Point(5 - 1, 6 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[5 - 1][5 - 1].get_sign() == 'X');
}

TEST_F(test_Fliper, testCheckLeft) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	f.flip(b, Point(4 - 1, 3 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[4 - 1][4 - 1].get_sign() == 'X');
}

TEST_F(test_Fliper, testCheckUp) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	f.flip(b, Point(3 - 1, 4 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[4 - 1][4 - 1].get_sign() == 'X');
}

TEST_F(test_Fliper, testCheckDown) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	f.flip(b, Point(6 - 1, 5 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[5 - 1][5 - 1].get_sign() == 'X');
}

TEST_F(test_Fliper, testCheckUpRight) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	b.setPoint(Point(6 - 1, 4 - 1, 'X'));
	f.flip(b, Point(4 - 1, 6 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[5 - 1][5 - 1].get_sign() == 'X');
}

TEST_F(test_Fliper, testCheckUpLeft) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	b.setPoint(Point(6 - 1, 6 - 1, 'X'));
	f.flip(b, Point(3 - 1, 3 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[5 - 1][5 - 1].get_sign() == 'X');
	EXPECT_TRUE(b.parr[4 - 1][4 - 1].get_sign() == 'X');
}

TEST_F(test_Fliper, testCheckDownRight) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	b.setPoint(Point(3 - 1, 3 - 1, 'X'));
	f.flip(b, Point(6 - 1, 6 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[5 - 1][5 - 1].get_sign() == 'X');
	EXPECT_TRUE(b.parr[4 - 1][4 - 1].get_sign() == 'X');
}

TEST_F(test_Fliper, testCheckDownLeft) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	b.setPoint(Point(4 - 1, 6 - 1, 'X'));
	f.flip(b, Point(6 - 1, 4 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[5 - 1][5 - 1].get_sign() == 'X');
}

TEST_F(test_Fliper, testNotFlipingWhenNotNeeded_UpLeft) {
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	b.setPoint(Point(1 - 1, 1 - 1, 'O'));
	f.flip(b, Point(4 - 1, 4 - 1, 'X'), 'X');
	EXPECT_FALSE(b.parr[3 - 1][3 - 1].get_sign() == 'X');
	EXPECT_FALSE(b.parr[2 - 1][2 - 1].get_sign() == 'X');
	EXPECT_FALSE(b.parr[1 - 1][1 - 1].get_sign() == 'X');
}

TEST_F(test_Fliper, testNotFlipingWhenNotNeeded_UpRight) {
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	b.setPoint(Point(2 - 1, 4 - 1, 'O'));
	f.flip(b, Point(4 - 1, 2 - 1, 'X'), 'X');
	EXPECT_FALSE(b.parr[3 - 1][3 - 1].get_sign() == 'X');
	EXPECT_FALSE(b.parr[2 - 1][4 - 1].get_sign() == 'X');
}

TEST_F(test_Fliper, testNotFlipingWhenNotNeeded_DownLeft) {
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	b.setPoint(Point(4 - 1, 1 - 1, 'X'));
	f.flip(b, Point(1 - 1, 4 - 1, 'O'), 'O');
	EXPECT_FALSE(b.parr[2 - 1][3 - 1].get_sign() == 'O');
	EXPECT_FALSE(b.parr[3 - 1][2 - 1].get_sign() == 'O');
	EXPECT_FALSE(b.parr[4 - 1][1 - 1].get_sign() == 'O');
}

TEST_F(test_Fliper, testNotFlipingWhenNotNeeded_DownRight) {
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	b.setPoint(Point(4 - 1, 4 - 1, 'O'));
	f.flip(b, Point(1 - 1, 1 - 1, 'X'), 'X');
	EXPECT_FALSE(b.parr[2 - 1][2 - 1].get_sign() == 'X');
	EXPECT_FALSE(b.parr[3 - 1][3 - 1].get_sign() == 'X');
	EXPECT_FALSE(b.parr[4 - 1][4 - 1].get_sign() == 'X');
}

TEST_F(test_Fliper, testNotFlipingWhenNotNeeded_Down) {
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	f.flip(b, Point(1 - 1, 3 - 1, 'X'), 'X');
	EXPECT_FALSE(b.parr[2 - 1][3 - 1].get_sign() == 'O');
	EXPECT_FALSE(b.parr[3 - 1][3 - 1].get_sign() == 'X');
}

TEST_F(test_Fliper, testNotFlipingWhenNotNeeded_Up) {
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	b.setPoint(Point(1 - 1, 2 - 1, 'O'));
	f.flip(b, Point(4 - 1, 2 - 1, 'X'), 'X');
	EXPECT_FALSE(b.parr[2 - 1][2 - 1].get_sign() == 'X');
	EXPECT_FALSE(b.parr[1 - 1][2 - 1].get_sign() == 'X');
}

TEST_F(test_Fliper, testNotFlipingWhenNotNeeded_Right) {
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	b.setPoint(Point(3 - 1, 4 - 1, 'O'));
	f.flip(b, Point(3 - 1, 2 - 1, 'X'), 'X');
	EXPECT_FALSE(b.parr[3 - 1][3 - 1].get_sign() == 'X');
	EXPECT_FALSE(b.parr[3 - 1][4 - 1].get_sign() == 'X');
}

TEST_F(test_Fliper, testNotFlipingWhenNotNeeded_Left) {
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	b.setPoint(Point(3 - 1, 1 - 1, 'X'));
	f.flip(b, Point(3 - 1, 4 - 1, 'O'), 'O');
	EXPECT_FALSE(b.parr[3 - 1][1 - 1].get_sign() == 'O');
	EXPECT_FALSE(b.parr[3 - 1][2 - 1].get_sign() == 'O');
	EXPECT_FALSE(b.parr[3 - 1][3 - 1].get_sign() == 'X');

}

TEST_F(test_Fliper, checkFliperUpdatesPointsCounter) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	EXPECT_EQ(b.getCounter().getBlackCount(), 2);
	f.flip(b, Point(3 - 1, 4 - 1, 'X'), 'X');
	//the chosen point will be added by the board:
	EXPECT_EQ(b.getCounter().getBlackCount(), 3);
	EXPECT_EQ(b.getCounter().getWhiteCount(), 1);
}
#endif /* TEST_TEST_FLIPER_H_ */
