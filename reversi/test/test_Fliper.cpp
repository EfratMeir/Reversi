/*
 * test_Fliper.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: efrat
 */

#include "Fliper.h"
#include "gtest/gtest.h"


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

TEST(FliperTest, testCheckRight) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	Fliper f;
	f.flip(b, Point(5 - 1, 6 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[5 - 1][5 - 1].get_sign() == 'X');
}

TEST(FliperTest, testCheckLeft) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	Fliper f;
	f.flip(b, Point(4 - 1, 3 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[4 - 1][4 - 1].get_sign() == 'X');
}

TEST(FliperTest, testCheckUp) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	Fliper f;
	f.flip(b, Point(3 - 1, 4 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[4 - 1][4 - 1].get_sign() == 'X');
}

TEST(FliperTest, testCheckDown) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	Fliper f;
	f.flip(b, Point(6 - 1, 5 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[5 - 1][5 - 1].get_sign() == 'X');
}

TEST(FliperTest, testCheckUpRight) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	b.setPoint(Point(6 - 1, 4 - 1, 'X'));
	Fliper f;
	f.flip(b, Point(4 - 1, 6 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[5 - 1][5 - 1].get_sign() == 'X');
}

TEST(FliperTest, testCheckUpLeft) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	b.setPoint(Point(6 - 1, 6 - 1, 'X'));
	Fliper f;
	f.flip(b, Point(3 - 1, 3 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[5 - 1][5 - 1].get_sign() == 'X');
	EXPECT_TRUE(b.parr[4 - 1][4 - 1].get_sign() == 'X');
}

TEST(FliperTest, testCheckDownRight) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	b.setPoint(Point(3 - 1, 3 - 1, 'X'));
	Fliper f;
	f.flip(b, Point(6 - 1, 6 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[5 - 1][5 - 1].get_sign() == 'X');
	EXPECT_TRUE(b.parr[4 - 1][4 - 1].get_sign() == 'X');
}

TEST(FliperTest, testCheckDownLeft) {
	Board b = Board(8,8);
	initializeMiddlePoints8X8(b);
	b.setPoint(Point(4 - 1, 6 - 1, 'X'));
	Fliper f;
	f.flip(b, Point(6 - 1, 4 - 1, 'X'), 'X');
	EXPECT_TRUE(b.parr[5 - 1][5 - 1].get_sign() == 'X');
}

TEST(FliperTest, testNotFlipingWhenNotNeeded_UpLeft) {
	Fliper f;
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	b.setPoint(Point(1 - 1, 1 - 1, 'O'));
	f.flip(b, Point(4 - 1, 4 - 1, 'X'), 'X');
	EXPECT_FALSE(b.parr[3 - 1][3 - 1].get_sign() == 'X');
	EXPECT_FALSE(b.parr[2 - 1][2 - 1].get_sign() == 'X');
	EXPECT_FALSE(b.parr[1 - 1][1 - 1].get_sign() == 'X');
}

TEST(FliperTest, testNotFlipingWhenNotNeeded_UpRight) {
	Fliper f;
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	b.setPoint(Point(2 - 1, 4 - 1, 'O'));
	f.flip(b, Point(4 - 1, 2 - 1, 'X'), 'X');
	EXPECT_FALSE(b.parr[3 - 1][3 - 1].get_sign() == 'X');
	EXPECT_FALSE(b.parr[2 - 1][4 - 1].get_sign() == 'X');
}

TEST(FliperTest, testNotFlipingWhenNotNeeded_DownLeft) {
	Fliper f;
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	b.setPoint(Point(4 - 1, 1 - 1, 'X'));
	f.flip(b, Point(1 - 1, 4 - 1, 'O'), 'O');
	EXPECT_FALSE(b.parr[2 - 1][3 - 1].get_sign() == 'O');
	EXPECT_FALSE(b.parr[3 - 1][2 - 1].get_sign() == 'O');
	EXPECT_FALSE(b.parr[4 - 1][1 - 1].get_sign() == 'O');
}

TEST(FliperTest, testNotFlipingWhenNotNeeded_DownRight) {
	Fliper f;
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	b.setPoint(Point(4 - 1, 4 - 1, 'O'));
	f.flip(b, Point(1 - 1, 1 - 1, 'X'), 'X');
	EXPECT_FALSE(b.parr[2 - 1][2 - 1].get_sign() == 'X');
	EXPECT_FALSE(b.parr[3 - 1][3 - 1].get_sign() == 'X');
	EXPECT_FALSE(b.parr[4 - 1][4 - 1].get_sign() == 'X');
}

TEST(FliperTest, testNotFlipingWhenNotNeeded_Down) {
	Fliper f;
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	f.flip(b, Point(1 - 1, 3 - 1, 'X'), 'X');
	EXPECT_FALSE(b.parr[2 - 1][3 - 1].get_sign() == 'O');
	EXPECT_FALSE(b.parr[3 - 1][3 - 1].get_sign() == 'X');
}

TEST(FliperTest, testNotFlipingWhenNotNeeded_Up) {
	Fliper f;
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	b.setPoint(Point(1 - 1, 2 - 1, 'O'));
	f.flip(b, Point(4 - 1, 2 - 1, 'X'), 'X');
	EXPECT_FALSE(b.parr[2 - 1][2 - 1].get_sign() == 'X');
	EXPECT_FALSE(b.parr[1 - 1][2 - 1].get_sign() == 'X');
}

TEST(FliperTest, testNotFlipingWhenNotNeeded_Right) {
	Fliper f;
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	b.setPoint(Point(3 - 1, 4 - 1, 'O'));
	f.flip(b, Point(3 - 1, 2 - 1, 'X'), 'X');
	EXPECT_FALSE(b.parr[3 - 1][3 - 1].get_sign() == 'X');
	EXPECT_FALSE(b.parr[3 - 1][4 - 1].get_sign() == 'X');
}

TEST(FliperTest, testNotFlipingWhenNotNeeded_Left) {
	Fliper f;
	Board b = Board(4,4);
	initializeMiddlePoints4X4(b);
	b.setPoint(Point(3 - 1, 1 - 1, 'X'));
	f.flip(b, Point(3 - 1, 4 - 1, 'O'), 'O');
	EXPECT_FALSE(b.parr[3 - 1][1 - 1].get_sign() == 'O');
	EXPECT_FALSE(b.parr[3 - 1][2 - 1].get_sign() == 'O');
	EXPECT_FALSE(b.parr[3 - 1][3 - 1].get_sign() == 'X');

}

