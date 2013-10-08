/*
 * FadeScreen.h
 *
 *  Created on: Oct 3, 2013
 *      Author: makoto
 */

#ifndef FADESCREEN_H_
#define FADESCREEN_H_
#include "GameObject.h"
#include "Sprite.h"
#include "FadeHandler.h"

class FadeScreen : GameObject {
public:
	FadeScreen(Sprite* sprite, float x, float y);
	virtual ~FadeScreen();
	int update(int dt);
	void render(float cameraX, float cameraY);

private:
	Sprite * sprite;
	FadeHandler * fadeHandler;
};

#endif /* FADESCREEN_H_ */
