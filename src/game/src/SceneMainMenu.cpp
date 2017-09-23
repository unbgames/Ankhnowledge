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
	AudioHandler * audio = AudioHandler::getInstance();
 	audio->stopMusic();
   	audio->setMusic("tema.ogg");
 	audio->playMusic(-1);

	buttons = new MainMenuButHandler();
	this->addGameObject(buttons);
	GameManager::fadeScreen->fadeOut(0,2);
}

void SceneMainMenu::Exit()
{
	this->cleanGameObjects();
}

