#ifndef PLANETRED_H_
#define PLANETRED_H_
#include "Planeta.h"
#include "InputManager.h"
#include <time.h>

class PlanetRed : public Planeta {
public:
	PlanetRed(Sprite * sprite, float x, float y, int hitPoints = 1);
	virtual ~PlanetRed();
	int update(int dt);
};

#endif /* PLANETRED_H_ */
