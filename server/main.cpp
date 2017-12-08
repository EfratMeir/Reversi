/*
 * main.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: efrat
 */


#include "Server.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	Server server(8000);
	try {
		server.start();
	} catch (const char *msg) {
		cout << "cannot start server. Reason: " << msg << endl;
		exit(-1);
	}
}
