/*
 * ServerInitializer.cpp
 *
 *  Created on: Jan 1, 2018
 *      Author: efrat
 */

#include <ServerInitializer.h>

ServerInitializer::ServerInitializer() {


}

void ServerInitializer::initialize(int port_num) {
	int port = port_num;
	pthread_t new_thread;
	int thread = pthread_create(&new_thread, NULL, goToStart , (void*)&port);
	if (thread) {
		cout << "ERROR: unable to create thread for waitToExitCommand" << endl;
		return;
	}
	//	pthread_exit(NULL);
		return;
}


void* ServerInitializer::goToStart(void* port_num) {
	long port = (long)port_num;
	Server server = Server(port);
	server.start();
}


ServerInitializer::~ServerInitializer() {
	// TODO Auto-generated destructor stub
}

