#ifndef SKILL_H_
#define SKILL_H_

#include "Tile.h"

class Tile;

class Skill
{
	public:
		virtual void execute(Tile * origin, Tile * dest) = 0; 
		virtual int getRequiredStamina() = 0;
		virtual bool getConsiderBlocks() = 0;
		virtual int getReach() = 0;
		virtual ~Skill();

	protected:
		Skill();
		int requiredStamina;
		int reach;
		bool considerBlocks;
		bool considerSand;
};

#endif 
