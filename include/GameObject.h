#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

class GameObject {
public:
	GameObject(float x, float y);
	virtual ~GameObject();
	virtual int update(int dt) = 0;
	virtual void render(float cameraX, float cameraY) = 0;
	float x;
	float y;

};

#endif /* GAMEOBJECT_H_ */
