/*
 * SceneMainMenu.h
 *
 *  Created on: Oct 8, 2013
 *      Author: makoto
 */

#ifndef SCENEMAINMENU_H_
#define SCENEMAINMENU_H_
#include "Scene.h"
#include "Sprite.h"
#include "SplashScreen.h"
#include <string>

class SceneMainMenu : public Scene{
public:
	SceneMainMenu (string sceneName);
	virtual ~SceneMainMenu ();
	void Enter();
	void Exit();

private:
	Sprite * splashSprite;
};

#endif /* SCENEMAINMENU_H_ */
