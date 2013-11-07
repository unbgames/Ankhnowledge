#include "GameObject.h"

GameObject::GameObject(float x, float y) {
	this->x = x;
	this->y = y;

}

GameObject::~GameObject() {

}

float GameObject::getX(){
	return this->x;
}

float GameObject::getY(){
	return this->y;
}

bool GameObject::lerp(float beginX, float beginY, float endX, float endY, float time, float  dt)
{
	float xPercentage = 0;
	float yPercentage = 0;
	float totalX = endX - beginX;
	float totalY = endY - beginY;
	bool positiveX;
	bool positiveY;

	bool stillInterpolating = false;

	if(beginX > endX)
	{
		positiveX = false;
		xPercentage = (beginX - getX())/ totalX;
	}
	else
	{
		positiveX = true;
		xPercentage = (getX() - beginX)/ totalX;
	}

	if(beginY > endY)
	{
		positiveY = false;
		yPercentage =  (beginY - getY())/ totalY;
	}
	else
	{
		positiveY = true;
		yPercentage = (getY() - beginY)/ totalY;
	}


	if(xPercentage < 1 && xPercentage > -1 && this->x != endX)
	{
		stillInterpolating = true;
		if(positiveX)
			this->x = this->x + totalX*(totalX/time * dt/1000);
		else
			this->x = this->x - totalX*(totalX/time * dt/1000);
	}
	else
	{
		this->x = endX;
	}

	if(yPercentage < 1 && yPercentage > -1 && this->y != endY)
	{
		stillInterpolating = true;
		if(positiveY)
			this->y = this->y + totalY*(totalY/time * dt/1000);
		else
			this->y = this->y - totalY*(totalY/time * dt/1000);
	}
	else
	{
		this->y = endY;
	}

	return stillInterpolating;
}

void GameObject::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

