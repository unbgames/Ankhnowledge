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
	this->animDestroyed = false;
	this->finalDestroyed = false;
}

Block::~Block() {
	this->block->decNumRef();
	this->block = 0;
	this->tile = 0;
}

int Block::update(int dt)
{
	dt = 0;
	return dt;
}

void Block::render(float cameraX, float cameraY)
{
	cameraX = getX();
	cameraY = getY();
	this->block->render(cameraX, cameraY);
}

void Block::setDestroyedAnimBlock(bool destroyed){
	this->animDestroyed = destroyed;
}

void Block::setDestroyedFinalBlock(bool destroyed){
	this->finalDestroyed = destroyed;
}

bool Block::getDestroyedFinalBlock(){
	return this->finalDestroyed;
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
