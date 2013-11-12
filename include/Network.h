/*
 * Network.h
 *
 *  Created on: Sep 24, 2013
 *      Author: al
 */

#ifndef NETWORK_H_
#define NETWORK_H_
using namespace std;
#include <string>
#include "SDL/SDL_net.h"
#include <vector>

class Network {
public:
	virtual ~Network();
	int connect(string ipaddress);
	int listening();
	void disconnect();
	void sendMessage(string message);
	void receiveMessage();
	string readMessage();
	int host();
	static Network* getInstance();
	bool endGame, connected;
private:
	int rc;
	TCPsocket currentSocket, communicationSocket;
	IPaddress ip, *receiverIp;
	char buffer[512];
	Network();
	static Network* instance;
	vector<string> messageQueue;

};

#endif /* NETWORK_H_ */
