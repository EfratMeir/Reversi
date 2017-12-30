/*
 * Connecter.h
 *
 *  Created on: Dec 6, 2017
 *      Author: efrat
 */

#ifndef CONNECTER_H_
#define CONNECTER_H_
#define MAX_COMMAND_SIZE 50

#include "Point.h"
#include <vector>
class Connecter {
public:
	/**
	 * constructor
	 */
	Connecter();
	/**
	 * constructor
	 * @param serverIP the IP number
	 * @param serverPort the port number
	 */
	Connecter( char *serverIP, int serverPort);
	/**
	 * connect the client to server
	 */
	void connectToServer();
	/**
	 * send the move and if there's no move to server
	 * @param p the move
	 * @param player_has_no_moves bool - true if the player has no moves.
	 * @return the move
	 */
	int sendMsg(Point p, bool player_has_no_moves);
	/**
	 * receive from server '1' if he is the first player, 2 if second.
	 * @return the number
	 */
	int sendCommand( char command[MAX_COMMAND_SIZE]);
	int receiveNumPlayer();
	/**
	 * receive a point from the server (the move of the other player)
	 * @return the point
	 */
	Point receivePoint();
	/**
	 * receive from server bool - if there's no moves.
	 * @return if there's no moves return 1, else 0
	 */
	bool receiveNoMoves();
	/**
	 * receive a bool that the game can start
	 * @return 1 if the game can start, else 0
	 */
	bool receieveStartGame();
	/**
	 * send to server bool - if there's no moves
	 * @param player_has_no_moves bool
	 * @return
	 */
	int sendNoMoves(bool player_has_no_moves);

	/**
	 * receive a bool that the game can start
	 * @return 1 if the game can start, else 0
	 */
	void receieveGamesTojoinList(vector<string>& games_to_join_list);

	/**
	 * send a point to server
	 * @param p the point
	 * @return
	 */
	int sendPoint(Point p);

	/**
	 * receive from server '1' if he is the first player, 2 if second.
	 * @return the number
	 */
	int receiveStartCommandMsg();
	bool receiveJoinValid();
private:
	//members
	char *serverIP; //CHANGE FROM CONST CHAR* TO CHAR*
	int serverPort;
	int clientSocket;



};

#endif /* CONNECTER_H_ */
