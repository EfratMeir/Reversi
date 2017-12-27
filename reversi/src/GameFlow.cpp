/*
 * GameFlow.cpp
 */

#include "GameFlow.h"
#include "RemotePlayer.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 8
#define MAX_COMMAND_SIZE 50

GameFlow::GameFlow() {
	int board_size = 6;
	Board b = Board(board_size);
	Console console = Console();
	this->initialize(b, console);
}

void GameFlow::initialize(Board& b, Console& console) {
//	indexes are -1 because the array start from 0
	int board_size = b.getBoardSize();
	b.setPoint(Point(board_size/2 -1, board_size/2 - 1, b.white_player));
	b.setPoint(Point(board_size/2 + 1 - 1, board_size/2 + 1 - 1, b.white_player));
	b.setPoint(Point(board_size/2 - 1, board_size/2 + 1 - 1, b.black_player));
	b.setPoint(Point(board_size/2 + 1 - 1, board_size/2 - 1, b.black_player));

	bool is_remote_game = false;
	Player* players[2];

	char chosen_player = choose_players();
	if (chosen_player == 'r' || chosen_player == 'R'){
		startRemoteGame(players, b , console);
	}

	if (chosen_player == 'c' || chosen_player == 'C'){
		players[0] = new HumenPlayer('X');
		players[1] = new ComputerPlayer('O');
		this->turn_base = TurnBase(b, players, is_remote_game, console);
	}

	else if (chosen_player == 'h' || chosen_player == 'H'){
		//chosen player is a human player
		players[0] = new HumenPlayer('X');
		players[1] = new HumenPlayer('O');
		this->turn_base = TurnBase(b, players, is_remote_game, console);
	}
}
void GameFlow::startRemoteGame(Player* players[2], Board& b, Console& console){
	bool is_remote_game = true;
	int port = convertStringToInt(readFromFile("port"));
	const char* IP = convertStringToChar(readFromFile("IP"));
	Connecter connecter = Connecter((char*)IP, port);
	initializeConnecter(connecter);
	enterCommand(console, connecter);

	Player* remote_player = new RemotePlayer(connecter);
	char remote_sign = remote_player->get_sign();
	is_remote_game = true;
	if (remote_sign == 'X'){
		players[0] = remote_player;
		players[1] = new HumenPlayer('O');
	}
	else{
		players[0] =  new HumenPlayer('X');
		players[1] = remote_player;
		this->turn_base.getConsole().printWaitingToOther();
//		cout << "Waiting for other player to join..." << endl;
	}

	//wait until server will send a msg that we can start:
	bool start_game = connecter.receieveStartGame();
	this->turn_base.getConsole().canStart();
	this->turn_base = TurnBase(b, players, is_remote_game, connecter, console);
}
void GameFlow::enterCommand(Console& console, Connecter& connecter){
	console.printEnterCommand();
//	string command_temp ;
//	getline(cin >> ws, command_temp);
//	const char* command = convertStringToChar(command_temp);
//	connecter.sendCommand(command);
	char command[MAX_COMMAND_SIZE];
	cin.ignore();
	cin.getline(command, MAX_COMMAND_SIZE);
	cout << "the command is" << command;
	connecter.sendCommand(command);
	int game_name = connecter.receieveStartGame();
	if (game_name == -1){ //the game name is already exist
		console.nameExist();
	}
//	if (command.find("start ") != -1){ //if its a start command
//
//	}

}
char GameFlow::choose_players(){
	this->turn_base.getConsole().print_hello();
	char chosen;
	cin >> chosen;
	if (!(chosen == 'c' || chosen == 'C' || chosen == 'h'
			|| chosen == 'H' || chosen == 'r' || chosen == 'R')){
		this->turn_base.getConsole().printInvalidChar();
//		cout << "you have entered an invalid char." <<endl;
		chosen = choose_players();
		return chosen;
	}
	return chosen;
}
int GameFlow::initializeConnecter(Connecter& connecter) {

	try {
		connecter.connectToServer();
		this->turn_base.getConsole().printConnectToServer();

	} catch (const char *msg) {
		this->turn_base.getConsole().connectionFailed(msg);
//		cout << "Failed to connect to server. Reason: " << msg << endl;
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

void GameFlow::run() {
	turn_base.play_game();
	delete turn_base.get_players()[0];
	delete turn_base.get_players()[1];
}

GameFlow::~GameFlow() {

}

char GameFlow::findWinner(TurnBase& turn_base) {
	if (turn_base.getBoard().getCounter().getBlackCount() > turn_base.getBoard().getCounter().getWhiteCount()) {
		return 'X';
	}
	if (turn_base.getBoard().getCounter().getBlackCount() < turn_base.getBoard().getCounter().getWhiteCount()) {
		return 'O';
	}
	return 'T';
}

