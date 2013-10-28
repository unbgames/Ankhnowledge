#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

class GameObject {
public:
	GameObject(float x, float y);
	virtual ~GameObject();
	virtual int update(int dt) = 0;
	virtual void render(float cameraX, float cameraY) = 0;
	float getX();
	float getY();
	bool lerp(float beginX, float beginY, float endX, float endY, float time, float  dt);

protected:
	float x;
	float y;

};

#endif /* GAMEOBJECT_H_ */
