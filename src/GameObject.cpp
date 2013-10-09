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

