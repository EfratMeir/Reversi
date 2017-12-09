/*
 * Server.h
 *
 *  Created on: Dec 5, 2017
 *      Author: efrat
 */

#ifndef SERVER_H_
#define SERVER_H_

class Server {
public:
	Server(int port);
	void start();
	void stop();

private:
	int port;
	int serverSocket; //the sockets file descriptor

	// Handle requests from a specific client
	void handleClient(int clientSocket, int clientSocket2);

	void writeColorNum(int first_player, int second_player,
			int clientSocket1, int clientSocket2 );

	void notifyGameStarts(int clientSocket1, int clientSocket2);
};

#endif /* SERVER_H_ */
