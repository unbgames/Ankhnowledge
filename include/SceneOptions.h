/*
 * SceneOptions.h
 *
 *  Created on: Oct 28, 2013
 *      Author: al
 */

#ifndef SCENEOPTIONS_H_
#define SCENEOPTIONS_H_
#include "Scene.h"
#include "Sprite.h"
#include "SplashScreen.h"
#include "Slider.h"
#include <string>


class SceneOptions : public Scene {
public:
	SceneOptions(string sceneName);
	virtual ~SceneOptions();
	void Enter();
	void Exit();

private:
	Sprite * splashSprite,*sliderBar,*sliderButton;
	Slider * soundVolume;
};

#endif /* SCENEOPTIONS_H_ */
