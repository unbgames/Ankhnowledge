#include "Earth.h"

Earth::Earth(Sprite * sprite, float x, float y, int hitPoints) : Planeta(sprite, x, y, hitPoints) {
	// TODO Auto-generated constructor stub

}

Earth::~Earth() {
	// TODO Auto-generated destructor stub
}

int Earth::update(int dt){
	vx = 0;
	vy = 0;
	InputManager * input = InputManager::getInstance();

	if( input->isKeyPressed(SDLK_w) )
		vy = -0.3*dt;
	if( input->isKeyPressed(SDLK_s) )
		vy = 0.3*dt;
	if( input->isKeyPressed(SDLK_a) )
		vx = -0.3*dt;
	if( input->isKeyPressed(SDLK_d) )
		vx = 0.3*dt;

	x += vx;
	y += vy;

	return 0;
}

