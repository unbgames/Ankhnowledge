#include "BlockFixed.h"
#include <iostream>

using namespace std;

BlockFixed::BlockFixed(Sprite * block, float x, float y):Block(block,x,y)
{
	type = "BlockFixed";
	moving = 0;
	animation = new Animation(20,20,block,0);

}

BlockFixed::~BlockFixed() {}

void BlockFixed::render(float camerax, float cameray)
{
	animation->animate(150,this->x,this->y);
}

int BlockFixed::update(int dt)
{
	interpolateMovement(dt);

	if(this->animDestroyed)
	{
		animation->update(dt,false,0,false);
		if(animation->getFinishedAnimation())
		{
			this->finalDestroyed = true;
		}
	}
	else
		animation->update(dt,true,0,true);
	return 0;
}
void BlockFixed::reaction(Character * character){}

void BlockFixed::interpolateMovement(float dt)
{
	if(this->moving == true)
	{
		if(!lerp(beginX, beginY, endX, endY, 10, dt))
		{
			this->moving = false;
		}
	}

}

