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
	int calc(int arg1, const char op, int arg2) const;
};

#endif /* SERVER_H_ */
