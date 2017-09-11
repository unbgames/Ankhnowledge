#ifndef SPRITE_H_
#define SPRITE_H_
#include "SDLBase.h"
#include <stdlib.h>
#include <string>
class Sprite {
public:
	Sprite(std::string file);
	virtual ~Sprite();
	void load(std::string file);
	void clip(int x, int y, int w, int h);
	SDL_Rect getClip();
	int getWidth();
	int getHeight();
	void render(float x, float y);
	int getAlpha();
	void setAlpha(int alpha);
	void incNumRef();
	void decNumRef();
	int getNumRef();

private:

	SDL_Rect clipRect;
	SDL_Surface* surface;
	int currentAlpha;
	int numberRef;
};

#endif /* SPRITE_H_ */
