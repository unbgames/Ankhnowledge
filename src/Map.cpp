/*
 * Map.cpp
 *
 *  Created on: Oct 8, 2013
 *      Author: makoto
 */

#include "Map.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

Map::Map(Sprite * tile, Sprite * block, float x, float y):GameObject(x,y) {
	this->tile = tile;
	this->tile->incNumRef();
	this->block = block;
	this->block->incNumRef();

	//srand(time(NULL));

	for(int i = 0; i < 400; i++)
	{
		int random = rand() % 2;

		if(random == 1 || i == 20 || i == 39)
			tiles.push_back(new Tile(tile,getX()+ tile->getWidth()*((int)(i%20)), getY() + tile->getHeight()*((int)(i/20))));
		else
			tiles.push_back(new Tile(tile, block,getX()+ tile->getWidth()*((int)(i%20)), getY() + tile->getHeight()*((int)(i/20))));
	}

	player1 = new Character(new Sprite(SDLBase::imagePath + "adam_spr.png"),getX(),getY(),1);
	player2 = new Character(new Sprite(SDLBase::imagePath + "suti_spr.png"),getX()+tile->getWidth()*19,getY(),2);
	currentPlayer = player1;
	currentPlayer->setTurn(true);
	changePlayer = false;
}

Map::~Map() {
	this->tile->decNumRef();
	this->tile = 0;

	this->block->decNumRef();
	this->block = 0;

	delete player1;

	delete player2;
	// TODO Auto-generated destructor stub
}

void Map::render(float cameraX, float cameraY){
	for(unsigned int i = 0; i < tiles.size(); i++)
	{
		tiles.at(i)->render(0,0);
	}

	player1->render(0,0);
	player2->render(0,0);

}

int Map::update(int dt){
	player1->update(dt);
	player2->update(dt);

	if(currentPlayer->getStamina() == 0 && !changePlayer)
	{
		changePlayer = true;
	}

	if(changePlayer && !currentPlayer->isMoving())
	{
		changePlayer = false;
		if(currentPlayer->getId() == 1)
			currentPlayer = player2;
		else
			currentPlayer = player1;

		player1->setStamina(10);
		player2->setStamina(10);
		player1->toogleTurn();
		player2->toogleTurn();
	}
	return 0;
}

