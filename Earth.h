
#ifndef EARTH_H_
#define EARTH_H_
#include "Planeta.h"
#include "InputManager.h"
class Earth : public Planeta {
public:
	Earth(Sprite * sprite, float x, float y, int hitPoints = 1);
	int update(int dt);
	virtual ~Earth();

private:
	float vx;
	float vy;
};

#endif /* EARTH_H_ */
