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

	Player* players[2];
	players[0] = new HumenPlayer('X');
	char chosen_player = choose_players();
	if (chosen_player == 'c' || chosen_player == 'C'){
		players[1] = new ComputerPlayer('O');
	}
	else{ //if chosen player is human player
	players[1] = new HumenPlayer('O');
	}
	this->turn_base = TurnBase(b, players);

}
char GameFlow::choose_players(){
	cout << "to play against the computer type 'c'" << endl << "to play against human player type 'h'" << endl;
	char chosen;
	cin >> chosen;
	if (!(chosen == 'c' || chosen == 'C' || chosen == 'h' || chosen == 'H')){
		cout << "you entered an invalid char." <<endl;
		choose_players();
	}
	return chosen;
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
		return 'O';
	}
	return 'T';
}

