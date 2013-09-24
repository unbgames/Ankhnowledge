
#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "Sprite.h"
#include "Planet.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TileSet.h"
#include "TileMap.h"
#include "InputManager.h"
#include "PlanetRed.h"
#include "Earth.h"
#include "Moon.h"
#include "FollowerObject.h"

class GameManager {
public:
	GameManager();
	virtual ~GameManager();
	void run();
	void addPlanet();
	void checkPlanets();
	void processEvents();
	void update(int dt);
	void render(float cameraX, float cameraY);

private:
	Sprite* bg;
	Sprite* planetSprite;
	Sprite* earthSprite;
	Sprite* moonSprite;
	Sprite* ufo;
	FollowerObject * fo;
	Earth * earth;
	Moon * moon;
	std::vector<Planeta*> planetArray;
	TileSet * tileSet;
	TileMap * tileMap;
	InputManager * input;
	float SCROLL;
	float cameraX1;
	float cameraX2;
	float cameraY1;
	float cameraY2;
	float cameraSpeedX;
	float cameraSpeedY;
	float fatorParallaxScrolling;
	int dt, frameStart, frameEnd;

};

#endif /* GAMEMANAGER_H_ */
