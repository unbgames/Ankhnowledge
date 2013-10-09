/*
 * Character.h
 *
 *  Created on: Oct 7, 2013
 *      Author: al
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "GameObject.h"
#include "Sprite.h"
#include "InputManager.h"
#include "GameManager.h"

class Character:public GameObject {
public:
	Character(Sprite* sprite, float x, float y);
	void render(float cameraX, float cameraY);
	int update(int dt);
	virtual ~Character();

private:
	Sprite* sprite;
	float x,y,vx,vy;
};

#endif /* CHARACTER_H_ */
