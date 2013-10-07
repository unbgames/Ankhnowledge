/*
 * Network.cpp
 *
 *  Created on: Sep 24, 2013
 *      Author: al
 */

#include "Network.h"
Network * Network::instance = 0;

Network::Network() {
	// TODO Auto-generated constructor stub

}

Network::~Network() {
	// TODO Auto-generated destructor stub
}

void Network::connect(){

}

void Network::disconnect(){

}

void Network::sendMessage(){

}

void Network::receiveMessage(){

}

Network* Network::getInstance(){

	if(!instance) instance = new Network();
	return instance;
}
