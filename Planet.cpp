#include "Planet.h"
/*
 * Construtor da classe planet que ja seta as variaveis
 */
Planet::Planet(Sprite* sprite, float hitpoints, float x, float y) {
	this->sprite = sprite;
	this->hitpoints = hitpoints;
	this->x = x;
	this->y = y;

}

Planet::~Planet() {
	// TODO Auto-generated destructor stub
}

/*
 * Metodo que renderiza o sprite do planeta na posicao certa
 */
void Planet::render() {
	this->sprite->render(this->x, this->y);
}

/*
 * Metodo que retorna a quantidade de hitpoints do planeta
 */

float Planet::getHitPoints(){
	return this->hitpoints;
}

/*
 * Metodo que seta a quantidade de hitpoints
 */
void Planet::setHitPoints(float hitpoints){
	this->hitpoints = hitpoints;
}

/*
 * Metodo que retorna a coordenada x do planeta
 */
float Planet::getX(){
	return this->x;
}

/*
 * Metodo que retorna a coordenada y do planeta
 */
float Planet::getY(){
	return this->y;
}

void Planet::setX(float x){
	this->x += x;
}

void Planet::setY(float y){
	this->y += y;
}

/*
 * Metodo que retorna o sprite do planeta
 */
Sprite* Planet::getSprite(){
	return this->sprite;
}

