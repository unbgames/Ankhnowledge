/*
 * ConnectController.cpp
 *
 *  Created on: Nov 5, 2013
 *      Author: al
 */

#include "ConnectController.h"

ConnectController::ConnectController() :GameObject(getX(),getY()){
	// TODO Auto-generated constructor stub
	box = new Sprite(SDLBase::imagePath + "box.png");
	boxInput = new Sprite(SDLBase::imagePath + "box_input.png");
	bg = new Sprite(SDLBase::imagePath + "background.png");
	cursor = new Sprite(SDLBase::imagePath + "cursor.png");
	this->animation = new Animation(18,45,cursor,0);
	input = InputManager::getInstance();
	this->boxX = 250;
	this->boxY = 200;
	this->boxInputX = boxX + box->getWidth()/2 - boxInput->getWidth()/2;
	this->boxInputY = boxY + 50;
	SDLBase::initializeSDLTTF();
	color.r = 0;
	color.g = 0;
	color.b = 0;
	string font_path = SDLBase::imagePath + "aeolus.ttf";
	font = SDLBase::loadFont(font_path.c_str(),40);
	read = false;
	message = "";

}

ConnectController::~ConnectController() {
	// TODO Auto-generated destructor stub
}

void ConnectController::render(float cameraX, float cameraY){
	bg->render(0,0);
	box->render(boxX,boxY);
	//Render by the center
	boxInput->render(boxInputX,boxInputY);

	if(message.size() != 0)
	{
	SDLBase::renderText(font, message ,color,boxInputX + 10,boxInputY);
	}
	else if(read){
		animation->animate(400, boxInputX,boxInputY);
	}

	SDLBase::renderText(font, "IP: " + message ,color,150,105);

}

int ConnectController::update(int dt){

	if(isInsideBox(boxInput) == true && (input->isMousePressed(1)))
	{
		read = true;
	}
	else if(isInsideBox(boxInput) == false && (input->isMousePressed(1)))
	{
		read = false;
	}

	if(read)
	{
		if (message.size() < 15)
		{
			readInput();
		}
		else
		{
			backspace();
		}
	}
	animation->update(dt, true,0);
	return 0;
}

void ConnectController::readInput(){
	if(input->isKeyUp(SDLK_0))
		message = message + "0";
	if(input->isKeyUp(SDLK_1))
			message = message + "1";
	if(input->isKeyUp(SDLK_2))
			message = message + "2";
	if(input->isKeyUp(SDLK_3))
			message = message + "3";
	if(input->isKeyUp(SDLK_4))
			message = message + "4";
	if(input->isKeyUp(SDLK_5))
			message = message + "5";
	if(input->isKeyUp(SDLK_6))
			message = message + "6";
	if(input->isKeyUp(SDLK_7))
			message = message + "7";
	if(input->isKeyUp(SDLK_8))
			message = message + "8";
	if(input->isKeyUp(SDLK_9))
			message = message + "9";
	if(input->isKeyUp(SDLK_PERIOD))
			message = message + ".";
	backspace();

}

void ConnectController::backspace(){
	if(input->isKeyUp(SDLK_BACKSPACE))
		message = message.substr(0, message.size()-1);

}

bool ConnectController::isInsideBox(Sprite* currentSprite){
	return ((input->mousePosX() > this->boxInputX) && (input->mousePosX() < (this->boxInputX + currentSprite->getWidth())) &&
				(input->mousePosY() > this->boxInputY) && (input->mousePosY() < (this->boxInputY + currentSprite->getHeight())));
}

