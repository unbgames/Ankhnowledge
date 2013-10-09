#include "Sprite.h"

/*
 * Construtor da Classe, que seta o surface do sprite como NULL e carrega a imagem nela
 */
Sprite::Sprite(std::string file) {
	surface = NULL;
	load(file);
	currentAlpha = 255;
	numberRef = 0;
}

/*
 * Destrutor da Classe que libera o ponteiro do surface do sprite
 */
Sprite::~Sprite() {
	if(surface){
		SDL_FreeSurface(surface);
	}
}

/*
 * Metodo que carrega a imagem na surface e adequa o clipRect para essa surface
 */
void Sprite::load(std::string file){
	if(surface){
		SDL_FreeSurface(surface);
	}
		surface = SDLBase::loadImage(file);
		clipRect.x = 0;
		clipRect.y = 0;
		clipRect.w = surface->w;
		clipRect.h = surface->h;
}

/*
 *  Metodo que seta as variaveis do clipRect
 */
void Sprite::clip(int x, int y, int w, int h){
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

/*
 * Meotodo que retorna o clipRect
 */
SDL_Rect Sprite::getClip(){
	return clipRect;
}

/*
 * Metodo que que cola a surface do sprite em uma posicao do buffer principal
 */
void Sprite::render(float x, float y){
	SDL_Rect dst;

	dst.x = x;
	dst.y = y;
	dst.w = 0;
	dst.h = 0;

	SDLBase::renderSurface(surface, &clipRect, &dst);
}

/*
 * Metodo que retorna o comprimento da surface do sprite
 */
int Sprite::getWidth(){
	return surface->w;
}

/*
 * Metodo que retorna a altura da surfae do sprite
 */
int Sprite::getHeight(){
	return surface->h;
}

int Sprite::getAlpha()
{
	return currentAlpha;
}
void Sprite::setAlpha(int alpha)
{
	if(alpha < 0)
		alpha = 0;
	else if(alpha > 255)
		alpha = 255;

	currentAlpha = alpha;
	SDLBase::setAlpha(surface, currentAlpha);
}

void Sprite::incNumRef(){
	this->numberRef++;
}

void Sprite::decNumRef(){
	this->numberRef--;
}

int Sprite::getNumRef(){
	return this->numberRef;
}

