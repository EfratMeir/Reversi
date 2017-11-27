/*
 *  Created on: Oct 28, 2017
 *      Author: Efrat Meir
 *      user name meirefr
 *      ID 201543253
 */

/**
 * IMPORTANT NOTICE: i planed the UML and the game structure together with Keren Levy, as we will be partners in the next exercises.
 * 					 the implementation of this files was made by my self.
 */

#include <Board.h>
#include <GameFlow.h>
#include <HumenPlayer.h>
#include <MovesCalculator.h>
#include <Player.h>
#include <Point.h>
#include <TurnBase.h>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
	GameFlow game = GameFlow();
	game.initialize();
	game.run();

}
