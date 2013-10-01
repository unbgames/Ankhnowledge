/*
 * Shape.h
 *
 *  Created on: Sep 30, 2013
 *      Author: al
 */

#ifndef SHAPE_H_
#define SHAPE_H_
#include "SDLBase.h"

class Shape {

public:
	Shape();
	virtual ~Shape();
	void fillRect(int x, int y, int w, int h, int color);
	void drawLine(int x0, int y0, int x1,int y1,int color,int spacing);
	void drawCircle(float size, int x,int y,int r, int g, int b);


private:
	SDL_Rect clipRect;
	SDL_Surface* surface;
};

#endif /* SHAPE_H_ */
