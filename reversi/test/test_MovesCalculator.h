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
	b.parr[4 - 1][4 - 1].set_sign(b.white_player);
	b.parr[5 - 1][5 - 1].set_sign(b.white_player);
	b.parr[4 - 1][5 - 1].set_sign(b.black_player);
	b.parr[5 - 1][4 - 1].set_sign(b.black_player);
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


#endif /* TEST_TEST_MOVESCALCULATOR_H_ */
