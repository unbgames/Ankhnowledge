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

class Character:public GameObject {
public:
	Character(Sprite* sprite, float x, float y, int id);
	void render(float cameraX, float cameraY);
	int update(int dt);
	virtual ~Character();
	bool isMoving();
	enum Direction { up, down, right, left, none };
	void move(Direction dir);
	void interpolateMovement(float dt);
	void setTurn(bool on);
	void toogleTurn();
	bool getStamina();
	void setStamina(int stamina);
	int getId();

private:
	Sprite* sprite;
	Animation *currentAnimation;
	float vx,vy;
	bool moving;
	float endX;
	float endY;
	float beginX;
	float beginY;
	int stamina;
	bool turn;
	int id;
	int direction;
};

#endif /* CHARACTER_H_ */
