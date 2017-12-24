/*
 * Console.cpp
 *
 *  Created on: Dec 23, 2017
 *      Author: keren
 */

#include "Console.h"

Console::Console() {
	// TODO Auto-generated constructor stub

}
Console::Console(Board& board){
	this->board = board;
}
void Console::printNowTurn(char sign){
	cout << "its " << sign << "'s turn." << endl;

}
void Console::printCounter(PointsCounter counter){
	cout << "black counter:" << counter.getBlackCount() << endl <<
			"white counter:" << counter.getWhiteCount() << endl;
}

void Console:: printBoard(){
	// i - index for rows
	// j - index for columns
	Point** all_players = this->board.getAllPlayers();
	for (int i = 0; i < this->board.getBoardSize() ; i++) {
		cout << " | " << i +1 ;
	}
	cout << " |" << endl;
	for (int i = 0; i < 2 + (4 * this->board.getBoardSize()); i++){
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < this->board.getBoardSize(); i++) {
		for (int j = 0; j < this->board.getBoardSize() + 1; j++) {  //size + 1 because  of the rows indexes
			if (j == 0) {
				cout << i + 1;
			}
			if (j == this->board.getBoardSize()) {
				cout << "| " << endl ;
				for (int i = 0; i < 2 + (4 * this->board.getBoardSize()); i++){
						cout << "-";
					}
				cout << endl;
			}
			else {
				cout << "| " << all_players[i][j].get_sign() << " ";
			}
		}
	}
}
Console::~Console() {
	// TODO Auto-generated destructor stub
}

