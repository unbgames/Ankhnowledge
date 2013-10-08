#include "GameObject.h"

GameObject::GameObject(Sprite* sprite, float x, float y) {
	this->sprite = sprite;
	this->x = x;
	this->y = y;

}

GameObject::~GameObject() {
	// TODO Auto-generated destructor stub
}

float GameObject::getX(){
	return this->x;
}

float GameObject::getY(){
	return this->y;
}

Sprite* GameObject::getSprite(){
	return this->sprite;
}

