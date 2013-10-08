/*
 * FadeScreen.cpp
 *
 *  Created on: Oct 3, 2013
 *      Author: makoto
 */

#include "FadeScreen.h"
#include <iostream>

FadeScreen::FadeScreen(Sprite* sprite, float x, float y) : GameObject (getSprite(),getX(),getY()) {
	this->sprite = sprite;
	sprite->incNumRef();
	fadeHandler = new FadeHandler(sprite);
	fadeHandler->fadeOut(0, 2);
}

FadeScreen::~FadeScreen() {
	delete fadeHandler;
	delete sprite;
}

int FadeScreen::update(int dt){
	fadeHandler->update(dt);
	return 0;
}

void FadeScreen::render(float cameraX, float cameraY){
	if(sprite)
		this->sprite->render(0,0);
}

