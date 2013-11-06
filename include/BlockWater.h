
#ifndef BLOCKWATER_H_
#define BLOCKWATER_H_
#include "Character.h"
#include "Block.h"

class BlockWater: public Block 
{
public:
	BlockWater(Sprite * block, float x, float y);
	int update(int dt);
	virtual void reaction(Character * character);
	virtual ~BlockWater();

};

#endif /* BLOCK_H_ */
