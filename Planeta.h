#ifndef PLANETA_H_
#define PLANETA_H_
#include "Sprite.h"
#include "GameObject.h"

class Planeta : public GameObject {

public:
	int hitPoints;
	virtual ~Planeta();
	Planeta(Sprite * sprite, float x, float y, int hitPoints);
	virtual int update(int dt) = 0;
	void render(float cameraX = 0.0, float cameraY = 0.0);
	Sprite * getSprite();

private:
	Sprite * sprite;
};

#endif /* PLANETA_H_ */
