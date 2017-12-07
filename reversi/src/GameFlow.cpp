/*
 * GameFlow.cpp
 */

#include <GameFlow.h>
#include "RemotePlayer.h"
#define SIZE 8
GameFlow::GameFlow() {

}

void GameFlow::initialize() {
	//PointsCounter counter = PointsCounter();
	Board b = Board(8,8);


//	indexes are -1 because the array start from 0
	b.setPoint(Point(4 - 1, 4 - 1, b.white_player));
	b.setPoint(Point(5 - 1, 5 - 1, b.white_player));
	b.setPoint(Point(4 - 1, 5 - 1, b.black_player));
	b.setPoint(Point(5 - 1, 4 - 1, b.black_player));

	bool is_remote_game = false;
	Player* players[2];
	players[0] = new HumenPlayer('X');
	char chosen_player = choose_players();
	if (chosen_player == 'c' || chosen_player == 'C'){
		players[1] = new ComputerPlayer('O');
	}
	if (chosen_player == 'r' || chosen_player == 'R'){
		players[1] = new RemotePlayer('O'); // I HAVE NOT DELETED YET!!!! DO NOT FORGET
		is_remote_game = true;
	}
	else{
	//chosen player is a human player
	players[1] = new HumenPlayer('O');
	}
	this->turn_base = TurnBase(b, players, is_remote_game);

}
char GameFlow::choose_players(){
	cout << "Welcome to reversi!" << endl << "choose an opponent type: " << endl << endl;

	cout << "to play against the computer type 'c'" << endl <<
			"to play against human player type 'h'" << endl <<
			"to play against a remote player type 'r'" << endl;
	char chosen;
	cin >> chosen;
	if (!(chosen == 'c' || chosen == 'C' || chosen == 'h'
			|| chosen == 'H' || chosen == 'r' || chosen == 'R')){
		cout << "you have entered an invalid char." <<endl;
		chosen = choose_players();
		return chosen;
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

