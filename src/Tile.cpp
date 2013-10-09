/*
 * Tiles.cpp
 *
 *  Created on: Oct 8, 2013
 *      Author: makoto
 */

#include "Tile.h"

using namespace std;

Tile::Tile(Sprite * tile, Sprite * block, float x, float y):GameObject(x,y) {
	this->tile = tile;
	this->tile->incNumRef();
	this->block = block;
	this->block->incNumRef();
}

Tile::Tile(Sprite * tile, float x, float y):GameObject(x,y) {
	this->tile = tile;
	this->tile->incNumRef();
	this->block = 0;
}

Tile::~Tile() {
	this->tile->decNumRef();
	this->tile = 0;

	if(block != 0)
	{
		this->block->decNumRef();
		this->block = 0;
	}
	// TODO Auto-generated destructor stub
}

void Tile::render(float cameraX, float cameraY){
	if(tile)
		tile->render(getX(), getY());

	if(block)
	if(block != 0)
		block->render(getX(),getY());
}

int Tile::update(int dt){

	return 0;
}

