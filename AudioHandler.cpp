/*
 * AudioHandler.cpp
 *
 *  Created on: Sep 24, 2013
 *      Author: al
 */

#include "AudioHandler.h"
AudioHandler * AudioHandler::instance = 0;

AudioHandler::AudioHandler() {
	// TODO Auto-generated constructor stub

}

AudioHandler::~AudioHandler() {
	// TODO Auto-generated destructor stub
}

void AudioHandler::update(){

}

AudioHandler * AudioHandler::getInstance(){

	if(!instance) instance = new AudioHandler();
	return instance;
}

