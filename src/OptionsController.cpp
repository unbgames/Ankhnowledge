/*
 * OptionsController.cpp
 *
 *  Created on: Oct 28, 2013
 *      Author: al
 */

#include "OptionsController.h"
#include <iostream>
#include <sstream>

OptionsController::OptionsController():GameObject(getX(),getY()) {
	this->back_1 = new Sprite(SDLBase::imagePath + "quit_1.png");
	this->back_2 = new Sprite(SDLBase::imagePath + "quit_2.png");
	this->back_3 = new Sprite(SDLBase::imagePath + "quit_3.png");
	this->back = new Button(back_1,back_2,back_3,500,500);
	this->sliderBar = new Sprite(SDLBase::imagePath + "slider_bar.png");
	this->sliderButton = new Sprite(SDLBase::imagePath + "slider_button.png");
	bgVolume = new Slider(sliderButton,sliderBar,400,100);
	soundEffect = new Slider(sliderButton,sliderBar,400,300);
	this->splashSprite = new Sprite(SDLBase::imagePath + "background.png");
	input = InputManager::getInstance();
	SDLBase::initializeSDLTTF();
	color = {0, 0, 0, 255};
	string font_path = SDLBase::imagePath + "aeolus.ttf";
	font = SDLBase::loadFont(font_path.c_str(),40);

}

OptionsController::~OptionsController() {
	// TODO Auto-generated destructor stub
}

void OptionsController::render(float cameraX, float cameraY){
	this->splashSprite->render(0,0);
	this->back->render(0,0);
	this->bgVolume->render(0,0);
	this->soundEffect->render(0,0);
	SDLBase::renderText(font,"Background music volume",color,10,90);
	stringstream ssbgvolume;
	ssbgvolume << ((int)(100*bgVolume->calculateValue()));
	SDLBase::renderText(font, ssbgvolume.str() + "%" ,color,720,90);

	SDLBase::renderText(font,"Sound effect volume",color,10,290);
	stringstream sssoundeffect;
	sssoundeffect << ((int)(100*soundEffect->calculateValue()));
	SDLBase::renderText(font, sssoundeffect.str() + "%" ,color,720,290);


}

int OptionsController::update(int dt){
	mouseOver(back);
	mousePressed(back,"SceneMainMenu");
	this->back->update(dt);
	this->bgVolume->update(dt);
	this->soundEffect->update(dt);
	return 0;
}

void OptionsController::mouseOver(Button *bt){
	bt->setMouseCoord(input->mousePosX(),input->mousePosY());
}

void OptionsController::mousePressed(Button *bt,string scene){

	if(input->isMousePressed(1) && bt->insideButton() == 1)
	{
		bt->mousePressed(true);

		if(bt->getChangeScene())
		{
			changeScene(scene);
		}
	}
	else
	{
		bt->mousePressed(false);
	}
}

void OptionsController::changeScene(string nextScene){
	if(GameManager::currentScene->changeScene(nextScene) == 1)
		GameManager::fadeScreen->fadeIn(1,0.2);
}
