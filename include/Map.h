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
#include "Character.h"
#include "Animation.h"

using namespace std;

class Character;
class Map : public GameObject {
public:
	Map(Sprite * tile, Sprite * block, float x, float y);
	void render(float cameraX, float cameraY);
	int update(int dt);
	virtual ~Map();

private:
	Sprite* tile;
	Sprite* block;
	Sprite* char1_spr;
	Sprite* char2_spr;
	Character * player1;
	Character * player2;
	Character * currentPlayer;
	vector<Tile* > tiles;
	bool changePlayer;
};

#endif /* MAP_H_ */
