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

class Tile;
class Character:public GameObject {
public:
	Character(Sprite* sprite, Tile * tile, int id);
	void render(float cameraX, float cameraY);
	int update(int dt);
	virtual ~Character();
	bool isPerformingAction();
	enum Direction { up, down, right, left, none };
	void pushUpdate(InputManager * input);
	void moveUpdate(InputManager * input);
	void move(Direction dir);
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
	float vx,vy;
	bool performingAction;
	float endX;
	float endY;
	float beginX;
	float beginY;
	int stamina;
	bool turn;
	int id;
	int direction;
	Tile * currentTile;
	int discountStamina;
	void changeCurrentTile(Tile * tile);
	bool canChangeTile(Tile * tile);

};

#endif /* CHARACTER_H_ */
