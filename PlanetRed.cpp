#include "PlanetRed.h"
#include <iostream>

using namespace std;

PlanetRed::PlanetRed(Sprite * sprite, float x, float y, int hitPoints) : Planeta(sprite, x, y, hitPoints){
}

PlanetRed::~PlanetRed() {
	// TODO Auto-generated destructor stub
}

int PlanetRed::update(int dt){
	Sprite * sprite = getSprite();
	InputManager * input = InputManager::getInstance();
	SDL_Rect area;
	area.x = this->x;
	area.y = this->y;
	area.w = sprite->getWidth();
	area.h = sprite->getHeight();

	if(input->isMouseDown(0)){
		if(input->isMouseInside(&area)){
			float hitpoints = this->hitPoints - (rand() % 10 + 10);
		    hitPoints = hitpoints;
		}
	}
	return 0;
}

