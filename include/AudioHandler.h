#ifndef AUDIOHANDLER_H_
#define AUDIOHANDLER_H_

#include <iostream>
#include <string>

#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"

using namespace std;

class AudioHandler 
{
	public:
		static AudioHandler* getInstance();
		void update();
		virtual ~AudioHandler();
		void openAudio();
		void setMusic(string song);
		void playMusic(int times);
		void stopMusic();
		void setMusicVolume(int percent);
		void setEffect(string song);
		void playEffect(int times);
		void setEffectVolume(int percent);


	private:
		AudioHandler();
		static AudioHandler *instance;
		Mix_Music *currentMusic;
		Mix_Chunk *currentEffect;
};

#endif 