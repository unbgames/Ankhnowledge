#include "BlockSand.h"
#include <iostream>

using namespace std;

BlockSand::BlockSand(Sprite * block, float x, float y):Block(block,x,y)
{
	type = "BlockSand";
	animation = new Animation(20,20,block,0);
}

BlockSand::~BlockSand() {
	this->block = 0;
	delete this->block;

}

int BlockSand::update(int dt)
{
	animation->update(dt,true,0,false);
	return 0;
}

void BlockSand::render(float camerax, float cameray){
	camerax = this->x;
	cameray = this->y;
	animation->animate(100, camerax, cameray);
}

void BlockSand::reaction(Character * character)
{
	character->getId();
	this->tile->setBlock(0);
	this->tile = 0;
}
