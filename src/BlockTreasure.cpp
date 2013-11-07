/*
 * BlockTreasure.cpp
 *
 *  Created on: Nov 7, 2013
 *      Author: makoto
 */

#include "BlockTreasure.h"
#include <iostream>
using namespace std;

BlockTreasure::BlockTreasure(Sprite * block, float x, float y):Block(block,x,y) {
	type = "BlockTreasure";
}

BlockTreasure::~BlockTreasure() {

}

int BlockTreasure::update(int dt)
{
	return 0;
}

void BlockTreasure::reaction(Character * character)
{
	cout<<"Ganhou Safado"<<endl;
}

