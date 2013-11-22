
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
#include "Shape.h"
#include "FadeScreen.h"
#include "Scene.h"
#include "SceneLogo.h"
#include "SceneTechnology.h"
#include "SceneThirdParty.h"
#include "SceneLegal.h"
#include "SceneMainMenu.h"
#include "ScenePhaseOne.h"
#include "SceneGameOver.h"
#include "SceneCredits.h"
#include "SceneOptions.h"
#include "SceneSelectMap.h"
#include "SceneSelectCharacter.h"

class GameManager {
public:
	GameManager();
	virtual ~GameManager();
	void run();
	void processEvents();
	void update(int dt);
	void render(float cameraX, float cameraY);
	void initResources();
	static FadeScreen * fadeScreen;
	static Scene * currentScene;

private:
	Sprite* bg/*,*charOne,*charTwo*/;
	Scene * splashLogo;
	Scene * splashTechnology;
	Scene * splashThirdParty;
	Scene * splashLegal;
	Scene * splashMainMenu;
	Scene * splashPhaseOne;
	Scene * splashGameOver;
	Scene * splashCredits;
	Scene * splashOptions;
	Scene * splashConnect;
	Scene * splashSelectMap;
	Scene * splashSelectCharacter;


	InputManager * input;
	AudioHandler * audio;
	Shape* shape;
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
