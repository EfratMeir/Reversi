/*
 * GameFlow.cpp
 *
 *  Created on: Nov 4, 2017
 *      Author: Efrat Meir
 *      user name: meirefr
 *      ID: 201543253
 */

#include <GameFlow.h>

#define SIZE 8
GameFlow::GameFlow() {

}

void GameFlow::initialize() {
	//PointsCounter counter = PointsCounter();
	Board b = Board(8,8);


	//indexes are -1 becauses the array start from 0
	b.parr[4 - 1][4 - 1].set_sign(b.white_player);
	b.parr[5 - 1][5 - 1].set_sign(b.white_player);
	b.parr[4 - 1][5 - 1].set_sign(b.black_player);
	b.parr[5 - 1][4 - 1].set_sign(b.black_player);
	b.getCounter().add(2, 'X');
	b.getCounter().add(2, 'O');

	Player* playerss[2];

	playerss[0] = new HumenPlayer(b, 'X');
	playerss[1] = new HumenPlayer(b, 'O');
//	HumenPlayer black_player = HumenPlayer(b, 'X');
//	HumenPlayer white_player = HumenPlayer(b, 'O');
//	vector <HumenPlayer> players;
//	players.push_back(black_player);
//	players.push_back(white_player);
	this->turn_base = TurnBase(b, playerss);

}

void GameFlow::run() {
	turn_base.play_game();
	cout << "GAME IS OVER!" << endl << "THE WINNER IS: ";
	char winner = findWinner(turn_base);
	if (winner == 'T') {
		cout << "Tie! X & O have the same number of points";
	}
	else{
		cout << winner << endl;
	}
	delete turn_base.get_players()[0];
	delete turn_base.get_players()[1];
}

GameFlow::~GameFlow() {

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

