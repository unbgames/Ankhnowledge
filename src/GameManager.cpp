
#include "GameManager.h"
#include <iostream>
#include <sstream>
#include <memory>
using namespace std;

/*
 * Construtor da Classe
 * Antes de carregar a imagem e necessario inicialiar o SDL, uma vez que o construtor
 * do Sprite faz uso do metodo SDLBase::loadImage(char * arquivo), que faz uso das
 * funcoes SDL_DisplayFormat e SDL_DisplayFormaAlpha. Funcoes estas que precisam
 */
GameManager::GameManager() {
	//srand ( time(NULL) );
	SDLBase::initializeSDL();
	initResources();

}

/*
 * Destrutor da Clase
 */
GameManager::~GameManager() {
	delete (bg);
}

//Metodo que inicializa os objetos (recursos) do jogo
void GameManager::initResources(){
	this->bg = new Sprite("../Ankhnowledge/resources/images/background.png");
	this->fade = new Sprite("../Ankhnowledge/resources/images/Black.bmp");
	this->charSprite = new Sprite("../Ankhnowledge/resources/images/charac.png");
	this->charOne= new Character(charSprite,0,66);
	this->charTwo= new Character(charSprite,704,66);
	this->shape = new Shape();
	this->fadeScreen = new FadeScreen(fade,SDLBase::getScreen()->w, SDLBase::getScreen()->h);
	input = InputManager::getInstance();
	audio = AudioHandler::getInstance();
	network = Network::getInstance();
	dt = 0;
	frameStart = 0;
	frameEnd = 0;

}


// Metodo que realiza o game loop

void GameManager::processEvents(){
	// procura um event
	input->Update();
	if(input->QuitGame()){
		SDL_Event quit;
		quit.type = SDL_QUIT;
		SDL_PushEvent( &quit );
	}

	if(input->isKeyDown(SDLK_ESCAPE)){
		// se a tecla ESC foi pressionada, sair do programa
		SDL_Event quit;
	    quit.type = SDL_QUIT;
	    SDL_PushEvent( &quit );
	}


	if( input->isKeyDown(SDLK_UP) )
		cameraSpeedY -= SCROLL;
	if( input->isKeyDown(SDLK_DOWN) )
		cameraSpeedY += SCROLL;
	if( input->isKeyDown(SDLK_LEFT) )
		cameraSpeedX -= SCROLL;
	if( input->isKeyDown(SDLK_RIGHT) )
		cameraSpeedX += SCROLL;

	if( input->isKeyUp(SDLK_UP) )
		cameraSpeedY += SCROLL;
	if( input->isKeyUp(SDLK_DOWN) )
		cameraSpeedY -= SCROLL;
	if( input->isKeyUp(SDLK_LEFT) )
		cameraSpeedX += SCROLL;
	if( input->isKeyUp(SDLK_RIGHT) )
		cameraSpeedX -= SCROLL;

}

void GameManager::update(int dt){
	fadeScreen->update(dt);
	charOne->update(dt);
	audio->update();
	cameraX1 += cameraSpeedX;
	cameraY1 += cameraSpeedY;
}

void GameManager::render(float cameraX, float cameraY){
	bg->render(0,0);

	//Draw blocks
	shape->fillRect(528,531,88,66,0xBDB76B);
	shape->fillRect(528,465,88,66,0xBDB76B);
	shape->fillRect(528,399,88,66,0xBDB76B);
	shape->fillRect(440,399,88,66,0xBDB76B);
	shape->fillRect(176,531,88,66,0xBDB76B);
	shape->fillRect(176,465,88,66,0xBDB76B);
	shape->fillRect(176,399,88,66,0xBDB76B);
	shape->fillRect(264,399,88,66,0xBDB76B);
	shape->fillRect(352,399,88,66,0xBDB76B);
	shape->fillRect(352,333,88,66,0xBDB76B);
	shape->fillRect(352,267,88,66,0xBDB76B);
	shape->fillRect(352,201,88,66,0xBDB76B);
	shape->fillRect(264,201,88,66,0xBDB76B);
	shape->fillRect(176,201,88,66,0xBDB76B);
	shape->fillRect(88,201,88,66,0xBDB76B);
	shape->fillRect(440,201,88,66,0xBDB76B);
	shape->fillRect(528,201,88,66,0xBDB76B);
	shape->fillRect(616,201,88,66,0xBDB76B);
	shape->fillRect(616,135,88,66,0xBDB76B);
	shape->fillRect(616,69,88,66,0xBDB76B);
	shape->fillRect(616,3,88,66,0xBDB76B);
	shape->fillRect(88,135,88,66,0xBDB76B);
	shape->fillRect(88,69,88,66,0xBDB76B);
	shape->fillRect(88,3,88,66,0xBDB76B);
	//Draw grid
	shape->drawLine(88,0,88,600,0x00,0);
	shape->drawLine(176,0,176,600,0x00,0);
	shape->drawLine(264,0,264,600,0x00,0);
	shape->drawLine(352,0,352,600,0x00,0);
	shape->drawLine(440,0,440,600,0x00,0);
	shape->drawLine(528,0,528,600,0x00,0);
	shape->drawLine(616,0,616,600,0x00,0);
	shape->drawLine(704,0,704,600,0x00,0);
	shape->drawLine(0,66,800,66,0x00,0);
	shape->drawLine(0,132,800,132,0x00,0);
	shape->drawLine(0,198,800,198,0x00,0);
	shape->drawLine(0,264,800,264,0x00,0);
	shape->drawLine(0,330,800,330,0x00,0);
	shape->drawLine(0,396,800,396,0x00,0);
	shape->drawLine(0,66,800,66,0x00,0);
	shape->drawLine(0,462,800,462,0x00,0);
	shape->drawLine(0,528,800,528,0x00,0);
	//Draw circle
	shape->drawCircle(20,400,570,139,0,0);
	//Characters
	charOne->render(0,0);
	charTwo->render(0,0);

	fadeScreen->render(0,0);
}

void GameManager::run(){

	while(!SDL_QuitRequested()){
		frameStart = SDL_GetTicks();
		dt = frameStart - frameEnd;
		if(dt >= 1000/30){
			/* Captura de Input*/
			processEvents();

			/*Realizar Update*/
			update(dt);

			/*Renderizar os objetos*/
			render(cameraX1, cameraY1);

			/*Atualizar a tela*/
			SDLBase::updateScreen();
			network->sendMessage();
			network->receiveMessage();
			frameEnd = SDL_GetTicks();
		}else{
			SDL_Delay(1000/30 -dt);
		}
	}
}
