/*
 * HoverButton.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: makoto
 */

#include "HoverButton.h"

HoverButton::HoverButton(Sprite* sprite, float x, float y):GameObject(x,y) {
	this->sprite = sprite;
	this->sprite->incNumRef();
	onTop = false;
	pressed = false;
	input = InputManager::getInstance();
}

HoverButton::~HoverButton() {
	this->sprite->decNumRef();
	sprite = 0;

}


void HoverButton::render(float cameraX, float cameraY){
	cameraX = x;
	cameraY = y;
	if(this->sprite) {
		this->sprite->render(cameraX, cameraY);
	}
}

int HoverButton::update(int dt){
	dt = 0;
	if(insideButton())
		onTop = true;
	else
		onTop = false;

	if(insideButton() && this->input->isMouseDown(dt))
	{
		pressed = true;
	}else
		pressed = false;

	return dt;
}

bool HoverButton::insideButton(){
	return ((this->input->mousePosX() > this->x) && (this->input->mousePosX() < (this->x + this->sprite->getWidth())) &&
			(this->input->mousePosY() > this->y) && (this->input->mousePosY() < (this->y + this->sprite->getHeight())));
}

bool HoverButton::isOnTop()
{
	return onTop;
}

bool HoverButton::isPressed()
{
	return pressed;
}

Sprite * HoverButton::getSprite()
{
	return this->sprite;
}



