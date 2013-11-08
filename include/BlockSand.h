#ifndef BLOCKSAND_H_
#define BLOCKSAND_H_

#include "Character.h"
#include "Block.h"

class BlockSand: public Block
{
	public:
		BlockSand(Sprite * block, float x, float y);
		int update(int dt);
		virtual void reaction(Character * character);
		virtual ~BlockSand();

};

#endif
