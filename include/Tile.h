/*
 * Tiles.h
 *
 *  Created on: Oct 8, 2013
 *      Author: makoto
 */

#ifndef TILE_H_
#define TILE_H_
#include "GameObject.h"
#include "Sprite.h"
#include "Character.h"
#include "Block.h"

class Block;
class Character;
class Tile: public GameObject {
public:
	Tile(Sprite * tile, Block * block, float x, float y, int id);
	void render(float cameraX, float cameraY);
	int update(int dt);
	virtual ~Tile();
	void setRightTile(Tile * tile);
	void setLeftTile(Tile * tile);
	void setUpTile(Tile * tile);
	void setDownTile(Tile * tile);
	Tile * getRightTile();
	Tile * getLeftTile();
	Tile * getUpTile();
	Tile * getDownTile();
	void cleanReferences();
	void setCharacter(Character * character);
	Character* getCharacter();
	Block* getBlock();
	int id;

private:
	Sprite* tile;
	Block* block;
	Tile *leftTile, *rightTile, *upTile, *downTile;
	Character * character;

};

#endif /* TILE_H_ */
