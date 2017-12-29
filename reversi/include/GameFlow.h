/*
 * GameFlow.h
 */

#ifndef GAMEFLOW_H_
#define GAMEFLOW_H_
#include "Console.h"

#include "Board.h"
#include "HumenPlayer.h"
#include "ComputerPlayer.h"
#include "Player.h"
#include "TurnBase.h"
#include "Connecter.h"
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
	void initialize(Board& b, Console& c);
	/*
	 * choose the player to play with (computer or human)
	 */
	char choose_players();
	/*
	 * destructor
	 */
	void startRemoteGame(Player* players[2],Board& b, Console& console);
	char* enterCommand(Console& console, Connecter& connecter);

	virtual ~GameFlow();

private:
	TurnBase turn_base;
	/*
	 * checks the winner of the game.
	 * @return - the sign of the win player.
	 */
	char findWinner(TurnBase& turn_base);
	/**
	 * converts string to int
	 * @param str the string
	 * @return the int
	 */
	int convertStringToInt(string str);
	/**
	 * converst string to char*
	 * @param str the string
	 * @return the char*
	 */
	const char* convertStringToChar(string str);
	/**
	 * read a word in a file and return the word after it.
	 * @param word the word
	 * @return the word after it
	 */
	string readFromFile(string word);
	/**
	 * initialize the connecter
	 * @param connecter
	 * @return
	 */
	int initializeConnecter(Connecter& connecter);
};

#endif /* GAMEFLOW_H_ */
