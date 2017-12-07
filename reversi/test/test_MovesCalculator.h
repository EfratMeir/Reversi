/*
 * testMovesCalculator.h
 *
 *  Created on: Nov 28, 2017
 *      Author: efrat
 */

#ifndef TEST_TEST_MOVESCALCULATOR_H_
#define TEST_TEST_MOVESCALCULATOR_H_

#include <gtest/gtest.h>
#include "MovesCalculator.h"

class test_MovesCalculator: public testing::Test {
public:
	virtual void setUp() {
		this->moves = MovesCalculator();
		this->b = Board(8,8);
	}
protected:
	MovesCalculator moves;
	Board b;
};

TEST_F(test_MovesCalculator, testCalcMoves) {
	moves.options_list.clear();
	b.setPoint(Point(4 - 1, 4 - 1, 'O'));
	b.setPoint(Point(5 - 1, 5 - 1, 'O'));
	b.setPoint(Point(4 - 1, 5 - 1, 'X'));
	b.setPoint(Point(5 - 1, 4 - 1, 'X'));


	moves.calc_moves(b, 'X');
	EXPECT_EQ(moves.options_list[0].get_row(), (3 - 1));
	EXPECT_EQ(moves.options_list[0].get_col(), (4 - 1));
	EXPECT_EQ(moves.options_list[1].get_row(), (4 - 1));
	EXPECT_EQ(moves.options_list[1].get_col(), (3 - 1));
	EXPECT_EQ(moves.options_list[2].get_row(), (6 - 1));
	EXPECT_EQ(moves.options_list[2].get_col(), (5 - 1));
	EXPECT_EQ(moves.options_list[3].get_row(), (5 - 1));
	EXPECT_EQ(moves.options_list[3].get_col(), (6 - 1));

	moves.options_list.clear();

	moves.calc_moves(b, 'O');
	EXPECT_EQ(moves.options_list[0].get_row(), (3 - 1));
	EXPECT_EQ(moves.options_list[0].get_col(), (5 - 1));
	EXPECT_EQ(moves.options_list[1].get_row(), (4 - 1));
	EXPECT_EQ(moves.options_list[1].get_col(), (6 - 1));
	EXPECT_EQ(moves.options_list[2].get_row(), (6 - 1));
	EXPECT_EQ(moves.options_list[2].get_col(), (4 - 1));
	EXPECT_EQ(moves.options_list[3].get_row(), (5 - 1));
	EXPECT_EQ(moves.options_list[3].get_col(), (3 - 1));
}

TEST_F(test_MovesCalculator, testUpLeftBoarder) {
	moves.options_list.clear();
	Board b = Board(4,4);

	b.setPoint(Point(2 - 1, 2 - 1, 'O'));
	b.setPoint(Point(3 - 1, 3 - 1, 'O'));
	b.setPoint(Point(1 - 1, 1 - 1, 'O'));
	b.setPoint(Point(4 - 1, 4 - 1, 'X'));

	moves.calc_moves(b,'X');
	EXPECT_EQ(moves.options_list.size(), 0);


	moves.options_list.clear();
	b = Board(4,4);

	b.setPoint(Point(2 - 1, 1 - 1, 'O'));
	b.setPoint(Point(3 - 1, 2 - 1, 'O'));
	b.setPoint(Point(4 - 1, 3 - 1, 'X'));


	moves.calc_moves(b,'X');
	EXPECT_EQ(moves.options_list.size(), 0);

}

TEST_F(test_MovesCalculator, testUpRightBoarder) {
	moves.options_list.clear();
	Board b = Board(4,4);

	b.setPoint(Point(2 - 1, 3 - 1, 'X'));
	b.setPoint(Point(1 - 1, 4 - 1, 'O'));

	moves.calc_moves(b,'X');
	EXPECT_EQ(moves.options_list.size(), 0);
	moves.options_list.clear();
	moves.calc_moves(b,'O');
	EXPECT_EQ(moves.options_list.size(), 1);
}

TEST_F(test_MovesCalculator, testDownRightBoarder) {
	moves.options_list.clear();
	Board b = Board(4,4);

	b.setPoint(Point(3 - 1, 3 - 1, 'X'));
	b.setPoint(Point(4 - 1, 3 - 1, 'X'));
	b.setPoint(Point(4 - 1, 4 - 1, 'O'));

	moves.calc_moves(b,'X');
	EXPECT_EQ(moves.options_list.size(), 0);
	moves.options_list.clear();
	moves.calc_moves(b,'O');
	EXPECT_EQ(moves.options_list.size(), 2);
}


TEST_F(test_MovesCalculator, testDownLeftBoarder) {
	moves.options_list.clear();
	Board b = Board(4,4);

	b.setPoint(Point(3 - 1, 2 - 1, 'X'));
	b.setPoint(Point(4 - 1, 2 - 1, 'O'));
	b.setPoint(Point(4 - 1, 1 - 1, 'O'));

	moves.calc_moves(b,'X');
	EXPECT_EQ(moves.options_list.size(), 0);
	moves.options_list.clear();
	moves.calc_moves(b,'O');
	EXPECT_EQ(moves.options_list.size(), 2);
}
#endif /* TEST_TEST_MOVESCALCULATOR_H_ */
