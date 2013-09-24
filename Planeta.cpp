#include "Planeta.h"
#include <iostream>
using namespace std;
Planeta::Planeta(Sprite * sprite, float x, float y, int hitPoints) : GameObject (x,y) {
	this->sprite = NULL;
	this->sprite = sprite;
	this->hitPoints = hitPoints;
}


Planeta::~Planeta() {
	// TODO Auto-generated destructor stub
}

void Planeta::render(float cameraX, float cameraY){
	if(sprite)
	this->sprite->render((this->x - cameraX), (this->y - cameraY));
}

Sprite * Planeta::getSprite(){
	return sprite;
}
