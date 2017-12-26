/*
 * main.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: efrat
 */


#include "Server.h"
#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include <sstream>
#include <fstream>
//#include <string>

int readFromFile(){
	int port_num;
	ifstream infile("server_settings.txt");
	string line;
	while (std::getline(infile, line)){
		istringstream iss(line);
		string word;
		while(iss >> word) {
		   if (word == "port"){
			   iss >> word;
			   stringstream server(word);
			   server >> port_num;
			   return port_num;
		   }
		}
		// error
		if (!(iss >> word)) {
			return 0;
		}
	}
	return 0;
}
int main() {
	int port_num = readFromFile();
	if (port_num == 0){
		cout<< "error reading from file" << endl;
		return 0;
	}
	Server server(port_num);
	try {
		server.start();
	} catch (const char *msg) {
		cout << "cannot start server. Reason: " << msg << endl;
		exit(-1);
	}
}
