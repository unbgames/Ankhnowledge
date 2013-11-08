/*
 * Tiles.cpp
 *
 *  Created on: Oct 8, 2013
 *      Author: makoto
 */

#include "Tile.h"
#include "SDLBase.h"
#include <sstream>
using namespace std;

Tile::Tile(Sprite * tile, Block * block,float x, float y, int id):GameObject(x,y) {
	this->tile = tile;
	this->tile->incNumRef();
	this->block = block;
	this->leftTile = 0;
	this->rightTile = 0;
	this->upTile = 0;
	this->downTile = 0;
	this->id = id;
	this->character = 0;
	this->clickable = false;

	if(block)
		block->setTile(this);
}

Tile::~Tile() {
	this->tile->decNumRef();
	this->tile = 0;

	delete block;
	// TODO Auto-generated destructor stub
}

void Tile::render(float cameraX, float cameraY){
	if(tile)
		tile->render(getX(), getY());
}


int Tile::update(int dt){

	if(block)
		block->update(dt);
	return 0;
}

bool Tile::insideTile()
{
	InputManager* input;
	input = InputManager::getInstance();

	return ((input->mousePosX() > this->x) && (input->mousePosX() < (this->x + this->tile->getWidth())) &&
			(input->mousePosY() > this->y) && (input->mousePosY() < (this->y + this->tile->getHeight())));

}


void Tile::setLeftTile(Tile * tile)
{
	this->leftTile = tile;
}

void Tile::setRightTile(Tile * tile)
{
	this->rightTile = tile;
}

void Tile::setUpTile(Tile * tile)
{
	this->upTile = tile;
}

void Tile::setDownTile(Tile * tile)
{
	this->downTile = tile;
}

Tile * Tile::getRightTile()
{
	return this->rightTile;
}

Tile * Tile::getLeftTile()
{
	return this->leftTile;
}

Tile * Tile::getUpTile()
{
	return this->upTile;
}

Tile * Tile::getDownTile()
{
	return this->downTile;
}

void Tile::cleanReferences()
{
	this->leftTile  = 0;
	this->rightTile = 0;
	this->upTile = 0;
	this->downTile = 0;
}

void Tile::setCharacter(Character * character)
{
	this->character = character;
}

Character * Tile::getCharacter()
{
	return this->character;
}

Block * Tile::getBlock()
{
	return this->block;
}

bool Tile::isClickable()
{
	return this->clickable;
}

void Tile::setClickable(bool click)
{
	this->clickable = click;
}

void Tile::setBlock(Block * block)
{
	this->block = block;
}

float Tile::getWidth()
{
	return tile->getWidth();
}
