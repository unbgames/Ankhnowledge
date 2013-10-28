/*
 * SceneOptions.cpp
 *
 *  Created on: Oct 28, 2013
 *      Author: al
 */

#include "SceneOptions.h"

SceneOptions::SceneOptions(string sceneName) : Scene (sceneName)  {
	// TODO Auto-generated constructor stub

}

SceneOptions::~SceneOptions() {
	// TODO Auto-generated destructor stub
}

void SceneOptions::Enter()
{
	this->splashSprite = new Sprite(SDLBase::imagePath + "splashtechnology.png");
	this->sliderBar = new Sprite(SDLBase::imagePath + "slider_bar.png");
	this->sliderButton = new Sprite(SDLBase::imagePath + "slider_button.png");
	string nextScene = "SceneGameOver" ;
	SplashScreen * splashScreen =  new SplashScreen(splashSprite,nextScene);
	soundVolume = new Slider(sliderButton,sliderBar,100,100);
	this->addGameObject(splashScreen);
	this->addGameObject(soundVolume);

	GameManager::fadeScreen->fadeOut(0,2);
}

void SceneOptions::Exit()
{
	this->cleanGameObjects();
}

