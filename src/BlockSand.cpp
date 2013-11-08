#include "BlockSand.h"
#include <iostream>

using namespace std;

BlockSand::BlockSand(Sprite * block, float x, float y):Block(block,x,y) 
{
	type = "BlockSand";
}

BlockSand::~BlockSand() {}

int BlockSand::update(int dt)
{
	return 0;
}

void BlockSand::reaction(Character * character)
{
	character->setStamina(character->getStamina() - 3);
}

