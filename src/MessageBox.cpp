/*
 * MessageBox.cpp
 *
 *  Created on: Dec 3, 2013
 *      Author: al
 */

#include "MessageBox.h"

using namespace std;

MessageBox::MessageBox(Sprite * box, string buttonName, float x, float y):GameObject(getX(),getY()){
	this->box = box;	
	Sprite* confirm_1 = new Sprite(SDLBase::resourcesPath + buttonName + "_1.png");
	Sprite* confirm_2 = new Sprite(SDLBase::resourcesPath + buttonName + "_2.png");
	Sprite* confirm_3 = new Sprite(SDLBase::resourcesPath + buttonName + "_3.png");
	this->confirm = new Button(confirm_1,confirm_2,confirm_3,x,y);
	this->cancel = 0;
	input = InputManager::getInstance();
	this->confirmPress = false;
	this->cancelPress = false;

}

MessageBox::MessageBox(Sprite * box, string buttonName1, string buttonName2, float x, float y):GameObject(getX(),getY()){

	this->box = box;
	Sprite* confirm_1 = new Sprite(SDLBase::resourcesPath + buttonName1 + "_1.png");
	Sprite* confirm_2 = new Sprite(SDLBase::resourcesPath + buttonName1 + "_2.png");
	Sprite* confirm_3 = new Sprite(SDLBase::resourcesPath + buttonName1 + "_3.png");
	this->confirm = new Button(confirm_1,confirm_2,confirm_3,x,y);
	Sprite* cancel_1 = new Sprite(SDLBase::resourcesPath + buttonName2 + "_1.png");
	Sprite* cancel_2 = new Sprite(SDLBase::resourcesPath + buttonName2 + "_2.png");
	Sprite* cancel_3 = new Sprite(SDLBase::resourcesPath + buttonName2 + "_3.png");
	this->cancel = new Button(cancel_1,cancel_2,cancel_3,x - 150,y);
	input = InputManager::getInstance();
	this->confirmPress = false;
	this->cancelPress = false;
}

MessageBox::~MessageBox(){

}


void MessageBox::render(float cameraX, float cameraY){
	box->render(250,200);	
	if(confirm)
		confirm->render(0,0);

	if(cancel)
		cancel->render(0,0);
	
}

int MessageBox::update(int dt){
	
	if(confirm)
	{
		mouseOver(confirm);
		buttonPressed(confirm,"confirm");
		confirm->update(dt);
		
	}

	if(cancel)
	{
		mouseOver(cancel);
		buttonPressed(cancel,"cancel");
		cancel->update(dt);
	}

return 0;
}

void MessageBox::buttonPressed(Button *bt, string buttonName){

if((input->isMousePressed(1)) && (bt->insideButton()) == 1)
{
	bt->mousePressed(true);
	if(buttonName == "confirm")
		confirmPress = true;
	else
		cancelPress = true;
	bt->setChangeSprite(1);
}
else {
	bt->mousePressed(false);
}
 

}

void MessageBox::deactivateCancel(){
	this->cancelPress = false;
}

void MessageBox::mouseOver(Button *bt){
	bt->setMouseCoord(input->mousePosX(),input->mousePosY());
	if((bt->insideButton() == 1))		
		bt->setChangeSprite(1);

}

bool MessageBox::confirmPressed(){
	return this->confirmPress;
}

bool MessageBox::cancelPressed(){
	return this->cancelPress;
}
