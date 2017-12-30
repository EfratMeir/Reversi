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

void Console::printConnectToServer(){
	cout << "Connected to server" << endl;
}
void Console::connectionFailed(const char *msg){
	cout << "Failed to connect to server. Reason: " << msg << endl;
}
void Console::printEnterCommand(){
	cout << "please enter your command" << endl;
}
void Console::nameExist(){
	cout << "the name is already exist" <<endl;
}
void Console::printWaitingToOther(){
	cout << "Waiting for other player to join..." << endl;
}
void Console::canStart(){
	cout << "2 players are now connected, we can start!" << endl;
}
void Console::printNowTurn(char sign){
	cout << "its " << sign << "'s turn." << endl;

}
void Console::printChosenMove(char sign, int row, int col){
	cout << sign << "' chose to play (" << row << ", " << col << ")" <<endl;
}
void Console::printCounter(PointsCounter counter){
	cout << "black counter:" << counter.getBlackCount() << endl <<
			"white counter:" << counter.getWhiteCount() << endl;
}
void Console::print_hello(){
	cout << "Welcome to reversi!" << endl << "choose an opponent type: " << endl << endl;

	cout << "to play against the computer type 'c'" << endl <<
			"to play against human player type 'h'" << endl <<
			"to play against a remote player type 'r'" << endl;

}
void Console::printWinner(char winner){
	cout << "GAME IS OVER!" << endl << "THE WINNER IS: ";
	if (winner == 'T') {
		cout << "Tie! X & O have the same number of points";
	}
	else {
		cout << winner << endl;
	}
}
void Console::printInvalidChar(){
	cout << "you have entered an invalid char." <<endl;
}
void Console:: printBoard(Board& board){
	// i - index for rows
	// j - index for columns
//	Point** all_players = board.getAllPlayers();
	for (int i = 0; i < board.getBoardSize() ; i++) {
		cout << " | " << i +1 ;
	}
	cout << " |" << endl;
	for (int i = 0; i < 2 + (4 * board.getBoardSize()); i++){
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < board.getBoardSize(); i++) {
		for (int j = 0; j < board.getBoardSize() + 1; j++) {  //size + 1 because  of the rows indexes
			if (j == 0) {
				cout << i + 1;
			}
			if (j == board.getBoardSize()) {
				cout << "| " << endl ;
				for (int i = 0; i < 2 + (4 * board.getBoardSize()); i++){
						cout << "-";
					}
				cout << endl;
			}
			else {
				cout << "| " << board.all_players_list[i][j].get_sign() << " ";
			}
		}
	}
}
Console::~Console() {
	// TODO Auto-generated destructor stub
}

void Console::printGamesList(vector<string> list) {
	cout << "available games to join: " <<endl;
	for(int i = 0; i < list.size(); i++) {
		cout << list[i] << endl;
	}
}
