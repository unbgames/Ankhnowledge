/*
 * MainMenuButHandler.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: al
 */

#include "MainMenuButHandler.h"
#include "SDL/SDL_thread.h"

MainMenuButHandler::MainMenuButHandler():GameObject(getX(),getY()) {
	this->bt1_1 = new Sprite(SDLBase::resourcesPath + "host_1.png");
	this->bt1_1->incNumRef();
	this->bt1_2 = new Sprite(SDLBase::resourcesPath + "host_2.png");
	this->bt1_2->incNumRef();
	this->bt1_3 = new Sprite(SDLBase::resourcesPath + "host_3.png");
	this->bt1_3->incNumRef();
	this->bt2_1 = new Sprite(SDLBase::resourcesPath + "connect_1.png");
	this->bt2_1->incNumRef();
	this->bt2_2 = new Sprite(SDLBase::resourcesPath + "connect_2.png");
	this->bt2_2->incNumRef();
	this->bt2_3 = new Sprite(SDLBase::resourcesPath + "connect_3.png");
	this->bt2_3->incNumRef();
	this->bt3_1 = new Sprite(SDLBase::resourcesPath + "options_1.png");
	this->bt3_1->incNumRef();
	this->bt3_2 = new Sprite(SDLBase::resourcesPath + "options_2.png");
	this->bt3_2->incNumRef();
	this->bt3_3 = new Sprite(SDLBase::resourcesPath + "options_3.png");
	this->bt3_3->incNumRef();
	this->bt4_1 = new Sprite(SDLBase::resourcesPath + "credits_1.png");
	this->bt4_1->incNumRef();
	this->bt4_2 = new Sprite(SDLBase::resourcesPath + "credits_2.png");
	this->bt4_2->incNumRef();
	this->bt4_3 = new Sprite(SDLBase::resourcesPath + "credits_3.png");
	this->bt4_3->incNumRef();
	this->bt5_1 = new Sprite(SDLBase::resourcesPath + "quit_1.png");
	this->bt5_1->incNumRef();
	this->bt5_2 = new Sprite(SDLBase::resourcesPath + "quit_2.png");
	this->bt5_2->incNumRef();
	this->bt5_3 = new Sprite(SDLBase::resourcesPath + "quit_3.png");
	this->bt5_3->incNumRef();
	this->bt6_1 = new Sprite(SDLBase::resourcesPath + "ok_1.png");
	this->bt6_1->incNumRef();
	this->bt6_2 = new Sprite(SDLBase::resourcesPath + "ok_2.png");
	this->bt6_2->incNumRef();
	this->bt6_3 = new Sprite(SDLBase::resourcesPath + "ok_3.png");
	this->bt6_3->incNumRef();
	this->bt8_1 = new Sprite(SDLBase::resourcesPath + "cancel_1.png");
	this->bt8_1->incNumRef();
	this->bt8_2 = new Sprite(SDLBase::resourcesPath + "cancel_2.png");
	this->bt8_2->incNumRef();
	this->bt8_3 = new Sprite(SDLBase::resourcesPath + "cancel_3.png");
	this->bt8_3->incNumRef();

	this->bt1 = new Button(bt1_1,bt1_2,bt1_3,500,300);
	this->bt2 = new Button(bt2_1,bt2_2,bt2_3,500,350);
	this->bt3 = new Button(bt3_1,bt3_2,bt3_3,500,400);
	this->bt4 = new Button(bt4_1,bt4_2,bt4_3,500,450);
	this->bt5 = new Button(bt5_1,bt5_2,bt5_3,500,500);
	this->bt6 = new Button(bt6_1,bt6_2,bt6_3,500,300);
	this->bt7 = new Button(bt6_1,bt6_2,bt6_3,460,280);
	this->bt8 = new Button(bt8_1,bt8_2,bt8_3,430,280);
	this->bt6_1->incNumRef();
	this->bt6_2->incNumRef();
	this->bt6_3->incNumRef();
	this->splashSprite = new Sprite(SDLBase::resourcesPath + "titlebg.png");
	this->splashSprite->incNumRef();
	input = InputManager::getInstance();

	box = new Sprite(SDLBase::resourcesPath + "box.png");
	waiting = new Sprite(SDLBase::resourcesPath + "waiting.png");
	disconnect = new Sprite(SDLBase::resourcesPath + "disconnected.png");
	waiting->incNumRef();
	disconnect->incNumRef();
	this->box->incNumRef();
	boxInput = new Sprite(SDLBase::resourcesPath + "box_input.png");
	this->boxInput->incNumRef();
	bg = new Sprite(SDLBase::resourcesPath + "background.png");
	this->bg->incNumRef();
	cursor = new Sprite(SDLBase::resourcesPath + "cursor.png");
	this->cursor->incNumRef();
	this->animation = new Animation(18,45,cursor,0);
	input = InputManager::getInstance();
	this->boxX = 250;
	this->boxY = 200;
	this->boxInputX = boxX + box->getWidth()/2 - boxInput->getWidth()/2;
	this->boxInputY = boxY + 45;
	SDLBase::initializeSDLTTF();
	color.r = 0;
	color.g = 0;
	color.b = 0;
	string font_path = SDLBase::resourcesPath + "quicksandbold.ttf";
	font = SDLBase::loadFont(font_path.c_str(),25);
	read = false;
	tryToConnect = false;
	clickOtherButtons = true;
	message = "";
	sendMessage = false;
	host = false;
	thread = false;
	Network::cancel = true;
}

MainMenuButHandler::~MainMenuButHandler() {
	this->bt1_1->decNumRef();
	this->bt1_1 = 0;
	this->bt1_2->decNumRef();
	this->bt1_2 = 0;
	this->bt1_3->decNumRef();
	this->bt1_3 = 0;
	this->bt2_1->decNumRef();
	this->bt2_1 = 0;
	this->bt2_2->decNumRef();
	this->bt2_2 = 0;
	this->bt2_3->decNumRef();
	this->bt2_3 = 0;
	this->bt3_1->decNumRef();
	this->bt3_1 = 0;
	this->bt3_2->decNumRef();
	this->bt3_2 = 0;
	this->bt3_3->decNumRef();
	this->bt3_3 = 0;
	this->bt4_1->decNumRef();
	this->bt4_1 = 0;
	this->bt4_2->decNumRef();
	this->bt4_2 = 0;
	this->bt4_3->decNumRef();
	this->bt4_3 = 0;
	this->bt5_1->decNumRef();
	this->bt5_1 = 0;
	this->bt5_2->decNumRef();
	this->bt5_2 = 0;
	this->bt5_3->decNumRef();
	this->bt5_3 = 0;
	this->bt6_1->decNumRef();
	this->bt6_2->decNumRef();
	this->bt6_3->decNumRef();
	this->bt6_1->decNumRef();
	this->bt6_2->decNumRef();
	this->bt6_3->decNumRef();
	this->bt6_1 = 0;
	this->bt6_2 = 0;
	this->bt6_3 = 0;
	this->bt8_1->decNumRef();
	this->bt8_1 = 0;
	this->bt8_2->decNumRef();
	this->bt8_2 = 0;
	this->bt8_3->decNumRef();
	this->bt8_3 = 0;
	this->splashSprite->decNumRef();
	this->splashSprite = 0;
	this->box->decNumRef();
	this->box = 0;
	this->waiting->decNumRef();
	this->waiting = 0;
	this->disconnect->decNumRef();
	this->disconnect = 0;
	this->boxInput->decNumRef();
	this->boxInput = 0;
	this->bg->decNumRef();
	this->bg = 0;
	this->cursor->decNumRef();
	this->cursor = 0;
}

void MainMenuButHandler::render(float cameraX, float cameraY){
	this->splashSprite->render(0,0);
	this->bt1->render(0,0);
	this->bt2->render(0,0);
	this->bt3->render(0,0);
	this->bt4->render(0,0);
	this->bt5->render(0,0);

	if(tryToConnect)
		renderConnect();
	if(host)
		renderWaiting();
	if(Network::disconnected)
		renderDisconnect();
}

int MainMenuButHandler::update(int dt){
	mouseOver(bt1);
	mousePressed(bt1,"ScenePhaseOne");
	mouseOver(bt2);
	mousePressed(bt2,"SceneConnect");
	mouseOver(bt3);
	mousePressed(bt3,"SceneOptions");
	mouseOver(bt4);
	mousePressed(bt4,"SceneCredits");
	mouseOver(bt5);
	mousePressed(bt5,"Quit");
	mouseOver(bt6);
	mouseOver(bt7);
	mouseOver(bt8);

	this->bt1->update(dt);
	this->bt2->update(dt);
	this->bt3->update(dt);
	this->bt4->update(dt);
	this->bt5->update(dt);
	this->bt6->update(dt);
	this->bt7->update(dt);
	this->bt8->update(dt);
	if(tryToConnect)
		updateConnect(dt);
	updateDisconnect(dt);
	updateWaiting(dt);

	if(Network::connected && thread)
	{
		Network::receiveThread();
		if(GameManager::currentScene->changeScene("SceneSelectCharacter") == 1)
			GameManager::fadeScreen->fadeIn(1,2);
		thread = false;
		clickOtherButtons = true;
	}
	return 0;
}

void MainMenuButHandler::mouseOver(Button *bt){
	bt->setMouseCoord(input->mousePosX(),input->mousePosY());
	if((bt->insideButton() == 1) && (clickOtherButtons == false))
		bt->setChangeSprite(1);

}

void MainMenuButHandler::mousePressed(Button *bt,string scene){

	

	if((input->isMousePressed(1)) && (bt->insideButton()) == 1 && (clickOtherButtons == true))
	{
		bt->mousePressed(true);

		if(bt == bt1)
		{
			if(!host){
				Network::cancel = false;
				Network::host();
				host = true;
				thread = true;
				clickOtherButtons = false;
			}
		}else

		if(scene.compare("Quit") == 0){
			SDL_Event quit;
		    quit.type = SDL_QUIT;
			SDL_PushEvent( &quit );
		}
		else if(scene.compare("SceneConnect") == 0)
		{
			tryToConnect = true;
			clickOtherButtons = false;
			bt->setChangeSprite(0);
		}
		else if(bt->getChangeScene())
		{
			changeScene(scene);
			clickOtherButtons = false;
			bt->setChangeSprite(0);
		}
	}
	else
	{
		bt->mousePressed(false);
	}
}

void MainMenuButHandler::renderConnect(){
	box->render(boxX,boxY);
	//Render by the center
	boxInput->render(boxInputX,boxInputY);

	if(message.size() != 0)
	{
	SDLBase::renderText(font, message ,color,boxInputX + 5,boxInputY + 5);
	}
	else if(read){
		animation->animate(100, boxInputX + 5,boxInputY + 5);
	}

	if(sendMessage)
		SDLBase::renderText(font, "Mesangem Enviada IP: " + message ,color,150,400);
	bt6->render(0,0);

}

void MainMenuButHandler::renderDisconnect(){
	clickOtherButtons = false;
	disconnect->render(boxX,boxY);
	bt7->render(0,0);

}

void MainMenuButHandler::renderWaiting(){
	clickOtherButtons = false;
	waiting->render(boxX,boxY);
	bt8->render(0,0);
}

bool MainMenuButHandler::isInsideBox(Sprite* currentSprite){
	return ((input->mousePosX() > this->boxInputX) && (input->mousePosX() < (this->boxInputX + currentSprite->getWidth())) &&
					(input->mousePosY() > this->boxInputY) && (input->mousePosY() < (this->boxInputY + currentSprite->getHeight())));
}

void MainMenuButHandler::updateConnect(int dt){
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

	if((bt6->insideButton() == 1) && (input->isMousePressed(1)))
	{
		sendMessage = true;
		bt6->setChangeSprite(1);
		bt6->mousePressed(true);
		if(!Network::connected)
		{
			Network::connect(message);
			Network::receiveThread();
			if(GameManager::currentScene->changeScene("SceneSelectCharacter") == 1)
								GameManager::fadeScreen->fadeIn(1,2);
			/*Network::sendMessage(message);

					*/
		}
	}

	animation->update(dt, true,0,0);

}

void MainMenuButHandler::updateDisconnect(int dt){

	if((bt7->insideButton() == 1) && (input->isMousePressed(1)))
	{
		bt7->setChangeSprite(1);
		bt7->mousePressed(true);
		Network::disconnected = false;
		clickOtherButtons = true;
	}

}

void MainMenuButHandler::updateWaiting(int dt){
	if(SDL_mutexP(Network::mutex2) == 0)
	{

		if((bt8->insideButton() == 1) && (input->isMousePressed(1)) && !Network::cancel)
		{

			cout<<"cancel being called"<<endl;

			bt8->setChangeSprite(1);
			bt8->mousePressed(true);
			clickOtherButtons = true;
			host = false;
			thread = false;
			Network::closeConnection();
			Network::cancel = true;


		}

			SDL_mutexV(Network::mutex2);
	}
}

void MainMenuButHandler::readInput(){
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

void MainMenuButHandler::backspace(){
	if(input->isKeyUp(SDLK_BACKSPACE))
		message = message.substr(0, message.size()-1);
}

void MainMenuButHandler::changeScene(string nextScene){
	if(GameManager::currentScene->changeScene(nextScene) == 1)
		GameManager::fadeScreen->fadeIn(1,0.2);
}

