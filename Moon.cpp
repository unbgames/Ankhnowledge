#include "Moon.h"

Moon::Moon(Sprite * sprite, Planeta * center,  int hitPoints) : Planeta(sprite, center->x, center->y, hitPoints){
	this->radius = (center->getSprite()->getHeight()/2);
	this->center = center;
	this->angle = 0;

}

int Moon::update(int dt){
	angle += 0.2*dt;

	x = center->x - (getSprite()->getHeight()/2) + radius + radius*cos(angle*PI/180);
	y = center->y - (getSprite()->getHeight()/2) + radius + radius*sin(angle*PI/180);

	return 0;
}

Moon::~Moon() {
	// TODO Auto-generated destructor stub
}

