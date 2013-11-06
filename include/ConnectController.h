/*
 * ConnectController.h
 *
 *  Created on: Nov 5, 2013
 *      Author: al
 */

#ifndef CONNECTCONTROLLER_H_
#define CONNECTCONTROLLER_H_
#include "GameObject.h"
#include "Sprite.h"
#include "InputManager.h"
#include "Animation.h"
#include <string>
#include <iostream>

using namespace std;

class ConnectController :public GameObject {
public:
	ConnectController();
	virtual ~ConnectController();
	void render(float cameraX, float cameraY);
	int update(int dt);
	bool isInsideBox(Sprite* currentSprite);
	void readInput();
	void backspace();

private:
	Animation* animation;
	Sprite* box,*boxInput,*bg,*cursor;
	InputManager* input;
	float boxInputX, boxInputY,boxX,boxY;
	SDL_Color color;
	TTF_Font *font;
	bool read;
	string message;
};

#endif /* CONNECTCONTROLLER_H_ */
