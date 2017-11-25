/*
 * Sprite.h
 *
 *  Created on: Nov 3, 2017
 *      Author: efrat
 */

#ifndef SPRITE_H_
#define SPRITE_H_
#include <iostream>
using namespace std;

class Sprite {

public:
	virtual void draw() = 0;
	virtual ~Sprite() = 0;
};

#endif /* SPRITE_H_ */
