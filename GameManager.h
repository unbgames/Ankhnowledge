
#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "Sprite.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "InputManager.h"
#include "AudioHandler.h"
#include "Network.h"
#include "GameObject.h"
#include "TileSet.h"
#include "TileMap.h"

class GameManager {
public:
	GameManager();
	virtual ~GameManager();
	void run();
	void processEvents();
	void update(int dt);
	void render(float cameraX, float cameraY);
	void initResources();

private:
	Sprite* bg;
	InputManager * input;
	AudioHandler * audio;
	Network * network;
	TileSet * tileSet;
	TileMap * tileMap;
	std::vector<GameObject*> gameObjects;
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
