/*
 * GameFlow.cpp
 *
 *  Created on: Nov 4, 2017
 *      Author: Efrat Meir
 *      user name: meirefr
 *      ID: 201543253
 */

#include "GameFlow.h"

#define SIZE 8
GameFlow::GameFlow() {

}

void GameFlow::initialize() {
	//PointsCounter counter = PointsCounter();
	Board b = Board(8,8);
//	Player *playerss[2];
//	playerss[0] = new HumenPlayer(b, 'X');
//	playerss[1] = new HumenPlayer(b, 'O');
	HumenPlayer black_player = HumenPlayer(b, 'X');
	HumenPlayer white_player = HumenPlayer(b, 'O');
	vector <HumenPlayer> players;
	players.push_back(black_player);
	players.push_back(white_player);
	this->turn_base = TurnBase(b, players);
}

void GameFlow::run() {
	turn_base.play_game();
	cout << "GAME IS OVER!" << endl << "THE WINNER IS: ";
	char winner = findWinner(turn_base);
	if (winner == 'T') {
		cout << "Tie! X & O have the same number of points";
	}
	else{
		cout << winner;
	}

}

GameFlow::~GameFlow() {
	// TODO Auto-generated destructor stub
}

char GameFlow::findWinner(TurnBase turn_base) {
	if (turn_base.getBoard().getCounter().getBlackCount() > turn_base.getBoard().getCounter().getWhiteCount()) {
		return 'X';
	}
	if (turn_base.getBoard().getCounter().getBlackCount() < turn_base.getBoard().getCounter().getWhiteCount()) {
		return 'Y';
	}

	return 'T';
}

