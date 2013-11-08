/*
 * Map.cpp
 *
 *  Created on: Oct 8, 2013
 *      Author: makoto
 */

#include "Map.h"
#include "BlockWater.h"
#include "BlockMovable.h"
#include "BlockTreasure.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "SkillDig.h"
#include "SkillSand.h"

using namespace std;

Map::Map(Sprite * tile, Sprite * block, float x, float y):GameObject(x,y) {
	this->tile = tile;
	this->tile->incNumRef();
	this->block = block;
	this->block->incNumRef();
	this->columns = 20;
	this->rows = 20;

	SDLBase::initializeSDLTTF();
	color.r = 255;
	color.g = 255;
	color.b = 255;
	string font_path = SDLBase::imagePath + "quicksandbold.ttf";
	font = SDLBase::loadFont(font_path.c_str(),40);



	srand(time(NULL));
	/*
	 * Instantioating all the tiles
	 */

	int maxBlocks = 60;
	for(int i = 0; i < (columns*rows); i++)
	{
		int random = rand() % 5;

		if(random < 3|| random == 2|| i == 0 || i == 19 || i == 20 || i == 39)
			tiles.push_back(new Tile(tile, 0,getX()+ tile->getWidth()*((int)(i%20)), getY() + tile->getHeight()*((int)(i/20)), i));
		else
		{
			tiles.push_back(new Tile(tile
									, new BlockMovable(block,getX()+ tile->getWidth()*((int)(i%20)), getY() + tile->getHeight()*((int)(i/20)))
									, getX()+ tile->getWidth()*((int)(i%20))
									, getY() + tile->getHeight()*((int)(i/20))
									, i));
			maxBlocks--;
		}


		//tiles.push_back(new Tile(tile, 0,getX()+ tile->getWidth()*((int)(i%20)), getY() + tile->getHeight()*((int)(i/20)), i));
	}

	/*
	 * Connecting all the tiles
	 */
	for(int i = 0; i < (columns*rows); i++)
	{
		if(!isLastColumn(i))
			tiles.at(i)->setRightTile(tiles.at(i+1));

		if(!isFirstColumn(i))
			tiles.at(i)->setLeftTile(tiles.at(i-1));

		if(!isFirstRow(i))
			tiles.at(i)->setUpTile(tiles.at(i-columns));

		if(!isLastRow(i))
			tiles.at(i)->setDownTile(tiles.at(i+columns));
	}

	tiles.at(350)->setBlock(new BlockTreasure(new Sprite(SDLBase::imagePath + "bauanimacao.png"),tiles.at(350)->getX(), tiles.at(350)->getY()));
	tiles.at(0)->setRightTile(tiles.at(1));
	Skill *alanSkill = new SkillDig();
	Skill *sutiSkill = new SkillSand();
	player1 = new Character(new Sprite(SDLBase::imagePath + "adam_spr.png"), tiles.at(0), alanSkill, 1);
	player2 = new Character(new Sprite(SDLBase::imagePath + "suti_spr.png"), tiles.at(columns-1), sutiSkill, 2);
	currentPlayer = player1;
	currentPlayer->setTurn(true);
	changePlayer = false;
}

Map::~Map() {

	for(int i = 0; i < (columns*rows); i++)
	{
		tiles.at(i)->cleanReferences();
	}

	delete player1;

	delete player2;

	this->tile->decNumRef();
	this->tile = 0;

	this->block->decNumRef();
	this->block = 0;


	// TODO Auto-generated destructor stub
}

void Map::render(float cameraX, float cameraY){
	for(unsigned int i = 0; i < tiles.size(); i++)
	{
		tiles.at(i)->render(0,0);
	}
	for(unsigned int i = 0; i < tiles.size(); i++)
	{
		if(tiles.at(i)->getBlock())
			tiles.at(i)->getBlock()->render(getX(), getY());
		if(tiles.at(i)->isClickable())
			tiles.at(i)->renderClickableTiles();
	}




	if(player1->getY() > player2->getY())
	{
		player2->render(0,0);
		player1->render(0,0);
	}
	else
	{
		player1->render(0,0);
		player2->render(0,0);
	}

	stringstream st;
	st << ((int)(currentPlayer->getStamina()));
	SDLBase::renderText(font, st.str(),color,720,60);

}

int Map::update(int dt)
{
	InputManager* input;
	input = InputManager::getInstance();

	for(unsigned int i = 0; i < tiles.size(); i++)
	{
		tiles.at(i)->update(dt);
		if(tiles.at(i)->isClickable())
			tiles.at(i)->animateClickableTiles(dt);
	}
	
	if(currentPlayer->isUsingSkill())
	{
		if(input->isMousePressed(1))
		{
			Tile* currentTile = getPressedTile();
			currentPlayer->setSkillDestTile(currentTile);
		}		
	}

	player1->update(dt);
	player2->update(dt);

	if(!currentPlayer->getWin())
	{
		if(currentPlayer->getStamina() <= 0 && !changePlayer)
		{
			changePlayer = true;
		}

		if(changePlayer && !currentPlayer->isPerformingAction())
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
	}else
	{
		currentPlayer->setTurn(false);
	}

	for(unsigned int i = 0; i < tiles.size(); i++)
	{
		if(tiles.at(i)->getBlock())
		{
			if (tiles.at(i)->getBlock()->getDestroyedFinalBlock())
			{
			Block* tempBlock = tiles.at(i)->getBlock();
			tiles.at(i)->setBlock(0);
			delete tempBlock;
			}
		}
	}

	return 0;
}

Tile * Map::getPressedTile()
{
	for(unsigned int i = 0; i < tiles.size(); i++)
	{
		if(tiles.at(i)->isClickable())
		{
			if(tiles.at(i)->insideTile())
			{
				return tiles.at(i);
			}
		}
	}

	return 0;
}


bool Map::isFirstRow(int index)
{
	return (index < columns);
}

bool Map::isFirstColumn(int index)
{
	return ((index % columns) == 0);
}

bool Map::isLastRow(int index)
{
	return ((index + columns) > (columns*rows - 1));
}

bool Map::isLastColumn(int index)
{
	return ((index % columns) == (columns - 1));
}

