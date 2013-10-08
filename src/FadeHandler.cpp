/*
 * FadeHandler.cpp
 *
 *  Created on: Oct 3, 2013
 *      Author: makoto
 */

#include "FadeHandler.h"
#include <iostream>
using namespace std;

FadeHandler::FadeHandler(Sprite * sprite) {
	this->sprite = sprite;
	this->shouldFadeIn = false;
	this->shouldFadeOut = false;
	this->currentPercentage = ((float)sprite->getAlpha()/255);

}

FadeHandler::~FadeHandler() {
	this->sprite = 0;
}

void FadeHandler::fadeIn(float percentage, float time)
{
	this->shouldFadeIn = true;
	this->shouldFadeOut = false;
	this->percentageOfStop = percentage;
	this->currentPercentage = ((float)sprite->getAlpha()/255);
	this->rate = (this->percentageOfStop - this->currentPercentage)/time;
}

void FadeHandler::fadeOut(float percentage, float time)
{
	this->shouldFadeOut = true;
	this->shouldFadeIn = false;
	this->percentageOfStop = percentage;
	this->currentPercentage = ((float)sprite->getAlpha()/255);
	this->rate = (this->currentPercentage - this->percentageOfStop)/time;

}

void FadeHandler::update(float dt)
{
	if(!this->sprite)
		return;

	if(shouldFadeIn)
	{
		if(currentPercentage < percentageOfStop)
		{
			currentPercentage += rate * dt/1000;
			sprite->setAlpha(255*currentPercentage);
		}
		else
		{
			shouldFadeIn = false;
			currentPercentage = percentageOfStop;
			sprite->setAlpha(255*currentPercentage);
		}
	}else
	if(shouldFadeOut)
	{
		if(currentPercentage > percentageOfStop)
		{
			currentPercentage -= rate*dt/1000;
			sprite->setAlpha(255*currentPercentage);
		}
		else
		{
			shouldFadeOut = false;
			currentPercentage = percentageOfStop;
			sprite->setAlpha(255*currentPercentage);
			fadeIn(1,2);
		}
	}

}

