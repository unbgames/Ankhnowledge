/*
 * SceneCredits.cpp
 *
 *  Created on: Oct 28, 2013
 *      Author: al
 */

#include "SceneCredits.h"

SceneCredits::SceneCredits(string sceneName) : Scene (sceneName)  {
	// TODO Auto-generated constructor stub

}

SceneCredits::~SceneCredits() {
	// TODO Auto-generated destructor stub
}

void SceneCredits::Enter()
{
	this->splashSprite = new Sprite(SDLBase::imagePath + "splashlogo.png");
	string nextScene = "SceneGameOver" ;
	SplashScreen * splashScreen =  new SplashScreen(splashSprite,nextScene);
	this->addGameObject(splashScreen);
	GameManager::fadeScreen->fadeOut(0,2);
}

void SceneCredits::Exit()
{
	this->cleanGameObjects();
}

