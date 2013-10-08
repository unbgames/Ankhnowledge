#ifndef SDLBASE_H_
#define SDLBASE_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include <stdlib.h>
#include <string>

class SDLBase {
public:
	SDLBase();
	virtual ~SDLBase();
	static int initializeSDL();
	static SDL_Surface* getScreen();
	static SDL_Surface* loadImage(std::string arquivo);
	static void renderSurface(SDL_Surface* surface, SDL_Rect* clip = NULL, SDL_Rect* dst = NULL);
	static void updateScreen();
	static void fillRectangle(SDL_Rect* rect, Uint32 color);
	static void drawLine(int x1, int y1, int x2, int y2, int rgb, int spacing);
	static void putpixel(SDL_Surface* screen, int x, int y,int r,int g,int b);
	static void drawCircle(float size, int x,int y,int r, int g, int b);
	static void setAlpha(SDL_Surface * surface, int alpha);

private:
	static SDL_Surface* screen;
};

#endif /* SDLBASE_H_ */
