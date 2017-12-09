/*
 * RemotePlayer.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: efrat
 */
#include "RemotePlayer.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
RemotePlayer::RemotePlayer() {
//	char IP = static_cast<char>(readFromFile("IP"));
//	int port = readFromFile();

	this->port = convertStringToInt(readFromFile("port"));
	this->IP = convertStringToChar(readFromFile("IP"));
	this->connecter = Connecter((char*)IP, port);
	initializeConnecter();
	this->sign = 'Y'; //not initialize
	set_sign(); //Remote - not initialized
	this->moves_calculator = MovesCalculator();
	this->has_no_moves = false;

}
int RemotePlayer::convertStringToInt(string str){
	int num = atoi(str.c_str());
	return num;
}
 const char* RemotePlayer::convertStringToChar(string str){
	 const char * c = str.c_str();
	 return c;
}
string RemotePlayer::readFromFile(string word){
//	int port_num;
//	int IP;
	ifstream infile("reversi_settings.txt");
	string line;
	while (std::getline(infile, line)){
		istringstream iss(line);
		string word_from_file;
		while(iss >> word_from_file) {
		   if (word_from_file == "port" && word == "port"){
			   iss >> word_from_file;

			   return word_from_file;
//			   stringstream server(word_from_file);
//			   server >> port_num;
//			   return port_num;
		   }
		   if(word_from_file == "IP" && word == "IP"){
			   iss >> word_from_file;
			   return word_from_file;
//			   stringstream ip(word_from_file);
//			   ip >> IP;
//			   return IP;
		}
			// error
			if (!(iss >> word_from_file)) {
				return 0;
			}
		}
	}
	return 0;
}
RemotePlayer::RemotePlayer(char sign) {
	initializeConnecter();
	this->sign = 'Y'; //not initialize
	set_sign();
	this->moves_calculator = MovesCalculator();
	this->has_no_moves = false;

}


void RemotePlayer::play_next_step(Board& board, Point chosen_step) {
	board.setPoint(chosen_step);
}

vector<Point> RemotePlayer::get_possible_moves(Board& board,
		MovesCalculator moves_calculator) {
	connecter.sendMsg(this->opponent_last_move, opponent_has_no_move);
	vector<Point> chosen_move;
	chosen_move.push_back(connecter.recivePoint());
	this->has_no_moves = connecter.reciveNoMoves();
	return chosen_move;
}

Point RemotePlayer::choose_best_move(vector<Point> options_list, Fliper fliper,
		Board& board) {
	return options_list[0];
}

Connecter& RemotePlayer::getConnecter() {
	return this->connecter;
}

void RemotePlayer::setOpponentHasNoMoves(bool opp_has_no_moves) {
	this->opponent_has_no_move = opp_has_no_moves;
}

int RemotePlayer::initializeConnecter() {

	try {
		connecter.connectToServer();

	} catch (const char *msg) {
		cout << "Failed to connect to server. Reason: " << msg << endl;
		exit(-1);
	}
	return 0;
}
void RemotePlayer::set_sign(char sign){

}
void RemotePlayer::set_sign(){
	int color_player = this->getConnecter().reciveColorPlayer();
	if(color_player == 1){
		this->sign = 'O';
	}
	else if(color_player == 2){
		this->sign= 'X';
	}
}
char RemotePlayer::get_sign() {
	return this->sign;
}

bool RemotePlayer::get_no_moves() {
	return this->has_no_moves;
}


RemotePlayer::~RemotePlayer() {
	// TODO Auto-generated destructor stub
}
