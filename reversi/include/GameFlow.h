/*
 * GameFlow.h
 *
 *  Created on: Nov 4, 2017
 *      Author: Efrat Meir
 *      user name: meirefr
 *      ID: 201543253
 */

#ifndef GAMEFLOW_H_
#define GAMEFLOW_H_
#include <Board.h>
#include <HumenPlayer.h>
#include <ComputerPlayer.h>
#include <Player.h>
#include <TurnBase.h>

#include <vector>

/*
 * initializes the game and mannage it from outside.
 * responsible to start and end the game according to the game logic,
 * declare of the winner.
 */
class GameFlow {
public:
	/*
	 * constructor
	 */
	GameFlow();
	/*
	 * runs the game
	 */
	void run();
	/*
	 * initialize a board, players and turn base
	 */
	void initialize();
	/*
	 * choose the player to play with (computer or human)
	 */
	char choose_players();
	/*
	 * destructor
	 */
	virtual ~GameFlow();

private:
	TurnBase turn_base;

	/*
	 * checks the winner of the game.
	 * @return - the sign of the win player.
	 */
	char findWinner(TurnBase turn_base);
};

#endif /* GAMEFLOW_H_ */
