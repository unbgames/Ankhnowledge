/*
 * Animation.cpp
 *
 *  Created on: Oct 27, 2013
 *      Author: al
 */

#include "Animation.h"

Animation::Animation(int spriteWidth, int spriteHeight, Sprite* sprite,int direction) {
    //instancia um novo sprite
    this->animation = sprite;
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;
    this->columns =  animation->getWidth() / spriteWidth;
    this->dt = 0;
    this->startFrame = direction * columns;
    this->prevDirection = direction;
    this->currentFrame = startFrame;
    this->animateSprite = true;
    this->move = true;

}

Animation::~Animation() {
	// TODO Auto-generated destructor stub
}

void Animation::render(int index, float posX,float posY){

	int x = index % columns;
	int y = index / columns;

	int clipx = x * spriteWidth;
	int clipy = y * spriteHeight;

	animation->clip(clipx, clipy, spriteWidth, spriteHeight);
	animation->render(posX, posY);

}

void Animation::animate(int frameRate,float posX, float posY){
	this->frameRate = frameRate;
	render(currentFrame,posX,posY);

}

void Animation::update(int dt,bool oneShot, int direction){
	this->dt = this->dt + dt;

	if(prevDirection != direction)
	{
		this->startFrame = direction * columns;
		this->currentFrame = startFrame;
		this->prevDirection = direction;
	}

	if((this->dt > frameRate))
	{
		if((currentFrame == startFrame + columns -1) && (oneShot == true))
		{
			currentFrame = startFrame;
			move = true;
		}
		else if((currentFrame == startFrame + columns -1) && (oneShot == false))
		{
			move = false;
		}
		else {
			currentFrame++;
			this->dt = 0;
			move = true;
		}
	}

}

bool Animation::needToMove(){
	return this->move;
}
