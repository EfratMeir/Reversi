/*
 * GameFlow.cpp
 */

#include <GameFlow.h>
#include "RemotePlayer.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdlib.h>
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
	char chosen_player = choose_players();
	if (chosen_player == 'r' || chosen_player == 'R'){
		int port = convertStringToInt(readFromFile("port"));
		const char* IP = convertStringToChar(readFromFile("IP"));
		Connecter connecter = Connecter((char*)IP, port);
		initializeConnecter(connecter);
		Player* remote_player = new RemotePlayer(connecter); // I HAVE NOT DELETED YET!!!! DO NOT FORGET
		char remote_sign = remote_player->get_sign();
		is_remote_game = true;
		if (remote_sign == 'X'){
			players[0] = remote_player;
			players[1] = new HumenPlayer('O');
		}
		else{
			players[0] =  new HumenPlayer('X');
			players[1] = remote_player;
			cout << "Waiting for other player to join..." << endl;
		}

		//wait until server will send a msg that we can start:
		bool start_game = connecter.receieveStartGame();
		this->turn_base = TurnBase(b, players, is_remote_game, connecter);
	}

	if (chosen_player == 'c' || chosen_player == 'C'){
		players[0] = new HumenPlayer('X');
		players[1] = new ComputerPlayer('O');
		this->turn_base = TurnBase(b, players, is_remote_game);
	}

	else if (chosen_player == 'h' || chosen_player == 'H'){
		//chosen player is a human player
		players[0] = new HumenPlayer('X');
		players[1] = new HumenPlayer('O');
		this->turn_base = TurnBase(b, players, is_remote_game);
	}
}
int GameFlow::initializeConnecter(Connecter& connecter) {

	try {
		connecter.connectToServer();

	} catch (const char *msg) {
		cout << "Failed to connect to server. Reason: " << msg << endl;
		exit(-1);
	}
	return 0;
}
int GameFlow::convertStringToInt(string str){
	int num = atoi(str.c_str());
	return num;
}
 const char* GameFlow::convertStringToChar(string str){
	 const char * c = str.c_str();
	 return c;
}
string GameFlow::readFromFile(string word){
	ifstream infile("reversi_settings.txt");
	string line;
	while (std::getline(infile, line)){
		istringstream iss(line);
		string word_from_file;
		while(iss >> word_from_file) {
		   if (word_from_file == "port" && word == "port"){
			   iss >> word_from_file;

			   return word_from_file;
		   }
		   if(word_from_file == "IP" && word == "IP"){
			   iss >> word_from_file;
			   return word_from_file;
		}
			// error
			if (!(iss >> word_from_file)) {
				return 0;
			}
		}
	}
	return 0;
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
//	turn_base.connecter.sendPoint(Point(-1,-1,' ')); //send no point
//	turn_base.connecter.sendNoMoves(1); //MAYBE TURNBASE NEED TO BE FRIEND CLASS
	char winner = findWinner(turn_base);
	if (winner == 'T') {
		cout << "Tie! X & O have the same number of points";
	}
	else {
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

