
#include "GameManager.h"

#include <iostream>
#include <sstream>
using namespace std;

FadeScreen * GameManager::fadeScreen = 0;
Scene * GameManager::currentScene = 0;
string SDLBase::imagePath = getenv("HOME");

/*
 * Construtor da Classe
 * Antes de carregar a imagem e necessario inicialiar o SDL, uma vez que o construtor
 * do Sprite faz uso do metodo SDLBase::loadImage(char * arquivo), que faz uso das
 * funcoes SDL_DisplayFormat e SDL_DisplayFormaAlpha. Funcoes estas que precisam
 */
GameManager::GameManager() {
	SDLBase::imagePath = SDLBase::imagePath + "/../../usr/local/Ankhnowledge/resources/images/";
	SDLBase::initializeSDL();
	initResources();

}

/*
 * Destrutor da Clase
 */
GameManager::~GameManager() {
	delete splashLogo;
	delete splashTechnology;
	delete splashThirdParty;
	delete splashLegal;
	delete splashMainMenu;
	delete splashPhaseOne;
}

//Metodo que inicializa os objetos (recursos) do jogo
void GameManager::initResources(){

	this->splashLogo = new SceneLogo("SceneLogo");
	this->splashTechnology = new SceneTechnology("SceneTechnology");
	this->splashThirdParty = new SceneThirdParty("SceneThirdParty");
	this->splashLegal = new SceneLegal("SceneLegal");
	this->splashMainMenu = new SceneMainMenu("SceneMainMenu");
	this->splashPhaseOne = new ScenePhaseOne("ScenePhaseOne");
	this->splashGameOver = new SceneGameOver("SceneGameOver");
	this->splashCredits = new SceneCredits("SceneCredits");
	this->splashOptions = new SceneOptions("SceneOptions");

	this->splashLogo->addScenes(splashTechnology);
	this->splashTechnology->addScenes(splashThirdParty);
	this->splashThirdParty->addScenes(splashLegal);
	this->splashLegal->addScenes(splashMainMenu);
	this->splashMainMenu->addScenes(splashPhaseOne);
	this->splashMainMenu->addScenes(splashGameOver);
	this->splashMainMenu->addScenes(splashCredits);
	this->splashMainMenu->addScenes(splashOptions);
	this->splashOptions->addScenes(splashMainMenu);
	this->splashCredits->addScenes(splashMainMenu);
	fadeScreen = new FadeScreen(SDLBase::getScreen()->w, SDLBase::getScreen()->h);
	fadeScreen->fadeOut(0,2);
	currentScene = splashLogo;
	currentScene->Enter();


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


	//Skip

	if((input->isKeyDown(SDLK_SPACE)) 
	&& ((currentScene->getSceneName() == "SceneLogo")
	|| (currentScene->getSceneName() == "SceneTechnology")
	|| (currentScene->getSceneName() == "SceneThirdParty")
	|| (currentScene->getSceneName() == "SceneLegal"))){
	    currentScene = splashMainMenu;
	    currentScene->Enter();
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
	currentScene->update(dt);
	fadeScreen->update(dt);
	audio->update();
	cameraX1 += cameraSpeedX;
	cameraY1 += cameraSpeedY;
}

void GameManager::render(float cameraX, float cameraY){
	currentScene->render(0,0);
	fadeScreen->render(0,0);
}

void GameManager::run(){

	while(!SDL_QuitRequested()){

		frameStart = SDL_GetTicks();
		dt = frameStart - frameEnd;

		if(currentScene->shouldChangeScene() && fadeScreen->isFaded())
		{
			currentScene->Exit();
			currentScene = currentScene->getNextScene();
			currentScene->Enter();
		}



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

		this->currentScene->cleanDestroyedGameObjects();
	}
}
