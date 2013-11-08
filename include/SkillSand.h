#ifndef SKILLSAND_H_
#define SKILLSAND_H_

#include "Skill.h"

class Tile;
class Skill;

class SkillSand: public Skill
{
	public:
		SkillSand();
		virtual void execute(Tile * origin, Tile * dest); 
		virtual int getRequiredStamina();
		virtual bool getConsiderBlocks();
		virtual int getReach();
		virtual ~SkillSand();	
};

#endif 
