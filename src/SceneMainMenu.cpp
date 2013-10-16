/*
 * SceneMainMenu.cpp
 *
 *  Created on: Oct 8, 2013
 *      Author: makoto
 */

#include "SceneMainMenu.h"

SceneMainMenu::SceneMainMenu(string sceneName) : Scene (sceneName) {

}

SceneMainMenu::~SceneMainMenu() {
}

void SceneMainMenu::Enter()
{

	string nextScene = "ScenePhaseOne" ;
	//SplashScreen * splashScreen =  new SplashScreen(splashSprite,nextScene);
	buttons = new MainMenuButHandler();
	this->addGameObject(buttons);
	GameManager::fadeScreen->fadeOut(0,0.001);
}

void SceneMainMenu::Exit()
{
	this->cleanGameObjects();
}

