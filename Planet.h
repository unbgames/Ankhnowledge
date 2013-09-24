#ifndef PLANET_H_
#define PLANET_H_

#include "Sprite.h"

class Planet {
public:
	Planet(Sprite* sprite, float hitpoints, float x, float y);
	virtual ~Planet();
	void render();
	float getHitPoints();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	Sprite* getSprite();
	void setHitPoints(float hitpoints);
	float hitpoints;
private:
	Sprite* sprite;
	float x,y;


};

#endif /* PLANET_H_ */
