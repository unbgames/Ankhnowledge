#include "FollowerObject.h"
#include <iostream>
FollowerObject::FollowerObject(Sprite * sprite, float x, float y) : GameObject (x,y) {
	this->sprite = NULL;
	this->sprite = sprite;
}


FollowerObject::~FollowerObject() {
	// TODO Auto-generated destructor stub
}

int FollowerObject::update(int dt){
	if(!(this->coordinateQueueX.empty()) && !(this->coordinateQueueY.empty())){
		float dissenX = x - coordinateQueueX.front();
		float dissenY = y - coordinateQueueY.front();
		float c = 0.003;
		speedX = fabsf(c*dissenX*dt);
		speedY = fabsf(c*dissenY*dt);

		if(dissenX < 0){ 	//Desloca pra direita
			x += speedX;
		}else{				//Desloca pra esquerda
			x -= speedX;
		}
		if(dissenY < 0){ 	//Desloca pra cima
			y += speedY;
		}else{				//Desloca pra baixo
			y -= speedY;
		}

		if(fabsf(x - coordinateQueueX.front()) < 10){
			coordinateQueueX.pop();
			coordinateQueueY.pop();
		}
	}
	return 0;
}

void FollowerObject::render(float cameraX, float cameraY){
	if(sprite)
		this->sprite->render((this->x - sprite->getWidth()/2 - cameraX), (this->y - sprite->getHeight()/2 - cameraY));
}

void FollowerObject::renderQueueLines(float cameraX, float cameraY){
	std::queue<float> tempCoordinateQueueX, tempCoordinateQueueY;

	if(!(this->coordinateQueueX.empty()) && !(this->coordinateQueueY.empty())){
		SDLBase::drawLine(x -cameraX,y - cameraY,coordinateQueueX.front() - cameraX, coordinateQueueY.front() - cameraY,0xff,0);
		float tempX = coordinateQueueX.front();
		float tempY = coordinateQueueY.front();

		tempCoordinateQueueX.push(tempX);
		tempCoordinateQueueY.push(tempY);

		coordinateQueueX.pop();
		coordinateQueueY.pop();

		while(!coordinateQueueX.empty()){
				SDLBase::drawLine(tempX-cameraX,tempY-cameraY,coordinateQueueX.front()-cameraX, coordinateQueueY.front()-cameraY,0xff,0);
				tempX = coordinateQueueX.front();
				tempY = coordinateQueueY.front();

				tempCoordinateQueueX.push(tempX);
				tempCoordinateQueueY.push(tempY);

				coordinateQueueX.pop();
				coordinateQueueY.pop();
		}

		while(!tempCoordinateQueueX.empty()){
			tempX = tempCoordinateQueueX.front();
			tempY = tempCoordinateQueueY.front();

			coordinateQueueX.push(tempX);
			coordinateQueueY.push(tempY);

			tempCoordinateQueueX.pop();
			tempCoordinateQueueY.pop();
		}
	}
}

void FollowerObject::enqueueCommand(float posX, float posY){
	coordinateQueueX.push(posX);
	coordinateQueueY.push(posY);
	std::queue<float> tempCoordinateQueueX, tempCoordinateQueueY;
	float tempX = coordinateQueueX.front();
	float tempY = coordinateQueueY.front();
	while(!coordinateQueueX.empty()){
					tempX = coordinateQueueX.front();
					tempY = coordinateQueueY.front();
					std::cout<<tempX<<std::endl;
					std::cout<<tempY<<std::endl;
					tempCoordinateQueueX.push(tempX);
					tempCoordinateQueueY.push(tempY);

					coordinateQueueX.pop();
					coordinateQueueY.pop();
			}

			while(!tempCoordinateQueueX.empty()){
				tempX = tempCoordinateQueueX.front();
				tempY = tempCoordinateQueueY.front();

				coordinateQueueX.push(tempX);
				coordinateQueueY.push(tempY);

				tempCoordinateQueueX.pop();
				tempCoordinateQueueY.pop();
			}
}
