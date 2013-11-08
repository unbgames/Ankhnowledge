#include "SkillSand.h"
#include "SDLBase.h"
#include "BlockSand.h"
#include "Tile.h"
#include "Character.h"

SkillSand::SkillSand()
{
	this->requiredStamina = 4;
	this->considerBlocks = true;
	this->reach = 3;
}

SkillSand::~SkillSand() {}

void SkillSand::execute(Tile * origin, Tile * dest)
{
	Block *oldBlock = dest->getBlock();
	if(oldBlock)
	{	
		dest->setBlock(0);
		delete oldBlock;
	}
	else
	{
		Block *newBlock = new BlockSand(new Sprite(SDLBase::imagePath + "tile.png"), dest->getX(), dest->getY());
		dest->setBlock(newBlock);
	}
}

int SkillSand::getRequiredStamina()
{
	return this->requiredStamina;
}

bool SkillSand::getConsiderBlocks()
{
	return this->considerBlocks;
}

int SkillSand::getReach()
{
	return this->reach;
}