/*
 * SceneSelectCharacter.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: makoto
 */

#include "SceneSelectCharacter.h"
#include <string>
SceneSelectCharacter::SceneSelectCharacter(string sceneName) : Scene (sceneName) {

}

SceneSelectCharacter::~SceneSelectCharacter() {
}

void SceneSelectCharacter::Enter()
{
	cc = new SelectCharacterController();
		this->addGameObject(cc);
	GameManager::fadeScreen->fadeOut(0,2);
}

void SceneSelectCharacter::Exit()
{
	this->cleanGameObjects();
}

