/*
 * Animation.h
 *
 *  Created on: Oct 27, 2013
 *      Author: al
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_
#include "Sprite.h"
#include <iostream>

using namespace std;

class Animation {
public:
	Animation(int spriteWidth, int spriteHeight, Sprite* sprite,int direction);
	virtual ~Animation();
	void render(int index, float posX, float posY);
	void animate(int frameRate,float posX, float posY);
	void update(int dt,bool onLoop,int direction, bool singleFrame);
	bool getFinishedAnimation();
	void resetStartFrame();

private:
	Sprite* animation;
	int spriteWidth, spriteHeight,columns;
	int currentFrame,startFrame,dt,frameRate;
	bool animateSprite,finishedAnimation;
	int  prevDirection;
};

#endif /* ANIMATION_H_ */
