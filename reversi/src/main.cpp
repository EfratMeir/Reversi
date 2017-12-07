/*
 *  Created on: Oct 28, 2017
 *
 *  REVERSI MAIN
 */


#include <Board.h>
#include "Connecter.h"
#include <GameFlow.h>
#include <HumenPlayer.h>
#include <MovesCalculator.h>
#include <Player.h>
#include <Point.h>
#include <TurnBase.h>
#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>
using namespace std;

int main() {
	GameFlow game = GameFlow();
	game.initialize();
	game.run();

	//the main from tirgul:

//	Connecter connecter("127.0.0.1", 8000);
//	try {
//		connecter.connectToServer();
//	} catch (const char *msg) {
//		cout << "Failed to connect to server. Reason: " << msg << endl;
//		exit(-1);
//	}
//
//	int num1, num2;
//	char op;
//
//	while (true) {
//		cout << "Enter an exercise (e.g., 15*19):";
//		cin >> num1 >> op >> num2;
//		cout << "Sending exercise: " << num1 << op << num2 << endl;
//
//		try {
//		int result = connecter.sendExercise(num1, op, num2);
//			cout << "Result: " << result << endl;
//		} catch (const char* msg) {
//			cout << "Failed to send exercise to server. Reason: " << msg << endl;
//		}
//	}

}
