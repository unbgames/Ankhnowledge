/*
 * Map.h
 *
 *  Created on: Oct 8, 2013
 *      Author: makoto
 */

#ifndef MAP_H_
#define MAP_H_

#include "Tile.h"
#include "Sprite.h"
#include "InputManager.h"
#include <vector>
#include "GameObject.h"
using namespace std;

class Map : public GameObject {
public:
	Map(Sprite * tile, Sprite * block, float x, float y);
	void render(float cameraX, float cameraY);
	int update(int dt);
	virtual ~Map();

private:
	Sprite* tile;
	Sprite* block;
	Sprite* char1;
	Sprite* char2;
	vector<Tile* > tiles;
};

#endif /* MAP_H_ */
