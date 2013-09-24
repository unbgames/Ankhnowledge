#ifndef SPRITE_H_
#define SPRITE_H_
#include "SDLBase.h"
#include <stdlib.h>
#include <string>
class Sprite {
public:
	Sprite(std::string arquivo);
	virtual ~Sprite();
	void load(std::string arquivo);
	void clip(int x, int y, int w, int h);
	SDL_Rect getClip();
	int getWidth();
	int getHeight();
	void render(float x, float y);

private:

	SDL_Rect clipRect;
	SDL_Surface* surface;
};

#endif /* SPRITE_H_ */
