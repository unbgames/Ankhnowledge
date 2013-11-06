#include "BlockWater.h"

BlockWater::BlockWater(Sprite * block, float x, float y):Block(block,x,y) {
	type = "BlockWater";
}

BlockWater::~BlockWater() {

}

int BlockWater::update(int dt)
{
	return 0;
}

void BlockWater::reaction(Character * character)
{

}
