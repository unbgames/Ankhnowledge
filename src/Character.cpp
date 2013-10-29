/*
 * Character.cpp
 *
 *  Created on: Oct 7, 2013
 *      Author: al
 */

#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(Sprite* sprite, Tile * tile, int id):GameObject(tile->getX(),tile->getY()) {
	this->sprite = sprite;
	sprite->incNumRef();
	this->currentTile = tile;
	tile->setCharacter(this);
	this->x = tile->getX();
	this->y = tile->getY();
	this->currentAnimation = new Animation(20,40,sprite,0);
	this->moving = false;
	this->stamina = 10;
	this->turn = false;
	this->id = id;
	this->direction = 0;
}

Character::~Character() {
	this->currentTile = 0;
	this->sprite->decNumRef();
	sprite = 0;
}

void Character::render(float cameraX, float cameraY){

	currentAnimation->animate(50, this->x - cameraX,this->y - cameraY - 40/2);

}

int Character::update(int dt){
	InputManager* input;
	input = InputManager::getInstance();

	if(turn && !moving)
	{
		Direction dir = none;

		/*if(currentTile->getRightTile())
			cout<<"dir: "<<currentTile->getRightTile()->getCharacter()<<endl;
		if(currentTile->getLeftTile())
			cout<<"esq: "<<currentTile->getLeftTile()->getCharacter()<<endl;
		if(currentTile->getUpTile())
			cout<<"cim: "<<currentTile->getUpTile()->getCharacter()<<endl;
		if(currentTile->getDownTile())
			cout<<"bai: "<<currentTile->getDownTile()->getCharacter()<<endl;
		*/
		if (input->isKeyPressed(SDLK_d) && canChangeTile(currentTile->getRightTile()))
		{
			dir = right;
			direction = 2;
			changeCurrentTile(currentTile->getRightTile());
		}else
		if (input->isKeyPressed(SDLK_a) && canChangeTile(currentTile->getLeftTile()))
		{
			dir = left;
			direction = 1;
			changeCurrentTile(currentTile->getLeftTile());
		}else
		if (input->isKeyPressed(SDLK_s)  && canChangeTile(currentTile->getDownTile()))
		{
			dir = down;
			direction = 0;
			changeCurrentTile(currentTile->getDownTile());
		}else
		if (input->isKeyPressed(SDLK_w)  && canChangeTile(currentTile->getUpTile()))
		{
			dir = up;
			direction = 3;
			changeCurrentTile(currentTile->getUpTile());
		}

		if(dir != none && !moving)
			move(dir);


	}
	interpolateMovement(dt);
	currentAnimation->update(dt, true,direction);
	return 0;
}

void Character::move(Direction dir)
{
	this->moving = true;
	this->stamina -= 1;
	switch(dir)
	{
	    case up:
	    	endX = getX();
	    	endY = getY() - 20;
	    break;

	    case down:
	    	endX = getX();
			endY = getY() + 20;
	    break;
	    case right:
	    	endX = getX() + 20;
			endY = getY();
	    break;

	    case left:
	    	endX = getX() - 20;
			endY = getY();

	    break;

	    case none:

	    break;

	}

	   beginX = getX();
	   beginY = getY();
}

void Character::interpolateMovement(float dt)
{
	if(this->moving == true)
	{
		if(!lerp(beginX, beginY, endX, endY, 10, dt))
		{
			this->moving = false;
			direction = 0;
		}
	}

}

bool Character::getStamina()
{
	return this->stamina;
}

void Character::setStamina(int stamina)
{
	this->stamina = stamina;
}

void Character::setTurn(bool on)
{
	turn = on;
}

void Character::toogleTurn()
{
	if(turn == true)
		turn = false;
	else
		turn = true;
}

int Character::getId()
{
	return this->id;
}

bool Character::isMoving()
{
	return this->moving;
}

void Character::setCurrentTile(Tile * tile)
{
	this->currentTile = tile;
}

Tile * Character::getCurrentTile()
{
	return this->currentTile;
}

void Character::changeCurrentTile(Tile * tile)
{
	currentTile->setCharacter(0);
	currentTile = tile;
	currentTile->setCharacter(this);
}

bool Character::canChangeTile(Tile * tile)
{
	if(tile == 0)
		return false;

	if(tile->getCharacter() != 0)
		return false;

	if(tile->getBlock())
		return false;

	return true;
}
