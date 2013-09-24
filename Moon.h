#ifndef MOON_H_
#define MOON_H_
#define PI 3.14159265

#include "Planeta.h"
#include <math.h>
class Moon : public Planeta{
public:
	Moon(Sprite * sprite, Planeta * center, int hitPoints = 1);
	virtual ~Moon();
	int update (int dt);

private:
	float radius;
	float angle;
	Planeta * center;
};

#endif /* MOON_H_ */
