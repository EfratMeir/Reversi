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
	int board_size = 8;
	Board b = Board(board_size);
	Console console = Console();
	this->initialize(b, console);
	this->start_or_join = "Default";
//	this->name = "no name";
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
	cin.ignore();

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
	char remote_sign;
	char* command_name = "default";
	bool start_game = false;
	while (!start_game) {
		enterCommand(console, connecter); //start or join or see all possible games

		if (strcmp(this->start_or_join, "start") == 0) {
			remote_sign = 'O';
		}
		if(strcmp(this->start_or_join, "join") == 0) {
			remote_sign = 'X';
		}

		Player* remote_player = new RemotePlayer(connecter, remote_sign);
	//	char remote_sign = remote_player->get_sign();
		is_remote_game = true;
		if (remote_sign == 'X'){
			players[0] = remote_player;
			players[1] = new HumenPlayer('O');
		}
		else{
			players[0] =  new HumenPlayer('X');
			players[1] = remote_player;
		}
			this->turn_base.getConsole().printWaitingToOther();
		//wait until server will send a msg that we can start:

		start_game = connecter.receieveStartGame();

//		if(remote_sign == 'O'){
//			initializeConnecter(connecter);
		//	string play_name = this->name;
//			play_name.insert(0, "play ");
//			char* play_command;
//			const char* play_name_command = play_name.c_str();
//			strcpy(play_command, play_name_command);
//			connecter.sendCommand("play");
//		}
	}

	this->turn_base.getConsole().canStart();
	this->turn_base = TurnBase(b, players, is_remote_game, connecter, console);
}
/**
 * the function send a command to the server.
 * @param console
 * @param connecter
 * return the sign of the *remote player.* if the command is start , the sign of the remote is o.
 * if the ccommand is join the sign is x.
 */
void GameFlow::enterCommand(Console& console, Connecter& connecter){
	initializeConnecter(connecter);
	console.printEnterCommand();
	char command[MAX_COMMAND_SIZE];
	bool valid_input = false;

	while(!valid_input) {
		cin.getline(command, MAX_COMMAND_SIZE);
		if(strncmp(command, "start", 5) == 0 || strncmp(command, "join", 4) == 0
				|| strncmp(command, "list_games", 10) == 0) {
			valid_input = true;
		}
		else{
			console.printInvalidCommand();
		}
	}
	connecter.sendCommand(command);

//	cin.ignore();
//	cout << "the command is" << command;

	char* command_name;
	command_name = strtok (command," ");

	if (strcmp(command_name, "start") == 0){
		int game_name = connecter.receiveStartCommandMsg();
		if (game_name == -1){ //the game name is already exist
			console.nameExist();
			enterCommand(console, connecter);
		}
		else{
			this->start_or_join = "start";
			//wait to get a message that the second player is connected and
			//we can start the game
			//cout << "you opened a new game "<< endl;
		}
	}
	else if (strcmp(command_name, "join") == 0){
		bool join_valid = connecter.receiveJoinValid();
		//if there is no game with this name, choose command again
		if(join_valid == false){
			console.noGame();
			enterCommand(console, connecter);
		}
		else{
			this->start_or_join = "join";
		}
	}
	else if (strcmp(command_name, "list_games") == 0){
		vector<string> games_to_join;
		connecter.receieveGamesTojoinList(games_to_join);
		console.printGamesList(games_to_join);
		enterCommand(console, connecter);
	}

//	return command_name;
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
//	turn_base.play_game();
//	delete turn_base.get_players()[0];
//	delete turn_base.get_players()[1];
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

