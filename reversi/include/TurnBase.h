/*
 * TurnBase.h
 *
 *  Created on: Nov 6, 2017
 *      Author: Efrat Meir
 *      user name: meirefr
 *      ID: 201543253
 */

#ifndef TURNBASE_H_
#define TURNBASE_H_
#include <Board.h>
#include <ComputerPlayer.h>
#include <Fliper.h>
#include <HumenPlayer.h>
#include <PointsCounter.h>
#include <iostream>
#include <vector>
using namespace std;

/**
 * this class runs the game after its initialized.
 * responsible of the turns and what happens between them.
 */
class TurnBase {
public:
	/**
	 * default constructor
	 */
	TurnBase();

	/**
	 * constructor
	 */
	TurnBase(Board& board, vector<HumenPlayer> players);

	/**
	 * runs the game, connecting between players, board and fliper
	 */
	void play_game();

	// geters and setters:
	Board& getBoard() {
			return board;
		}

	/**
	 * destructor
	 */
	virtual ~TurnBase();

private:
	//class members
	Board board;
	vector<HumenPlayer> players;
	Fliper fliper;
};

#endif /* TURNBASE_H_ */
