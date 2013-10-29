/*
 * Block.h
 *
 *  Created on: Oct 28, 2013
 *      Author: makoto
 */

#ifndef BLOCK_H_
#define BLOCK_H_
#include "GameObject.h"
#include "Character.h"

class Character;
class Block: public GameObject {
public:
	Block(Sprite * block, float x, float y);
	void render(float cameraX, float cameraY);
	int update(int dt);
	//virtual void reaction(Character * character) = 0;
	virtual ~Block();

protected:
	Sprite* block;

};

#endif /* BLOCK_H_ */
