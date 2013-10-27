
#include "SceneLogo.h"

SceneLogo::SceneLogo(string sceneName) : Scene (sceneName) {

}

SceneLogo::~SceneLogo() {
}

void SceneLogo::Enter()
{
	this->splashSprite = new Sprite(SDLBase::imagePath + "splashlogo.png");
	string nextScene = "SceneTechnology";
	SplashScreen * splashScreen =  new SplashScreen(splashSprite,nextScene);

	this->addGameObject(splashScreen);
	//GameManager::fadeScreen->fadeOut(0,2);
}

void SceneLogo::Exit()
{
	this->cleanGameObjects();
}

