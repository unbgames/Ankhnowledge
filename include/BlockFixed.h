#ifndef BLOCKFIXED_H_
#define BLOCKFIXED_H_

#include "Character.h"
#include "Block.h"
#include "Animation.h"

class BlockFixed: public Block
{
public:
	BlockFixed(Sprite * block, float x, float y);
	int update(int dt);
	void render(float camerax, float cameray);
	void reaction(Character * character);
	virtual ~BlockFixed();
	enum Direction { up, down, right, left, none };
	void interpolateMovement(float dt);


private:
	float endX;
	float endY;
	float beginX;
	float beginY;
	bool moving;
	Animation* animation;
};

#endif
