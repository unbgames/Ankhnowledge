/*
 * Character.cpp
 *
 *  Created on: Oct 7, 2013
 *      Author: al
 */

#include <iostream>

#include "Character.h"
#include "Skill.h"

#define DT 300

using namespace std;

Character::Character(Sprite* sprite, Tile* tile, Skill* skill, int id):GameObject(tile->getX(),tile->getY()) {
	this->sprite = sprite;
	sprite->incNumRef();
	this->currentTile = tile;
	tile->setCharacter(this);
	this->x = tile->getX();
	this->y = tile->getY();
	this->skill = skill;
	this->currentAnimation = new Animation(20,40,sprite,0);
	this->activatedSkill = false;
	this->performingAction = false;
	this->stamina = 10;
	this->turn = false;
	this->id = id;
	this->direction = 4;
	this->skillDestTile = 0;
	this->dt = 0;
	discountStamina = 0;
	this->win = false;
	this->onLoop = true;
}

Character::~Character() {
	this->currentTile = 0;
	this->sprite->decNumRef();
	this->skill = 0;
	this->skillDestTile = 0;
	sprite = 0;
}

void Character::render(float cameraX, float cameraY)
{
	currentAnimation->animate(100, this->x - cameraX,this->y - cameraY - 40/2);
}

int Character::update(int dt)
{
	InputManager* input;
	input = InputManager::getInstance();
	
	this->dt = this->dt + dt;

	if(this->activatedSkill)
	{
		if(this->dt > DT)
		{
			if (input->isKeyPressed(SDLK_y))
			{
				activatedSkill = false;
				setClickableTiles(currentTile, skill->getReach(), skill->getConsiderBlocks(), false);

			}
			else if(this->skillDestTile)
			{	
				this->stamina -= skill->getRequiredStamina();
				setClickableTiles(currentTile, skill->getReach(), skill->getConsiderBlocks(), false);
				skill->execute(this->currentTile, this->skillDestTile);
				this->activatedSkill = false;
				this->skillDestTile = 0;
			}
			
			this->dt = 0;
		}
	}
	
	else
	{
		if(turn && !performingAction)
		{
			if (input->isKeyPressed(SDLK_y))
			{
				if(this->dt > DT)
				{
					if((this->skill) && (this->stamina >= this->skill->getRequiredStamina()))
					{
						activatedSkill = true;
						setClickableTiles(currentTile, skill->getReach(), skill->getConsiderBlocks(), true); 
					}

					this->dt = 0;
				}
			}
		}
		
		if(turn && !performingAction && input->isKeyPressed(SDLK_u))
		{
			pushUpdate(input);
		}
		else if(turn && !performingAction)
		{
			moveUpdate(input);
		}
	}

	interpolateMovement(dt);
	if(activatedSkill == true)
	{
		onLoop = false;
		direction = 5;
	}
	if((activatedSkill == false) && currentAnimation->getFinishedAnimation())
	{
		onLoop = false;
		if(direction == 5)
			direction = 6;
		else if(direction == 6)
			direction = 4;
	}
	else if ((direction != 5) && (direction != 6))
	{
		onLoop = true;
	}

	currentAnimation->update(dt, onLoop, direction,false);
	return 0;
}

void Character::push(Direction dir)
{
	this->performingAction = true;
	switch(dir)
	{
		case up:
			endX = getX();
			endY = getY() - currentTile->getWidth();
			direction = 3;
		break;

		case down:
			endX = getX();
			endY = getY() + currentTile->getWidth();
			direction = 0;
		break;
		case right:
			endX = getX() + currentTile->getWidth();
			endY = getY();
			direction = 2;
		break;

		case left:
			endX = getX() - currentTile->getWidth();
			endY = getY();
			direction = 1;

		break;

		case none:

		break;

	}

	   beginX = getX();
	   beginY = getY();
}

void Character::move(Direction dir)
{
	this->performingAction = true;
	this->stamina -= 1;
	switch(dir)
	{
	    case up:
	    	endX = getX();
	    	endY = getY() - currentTile->getWidth();
	    	direction = 3;
	    break;

	    case down:
	    	endX = getX();
			endY = getY() + currentTile->getWidth();
			direction = 0;
	    break;
	    case right:
	    	endX = getX() + currentTile->getWidth();
	    	endY = getY();
	    	direction = 2;
	    break;

	    case left:
	    	endX = getX() - currentTile->getWidth();
			endY = getY();
			direction = 1;
	    break;

	    case none:

	    break;

	}

	   beginX = getX();
	   beginY = getY();
}

void Character::interpolateMovement(float dt)
{
	if(this->performingAction == true)
	{
		if(!lerp(beginX, beginY, endX, endY, 10, dt))
		{
			this->performingAction = false;
			direction = 4;
		}
	}

}

int Character::getStamina()
{
	return this->stamina;
}

void Character::setStamina(int stamina)
{
	this->stamina = stamina;
	if(this->stamina < 0)
		this->stamina = 0;
}

void Character::setSkill(Skill * skill)
{
	this->skill = skill;
}

void Character::setTurn(bool on)
{
	turn = on;
}

void Character::toogleTurn()
{
	if(turn == true)
		turn = false;
	else
		turn = true;
}

int Character::getId()
{
	return this->id;
}

bool Character::isPerformingAction()
{
	return this->performingAction;
}

bool Character::isUsingSkill()
{
	return this->activatedSkill;
}

void Character::setCurrentTile(Tile * tile)
{
	this->currentTile = tile;
}

Tile * Character::getCurrentTile()
{
	return this->currentTile;
}

void Character::changeCurrentTile(Tile * tile)
{
	currentTile->setCharacter(0);
	currentTile = tile;
	currentTile->setCharacter(this);
}

bool Character::canChangeTile(Tile * tile)
{
	if(tile == 0)
		return false;

	if(tile->getCharacter() != 0)
		return false;

	if(tile->getBlock())
	{
		if(tile->getBlock()->getType() == "BlockMovable")
		return false;
	}


	return true;
}

void Character::setSkillDestTile(Tile * tile)
{
	this->skillDestTile = tile;
}


void Character::setClickableTiles(Tile *origin, int reach, bool considerBlock, bool clickable)
{
	int i = 1;
	Tile *tile = origin;

	if(i <= reach && tile->getUpTile())
	{
		tile = tile->getUpTile();
		
		if(!tile->getCharacter())
		{
			if(!(!considerBlock && tile->getBlock()))
				tile->setClickable(clickable);
		}

		setClickableTiles(tile, reach-1, considerBlock, clickable);
	}

	tile = origin;

	if(i <= reach && tile->getDownTile())
	{
		tile = tile->getDownTile();
		
		if(!tile->getCharacter())
		{
			if(!(!considerBlock && tile->getBlock()))
				tile->setClickable(clickable);
		}

		setClickableTiles(tile, reach-1, considerBlock, clickable);
	}

	tile = origin;

	if(i <= reach && tile->getLeftTile())
	{
		tile = tile->getLeftTile();
		
		if(!tile->getCharacter())
		{
			if(!(!considerBlock && tile->getBlock()))
				tile->setClickable(clickable);
		}

		setClickableTiles(tile, reach-1, considerBlock, clickable);
	}

	tile = origin;

	if(i <= reach && tile->getRightTile())
	{
		tile = tile->getRightTile();
		
		if(!tile->getCharacter())
		{
			if(!(!considerBlock && tile->getBlock()))
				tile->setClickable(clickable);
		}

		setClickableTiles(tile, reach-1, considerBlock, clickable);
	}
}

void Character::incrementDiscountStamina(int value)
{
	this->discountStamina += value;
}

void Character::resetDiscountStamina()
{
	this->discountStamina = 0;
}

bool Character::hasEnoughStamina()
{
	return	(discountStamina <= stamina);
}

void Character::pushUpdate(InputManager * input)
{
	Direction dir = none;

	Tile * nextTile = 0;
	if (input->isKeyPressed(SDLK_d))
	{
		dir = right;
		nextTile = currentTile->getRightTile();
	}else
	if (input->isKeyPressed(SDLK_a))
	{
		dir = left;
		nextTile = currentTile->getLeftTile();
	}else
	if (input->isKeyPressed(SDLK_s))
	{
		dir = down;
		nextTile = currentTile->getDownTile();
	}else
	if (input->isKeyPressed(SDLK_w))
	{
		dir = up;
		nextTile = currentTile->getUpTile();
	}

	Block * block = 0;
	if(nextTile)
	{
		block = nextTile->getBlock();
	}
	discountStamina = 0;
	if(block)
	{
		if(block->getType() == "BlockMovable")
		{
			block->reaction(this);
		}
	}

	if(discountStamina != 0 && hasEnoughStamina())
	{
		stamina -= discountStamina;

		if(stamina < 0)
			stamina = 0;

		discountStamina = 0;
		push(dir);
		changeCurrentTile(nextTile);
	}


	block = 0;
	nextTile = 0;
}

void Character::moveUpdate(InputManager * input)
{
	Direction dir = none;

	Tile * nextTile = 0;
	if (input->isKeyPressed(SDLK_d) && canChangeTile(currentTile->getRightTile()))
	{
		dir = right;
		nextTile = currentTile->getRightTile();
	}else
	if (input->isKeyPressed(SDLK_a) && canChangeTile(currentTile->getLeftTile()))
	{
		dir = left;
		nextTile = currentTile->getLeftTile();
	}else
	if (input->isKeyPressed(SDLK_s)  && canChangeTile(currentTile->getDownTile()))
	{
		dir = down;
		nextTile = currentTile->getDownTile();
	}else
	if (input->isKeyPressed(SDLK_w)  && canChangeTile(currentTile->getUpTile()))
	{
		dir = up;
		nextTile = currentTile->getUpTile();
	}

	if(nextTile)
	{
		Block * block = 0;
		block = nextTile->getBlock();

		if(block)
		{
			if(block->getType() == "BlockTreasure")
			{
				block->reaction(this);
			}
			if(block->getType() == "BlockSand")
			{
				changeCurrentTile(nextTile);
				if(dir != none && !performingAction)
					move(dir);
				nextTile->setBlock(0);
				setStamina(getStamina() - 3);
				//delete block;
			}
		}else
		{
			changeCurrentTile(nextTile);
			if(dir != none && !performingAction)
				move(dir);
		}

		block = 0;
	}

	nextTile = 0;
}

bool Character::getWin()
{
	return this->win;
}

void Character::setWin(bool win)
{
	this->win = win;
}

bool Character::getTurn()
{
	return this->turn;
}

