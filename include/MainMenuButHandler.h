/*
 * MainMenuButHandler.h
 *
 *  Created on: Oct 9, 2013
 *      Author: al
 */

#ifndef MAINMENUBUTHANDLER_H_
#define MAINMENUBUTHANDLER_H_
#include "GameObject.h"
#include "Button.h"
#include "Sprite.h"
#include "InputManager.h"
#include "GameManager.h"
#include <iostream>
#include <string>

using namespace std;

class MainMenuButHandler:public GameObject {
public:
	MainMenuButHandler();
	virtual ~MainMenuButHandler();
	void render(float cameraX, float cameraY);
	int update(int dt);
	void mouseOver(Button* bt);
	void mousePressed(Button* bt,string nextScene);
	void changeScene(string nextScene);

private:
	Button* bt1,* bt2, *bt3, *bt4,*bt5;
	Sprite* bt1_1,*bt1_2,*bt1_3;
	Sprite* bt2_1,*bt2_2,*bt2_3;
	Sprite *bt3_1,*bt3_2,*bt3_3;
	Sprite *bt4_1,*bt4_2,*bt4_3;
	Sprite *bt5_1,*bt5_2,*bt5_3,*splashSprite;
	InputManager* input;
};

#endif /* MAINMENUBUTHANDLER_H_ */
