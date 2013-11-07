/*
 * Character.h
 *
 *  Created on: Oct 7, 2013
 *      Author: al
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "GameObject.h"
#include "Sprite.h"
#include "InputManager.h"
#include "GameManager.h"
#include "Animation.h"
#include "Tile.h"
#include "Skill.h"

class Tile;
class Skill;

class Character:public GameObject {
public:
	Character(Sprite* sprite, Tile* tile, Skill * skill, int id);
	void render(float cameraX, float cameraY);
	int update(int dt);
	virtual ~Character();
	bool isUsingSkill();
	bool isPerformingAction();
	enum Direction { up, down, right, left, none };
	void pushUpdate(InputManager * input);
	void moveUpdate(InputManager * input);
	void move(Direction dir);
	void setSkill(Skill * skill);
	void setSkillDestTile(Tile * tile);
	void push(Direction dir);
	void interpolateMovement(float dt);
	void setTurn(bool on);
	void toogleTurn();
	int getStamina();
	void setStamina(int stamina);
	int getId();
	void setCurrentTile(Tile * tile);
	Tile * getCurrentTile();
	void incrementDiscountStamina(int value);
	void resetDiscountStamina();
	bool hasEnoughStamina();

private:
	Sprite* sprite;
	Animation *currentAnimation;
	Skill* skill;
	float vx,vy;
	bool actived_skill;
	bool performingAction;
	float endX;
	float endY;
	float beginX;
	float beginY;
	int stamina;
	bool turn;
	int id;
	int dt;
	int direction;
	Tile * currentTile, * skillDestTile;
	void changeCurrentTile(Tile * tile);
	bool canChangeTile(Tile * tile);
	void setClickableTiles(Tile *origin, int reach, bool considerBlock, bool clickable);
	int discountStamina;
};

#endif /* CHARACTER_H_ */
