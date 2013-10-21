/*
 * MainMenuButHandler.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: al
 */

#include "MainMenuButHandler.h"

MainMenuButHandler::MainMenuButHandler():GameObject(getX(),getY()) {
	this->bt1_1 = new Sprite("../Ankhnowledge/resources/images/host_2.png");
	this->bt1_2 = new Sprite("../Ankhnowledge/resources/images/host_1.png");
	this->bt1_3 = new Sprite("../Ankhnowledge/resources/images/host_3.png");
	this->bt2_1 = new Sprite("../Ankhnowledge/resources/images/connect_2.png");
	this->bt2_2 = new Sprite("../Ankhnowledge/resources/images/connect_1.png");
	this->bt2_3 = new Sprite("../Ankhnowledge/resources/images/connect_3.png");
	this->bt3_1 = new Sprite("../Ankhnowledge/resources/images/options_2.png");
	this->bt3_2 = new Sprite("../Ankhnowledge/resources/images/options_1.png");
	this->bt3_3 = new Sprite("../Ankhnowledge/resources/images/options_3.png");
	this->bt4_1 = new Sprite("../Ankhnowledge/resources/images/credits_2.png");
	this->bt4_2 = new Sprite("../Ankhnowledge/resources/images/credits_1.png");
	this->bt4_3 = new Sprite("../Ankhnowledge/resources/images/credits_3.png");
	this->bt5_1 = new Sprite("../Ankhnowledge/resources/images/quit_2.png");
	this->bt5_2 = new Sprite("../Ankhnowledge/resources/images/quit_1.png");
	this->bt5_3 = new Sprite("../Ankhnowledge/resources/images/quit_3.png");


	this->bt1 = new Button(bt1_1,bt1_2,bt1_3,500,300);
	this->bt2 = new Button(bt2_1,bt2_2,bt2_3,500,350);
	this->bt3 = new Button(bt3_1,bt3_2,bt3_3,500,400);
	this->bt4 = new Button(bt4_1,bt4_2,bt4_3,500,450);
	this->bt5 = new Button(bt5_1,bt5_2,bt5_3,500,500);
	this->splashSprite = new Sprite("../Ankhnowledge/resources/images/titlebg.png");
	input = InputManager::getInstance();

}

MainMenuButHandler::~MainMenuButHandler() {
	// TODO Auto-generated destructor stub
}

void MainMenuButHandler::render(float cameraX, float cameraY){
	this->splashSprite->render(0,0);
	this->bt1->render(0,0);
	this->bt2->render(0,0);
	this->bt3->render(0,0);
	this->bt4->render(0,0);
	this->bt5->render(0,0);

}

int MainMenuButHandler::update(int dt){
	mouseOver(bt1);
	mousePressed(bt1,"ScenePhaseOne");
	mouseOver(bt2);
	mousePressed(bt2,"ScenePhaseOne");
	mouseOver(bt3);
	mousePressed(bt3,"ScenePhaseOne");
	mouseOver(bt4);
	mousePressed(bt4,"ScenePhaseOne");
	mouseOver(bt5);
	mousePressed(bt5,"Quit");
	this->bt1->update(dt);
	this->bt2->update(dt);
	this->bt3->update(dt);
	this->bt4->update(dt);
	this->bt5->update(dt);
	return 0;
}

void MainMenuButHandler::mouseOver(Button *bt){
	bt->setMouseCoord(input->mousePosX(),input->mousePosY());
}

void MainMenuButHandler::mousePressed(Button *bt,string scene){

	if(input->isMousePressed(1) && bt->insideButton() == 1)
	{
		bt->mousePressed(true);

		if(scene.compare("Quit") == 0){
			SDL_Event quit;
		    quit.type = SDL_QUIT;
			SDL_PushEvent( &quit );
		}
		else if(bt->getChangeScene())
		{
			changeScene(scene);
		}
	}
	else
	{
		bt->mousePressed(false);
	}
}

void MainMenuButHandler::changeScene(string nextScene){
	if(GameManager::currentScene->changeScene(nextScene) == 1)
		GameManager::fadeScreen->fadeIn(1,2);
}
