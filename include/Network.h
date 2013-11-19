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
#include "SDL/SDL_thread.h"

using namespace std;

class Network {
public:
	static void init();
	static void finish();
	virtual ~Network();
	static int connect(string ipaddress);
	static int listening();
	static void disconnect();
	static void sendMessage(string message);
	static int receiveMessage(void *);
	static void receiveThread();
	static string readMessage();
	static int contagem(void *);
	static int host();
	static bool endGame, connected;
private:
	static int rc;
	static TCPsocket currentSocket, communicationSocket;
	static IPaddress ip, *receiverIp;
	static char buffer[512];
	Network();
	static vector<string> messageQueue;
	static SDL_Thread *thread;
	static SDL_mutex *mutex;

};

#endif /* NETWORK_H_ */

