/*
 * SceneConnect.cpp
 *
 *  Created on: Nov 5, 2013
 *      Author: al
 */

#include "SceneConnect.h"

SceneConnect::SceneConnect(string sceneName) : Scene (sceneName) {
	// TODO Auto-generated constructor stub

}

SceneConnect::~SceneConnect() {
	// TODO Auto-generated destructor stub
}

void SceneConnect::Enter()
{
	this->cc = new ConnectController();
	this->addGameObject(cc);

	GameManager::fadeScreen->fadeOut(0,2);
}

void SceneConnect::Exit()
{
	this->cleanGameObjects();
}

