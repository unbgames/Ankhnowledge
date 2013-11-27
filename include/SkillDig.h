#ifndef SKILLDIG_H_
#define SKILLDIG_H_

#include "Skill.h"

class Tile;
class Skill;

class SkillDig: public Skill
{
	public:
		SkillDig();
		virtual void execute(Tile * origin, Tile * dest); 
		virtual int getRequiredStamina();
		virtual bool getConsiderBlocks();
		virtual int getReach();
		virtual ~SkillDig();	
};

#endif 
