/*
 * Character.cpp
 *
 *  Created on: Oct 7, 2013
 *      Author: al
 */

#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(Sprite* sprite, float x, float y, int id):GameObject(getX(),getY()) {
	this->sprite = sprite;
	sprite->incNumRef();
	this->x = x;
	this->y = y;
	this->currentAnimation = new Animation(20,40,sprite,0);
	this->moving = false;
	this->stamina = 10;
	this->turn = false;
	this->id = id;
	this->direction = 0;

}

Character::~Character() {
	this->sprite->decNumRef();
	sprite = 0;
}

void Character::render(float cameraX, float cameraY){

	currentAnimation->animate(50, this->x - cameraX,this->y - cameraY - 40/2);

}

int Character::update(int dt){
	InputManager* input;
	input = InputManager::getInstance();

	if(turn)
	{
		Direction dir = none;

		if (input->isKeyPressed(SDLK_d))
		{
			dir = right;
			direction = 2;
		}

		if (input->isKeyPressed(SDLK_a))
		{
			dir = left;
			direction = 1;
		}

		if (input->isKeyPressed(SDLK_s))
		{
			dir = down;
			direction = 0;
		}
		if (input->isKeyPressed(SDLK_w))
		{
			dir = up;
			direction = 3;
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
