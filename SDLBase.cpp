#include "SDLBase.h"
#include <iostream>
using namespace std;
SDL_Surface* SDLBase::screen;

/*
 * Construtor da Classe
 */
SDLBase::SDLBase() {
	// TODO Auto-generated constructor stub

}

/*
 * Destrutor da Classe
 */
SDLBase::~SDLBase() {
	// TODO Auto-generated destructor stub
}

/*
 * Metodo responsavel por inicializar a biblioteca do SDL. Alem disso, cria uma janela
 * e uma surface para renderizacao
 */
int SDLBase::initializeSDL() {
	SDL_Init(SDL_INIT_EVERYTHING);
	screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
	SDL_WM_SetCaption("Ankhnowledge", "Ankhnowledge");
	return 0;
}

/*
 * Metodo que retorna a surface de renderizacao. No caso como a tecnica utlizada e
 * double buffering, entao o retorno e o buffer principal
 */
SDL_Surface* SDLBase::getScreen() {
	return screen;
}

/*
 * Metodo que retorna uma superficie com uma imagem carregada. Esse metodo leva em
 * consideracao se a imagem utiliza ou nao o canal alpha
 */
SDL_Surface* SDLBase::loadImage(std::string arquivo){
	SDL_Surface *surface = NULL;
		SDL_Surface *surtemp;
		surface = IMG_Load(arquivo.c_str());
		if(surface->format->Amask){
			surtemp = SDL_DisplayFormatAlpha(surface);

		}else{
			surtemp = SDL_DisplayFormat(surface);
		}
		SDL_FreeSurface(surface);
		return surtemp;
}

/*
 * Metodo que "cola" uma superficie em outra superficie. Metodo que possibilita a tecnica
 * do double buffering
 */
void SDLBase::renderSurface(SDL_Surface* surface, SDL_Rect* clip, SDL_Rect* dst){
	SDL_BlitSurface(surface, clip, screen, dst);
}

/*
 * Metodo para atualizar o buffer principal
 */
void SDLBase::updateScreen(){
	SDL_Flip(screen);
}
