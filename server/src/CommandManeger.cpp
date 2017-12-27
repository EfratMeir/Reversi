/*
 * CommandManeger.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: efrat
 */
//
#include <CommandManeger.h>

#include <string.h>
#include <vector>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

CommandManeger::CommandManeger() {
	// TODO Auto-generated constructor stub

}

void CommandManeger::map(int client_socket, vector<string> args) {
	//read request:
	string request;
	int n = read(client_socket, &request, sizeof(request));
	if (n == -1) {
		cout << "Error reading request from user" << endl;
		return;
}

S
	//CONTINUE MAPING HERE...
	// ...
	// ...
	// ...

}



CommandManeger::~CommandManeger() {

}
