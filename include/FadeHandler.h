

#ifndef FADEHANDLER_H_
#define FADEHANDLER_H_
#include "SDLBase.h"
#include "Sprite.h"

class FadeHandler {
public:
	FadeHandler(Sprite* sprite);
	virtual ~FadeHandler();
	void fadeIn(float percentage, float time);
	void fadeOut(float percentage, float time);
	void update(float dt);
	float getCurrentPercentage();
private:
	bool shouldFadeIn;
	bool shouldFadeOut;
	float percentageOfStop;
	Sprite * sprite;
	float time;
	float currentPercentage;
	float rate;
};

#endif /* FADEHANDLER_H_ */
