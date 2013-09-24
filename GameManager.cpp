
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
	SDLBase::inicilizaSDL();
	this->bg = new Sprite("resources/fundo.png");
	this->planetSprite = new Sprite("resources/PlanetaVermelho.png");
	this->earthSprite = new Sprite("resources/PlanetaTerra.png");
	this->moonSprite = new Sprite("resources/Lua.png");

	this->ufo = new Sprite("resources/ufo.png");

	this->tileSet = new TileSet(75, 75, "resources/Tileset.png");

	this->tileMap = new TileMap("resources/tileMap.txt", 16, tileSet);

	this->SCROLL = 0.1;
	cameraX1 = 0;
	cameraY1 = 0;
	cameraX2 = 0;
	cameraY2 = 0;
	cameraSpeedX = 0;
	cameraSpeedY = 0;
	fatorParallaxScrolling = 1.1;

	input = InputManager::getInstance();

	dt = 0;
	frameStart = 0;
	frameEnd = 0;

	earth = new Earth( earthSprite, 50,50, 100);
	moon = new Moon(moonSprite,earth,100);

	fo = new FollowerObject(ufo,100,100);

}

/*
 * Destrutor da Clase
 */
GameManager::~GameManager() {
	delete (bg);
}

/*
 * Metodo que realiza o game loop
 */

void GameManager::addPlanet(){

	int hitpoints = rand()%20 + 1;
	int x = rand()%(800 - planetSprite->getWidth());
	int y = rand()%(600 - planetSprite->getHeight());
	Planeta* planet = new PlanetRed(planetSprite, x,y,hitpoints);
	this->planetArray.push_back(planet);
}

void GameManager::checkPlanets(){
	Planeta* planet = NULL;
	for(vector<Planeta*>::iterator it = planetArray.end() - 1;
		                                        it != planetArray.begin() - 1; --it) {
		planet = *it;
				if(planet->hitPoints <= 0){
					planetArray.erase(it);
				}
	}
}

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

	if(input->isMousePressed(3)){
		fo->enqueueCommand(input->mousePosX(), input->mousePosY());
	}

	if( input->isKeyDown(SDLK_UP) )
		cameraSpeedY -= SCROLL;
	if( input->isKeyDown(SDLK_DOWN) )
		cameraSpeedY += SCROLL;
	if( input->isKeyDown(SDLK_LEFT) )
		cameraSpeedX -= SCROLL;
	if( input->isKeyDown(SDLK_RIGHT) )
		cameraSpeedX += SCROLL;
	if( input->isKeyDown(SDLK_SPACE) ){
		addPlanet();
	}


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
	Planeta* planet = NULL;

	for(vector<Planeta*>::iterator it = planetArray.end() - 1;
			                                        it != planetArray.begin() - 1; --it) {
			planet = *it;
					planet->update(dt);
		}

	cameraX1 += cameraSpeedX;
	cameraY1 += cameraSpeedY;

	earth->update(dt);
	moon->update(dt);

	fo->update(dt);
	checkPlanets();

}

void GameManager::render(float cameraX, float cameraY){
	bg->render(0,0);
	this->tileMap->renderLayer(cameraX, cameraY, 0);
	this->tileMap->renderLayer(cameraX*fatorParallaxScrolling, cameraY*fatorParallaxScrolling, 1);


	for (std::vector<Planeta*>::iterator it = planetArray.begin(); it!=planetArray.end(); ++it) {
		Planeta *planet = NULL;
			planet = *it;
			planet->render();
		}
	earth->render();
	moon->render();

	fo->render(cameraX,cameraY);
	fo->renderQueueLines(cameraX, cameraY);

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
			SDLBase::atualizarTela();
			frameEnd = SDL_GetTicks();
		}else{
			SDL_Delay(1000/30 -dt);
		}
	}
}
