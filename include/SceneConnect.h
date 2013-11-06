/*
 * SceneConnect.h
 *
 *  Created on: Nov 5, 2013
 *      Author: al
 */

#ifndef SCENECONNECT_H_
#define SCENECONNECT_H_
#include "Scene.h"
#include "Sprite.h"
#include "SplashScreen.h"
#include "ConnectController.h"
#include <string>

class SceneConnect : public Scene {
public:
	SceneConnect(string sceneName);
	virtual ~SceneConnect();
	void Enter();
	void Exit();

private:
	ConnectController* cc;
};

#endif /* SCENECONNECT_H_ */
