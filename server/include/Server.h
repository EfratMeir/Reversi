/*
 * Server.h
 *
 *  Created on: Dec 5, 2017
 *      Author: efrat
 */

#ifndef SERVER_H_
#define SERVER_H_


#include <ClientHandler.h>

using namespace std;


class Server {
public:
	Server();
	Server(int port);
	void start();
	void stop();
	void setExit();
	void threadOpening();


private:
	int port;
	bool exit;
	ClientHandler client_handler;
	int serverSocket; //the sockets file descriptor
	// Handle requests from a specific client
	void handleClient(int clientSocket, int clientSocket2);

	void writeColorNum(int first_player, int second_player,
			int clientSocket1, int clientSocket2 );

	void notifyGameStarts(int clientSocket1, int clientSocket2);
	static void* waitToExitCommand(void *);
	vector<pthread_t> server_threads_vec;
	void closeAllClientsSockets();


};

#endif /* SERVER_H_ */
