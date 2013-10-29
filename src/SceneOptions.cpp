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
	this->oc = new OptionsController();
	this->addGameObject(oc);

	GameManager::fadeScreen->fadeOut(0,2);
}

void SceneOptions::Exit()
{
	this->cleanGameObjects();
}

