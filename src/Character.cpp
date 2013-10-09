/*
 * Character.cpp
 *
 *  Created on: Oct 7, 2013
 *      Author: al
 */

#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(Sprite* sprite, float x, float y):GameObject(getX(),getY()) {
	this->sprite = sprite;
	sprite->incNumRef();
	this->x = x;
	this->y = y;

}

Character::~Character() {
	this->sprite->decNumRef();
	sprite = 0;
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


	if(this->y > 500){
		GameManager::currentScene->destroyGameObject(this);
	}

	return 0;
}
