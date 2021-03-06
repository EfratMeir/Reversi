/*
 * TurnBase.h
 */

#ifndef TURNBASE_H_
#define TURNBASE_H_
#include <Board.h>
#include "Console.h"
#include <ComputerPlayer.h>
#include <Fliper.h>
#include <HumenPlayer.h>
#include <PointsCounter.h>
#include <iostream>
#include <vector>
#include "Connecter.h"
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
	TurnBase(Board& board, Player** players, bool is_remote_game, Connecter& connecter, Console& console);
	TurnBase(Board& board, Player** players, bool is_remote_game, Console& console);

	/**
	 * runs the game, connecting between players, board and fliper
	 */
	void play_game();

	// geters and setters:
	Board& getBoard() {
			return board;
		}
	Console& getConsole(){
		return this->console;
	}
	Player** get_players(){
		return players;
	}

	/**
	 * destructor
	 */
	virtual ~TurnBase();
private:
	//class members
	Connecter connecter;
	Board board;
	Console console;
	Player* players[2];
	Fliper fliper;

	bool remote_game;
};

#endif /* TURNBASE_H_ */
