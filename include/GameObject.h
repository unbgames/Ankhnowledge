#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include "Sprite.h"

class GameObject {
public:
	GameObject(Sprite* sprite, float x, float y);
	virtual ~GameObject();
	virtual int update(int dt) = 0;
	virtual void render(float cameraX, float cameraY) = 0;
	Sprite* getSprite();
	float getX();
	float getY();

private:
	Sprite* sprite;
	float x;
	float y;

};

#endif /* GAMEOBJECT_H_ */
