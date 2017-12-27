/*
 * test_ComputerPlayer.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: efrat
 */

#include "ComputerPlayer.h"
#include "gtest/gtest.h"
#include <vector>

TEST(testComputerPlayer, testChooseRate) {
	Board b = Board(8);
	ComputerPlayer c = ComputerPlayer('O');
	Console console = Console();
	b.setPoint(Point(3 - 1, 4 - 1, 'X'));
	b.setPoint(Point(4 - 1, 4 - 1, 'X'));
	b.setPoint(Point(5 - 1, 4 - 1, 'X'));
	b.setPoint(Point(4 - 1, 5 - 1, 'X'));
	b.setPoint(Point(5 - 1, 5 - 1, 'O'));

//	Fliper f = Fliper();
//	int rate = c.rate_move(Point(3 - 1, 3 - 1, 'O'), f , b, console);
//
//	EXPECT_EQ(rate, 3);

}

TEST(testComputerPlayer, testPlayOneTurn) {
	Board b = Board(8);
	Console console = Console();
	ComputerPlayer c = ComputerPlayer('O');

	b.setPoint(Point(3 - 1, 4 - 1, 'X'));
	b.setPoint(Point(4 - 1, 4 - 1, 'X'));
	b.setPoint(Point(5 - 1, 4 - 1, 'X'));
	b.setPoint(Point(4 - 1, 5 - 1, 'X'));
	b.setPoint(Point(5 - 1, 5 - 1, 'O'));

	Fliper f = Fliper();

	c.play_one_turn(b, f, console);
	EXPECT_EQ(b.all_players_list[3 - 1][3 - 1].get_sign(), 'O');
}

