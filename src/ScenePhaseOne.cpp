/*
 * ScenePhaseOne.cpp
 *
 *  Created on: Oct 8, 2013
 *      Author: al
 */

#include "ScenePhaseOne.h"
#include "AudioHandler.h"

ScenePhaseOne::ScenePhaseOne(string sceneName) : Scene (sceneName) {


}

ScenePhaseOne::~ScenePhaseOne() {
	// TODO Auto-generated destructor stub
}

void ScenePhaseOne::Enter()
{
	AudioHandler * audio = AudioHandler::getInstance();
	audio->stopMusic();
	audio->setMusic("intro.ogg");
	audio->playMusic(1);


	this->splashSprite = new Sprite(SDLBase::imagePath + "interface.png");
	this->tile = new Sprite(SDLBase::imagePath + "tile.png");
	this->block = new Sprite(SDLBase::imagePath + "areiamovedicabloco.png");
	this->map = new Map(tile, block, 200, 100);
	string nextScene = "ScenePhaseOne" ;
	SplashScreen * splashScreen =  new SplashScreen(splashSprite,nextScene);
	this->addGameObject(splashScreen);
	this->addGameObject(map);
	GameManager::fadeScreen->fadeOut(0,2);
}

void ScenePhaseOne::Exit()
{
	this->cleanGameObjects();
}

