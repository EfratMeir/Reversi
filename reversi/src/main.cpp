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
//	game.initialize();
	game.run();
}
