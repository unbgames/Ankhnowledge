/*
 * Block.cpp
 *
 *  Created on: Oct 28, 2013
 *      Author: makoto
 */

#include "Block.h"

Block::Block(Sprite * block, float x, float y):GameObject(x,y) {
	this->block = block;
	this->block->incNumRef();
}

Block::~Block() {
	this->block->decNumRef();
	this->block = 0;
	this->tile = 0;
}

int Block::update(int dt)
{
	return 0;
}

void Block::render(float cameraX, float cameraY)
{
	this->block->render(getX(),getY());
}

string Block::getType()
{
	return this->type;
}

void Block::setTile(Tile * tile)
{
	this->tile = tile;
}

Tile * Block::getTile()
{
	return this->tile;
}
