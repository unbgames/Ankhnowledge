/*
 * Character.cpp
 *
 *  Created on: Oct 7, 2013
 *      Author: al
 */

#include "Character.h"
#include <iostream>

Character::Character(Sprite* sprite, float x, float y):GameObject(getSprite(),getX(),getY()) {
	this->sprite = sprite;
	sprite->incNumRef();
	this->x = x;
	this->y = y;

}

Character::~Character() {
	// TODO Auto-generated destructor stub
}

void Character::render(float cameraX, float cameraY){
	if(this->sprite) {
		this->sprite->render(this->x - cameraX,this->y - cameraY);
	}
}

int Character::update(int dt){
	float c = 0.3;
	vx = 0;
	vy = 0;
	InputManager* input;
	input = InputManager::getInstance();
	if (input->isKeyPressed(SDLK_d))
			vx = c*dt;
	if (input->isKeyPressed(SDLK_a))
			vx = - (c * dt);
	if (input->isKeyPressed(SDLK_s))
			vy = c*dt;
	if (input->isKeyPressed(SDLK_w))
			vy = - (c*dt);
	//incrementa a posição x da terra de forma linear
	this->x += vx;
	//incrementa a ṕosição y da terra de forma linear
	this->y += vy;

	if(this->x > 100){
		if(sprite){
			this->sprite->decNumRef();
			if(this->sprite->getNumRef() == 0){
				this->sprite = 0;
			}
		}
	}
	return 0;
}
