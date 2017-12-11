/*
 * Sprite.h
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
