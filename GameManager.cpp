
#include "GameManager.h"
#include <iostream>
#include <sstream>
using namespace std;

/*
 * Construtor da Classe
 * Antes de carregar a imagem e necessario inicialiar o SDL, uma vez que o construtor
 * do Sprite faz uso do metodo SDLBase::loadImage(char * arquivo), que faz uso das
 * funcoes SDL_DisplayFormat e SDL_DisplayFormaAlpha. Funcoes estas que precisam
 */
GameManager::GameManager() {
	srand ( time(NULL) );
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
	this->bg = new Sprite("resources/images/fundo.png");
	this->tileSet = new TileSet(75, 75, "resources/images/Tileset.png");
	this->tileMap = new TileMap("resources/images/tileMap.txt", 16, tileSet);
	input = InputManager::getInstance();
	audio = AudioHandler::getInstance();
	network = Network::getInstance();

	this->SCROLL = 0.1;
	cameraX1 = 0;
	cameraY1 = 0;
	cameraX2 = 0;
	cameraY2 = 0;
	cameraSpeedX = 0;
	cameraSpeedY = 0;
	fatorParallaxScrolling = 1.1;
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
	audio->update();
	cameraX1 += cameraSpeedX;
	cameraY1 += cameraSpeedY;
}

void GameManager::render(float cameraX, float cameraY){
	bg->render(0,0);
	this->tileMap->renderLayer(cameraX, cameraY, 0);
	this->tileMap->renderLayer(cameraX*fatorParallaxScrolling, cameraY*fatorParallaxScrolling, 1);
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
