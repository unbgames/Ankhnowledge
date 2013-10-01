/*
 * Shape.cpp
 *
 *  Created on: Sep 30, 2013
 *      Author: al
 */

#include "Shape.h"

Shape::Shape() {


}

Shape::~Shape() {
	if(surface){
		SDL_FreeSurface(surface);
	}
}

void Shape::fillRect(int x, int y, int w, int h, int color){
	clipRect = {x,y,w,h};
	SDLBase::fillRectangle(&clipRect, color);
}

void Shape::drawLine(int x0, int y0,int x1, int y1,int color,int spacing){
	SDLBase::drawLine(x0,y0,x1,y1,color,spacing);
}

void Shape::drawCircle(float size, int x,int y,int r, int g, int b){
	SDLBase::drawCircle(size, x,y,r,g,b);
}
