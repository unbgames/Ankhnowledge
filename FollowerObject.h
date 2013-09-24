
#ifndef FOLLOWEROBJECT_H_
#define FOLLOWEROBJECT_H_
#include "SDLBase.h"
#include "GameObject.h"
#include "Sprite.h"
#include <queue>
#include <stdlib.h>
#include <math.h>
#include "InputManager.h"

class FollowerObject : GameObject{
public:
	FollowerObject(Sprite * sprite, float x, float y);
	virtual ~FollowerObject();
	int update(int dt);
	void render(float cameraX, float cameraY);
	void renderQueueLines(float cameraX, float cameraY);
	void enqueueCommand(float posX, float posY);

private:
	Sprite * sprite;
	float speedX, speedY;
	std::queue<float> coordinateQueueX, coordinateQueueY;

};

#endif /* FOLLOWEROBJECT_H_ */
