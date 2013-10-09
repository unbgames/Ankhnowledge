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

class Tile: public GameObject {
public:
	Tile(Sprite * tile, Sprite * block, float x, float y);
	Tile(Sprite * tile, float x, float y);
	void render(float cameraX, float cameraY);
	int update(int dt);
	virtual ~Tile();

private:
	Sprite* tile;
	Sprite* block;
};

#endif /* TILE_H_ */
