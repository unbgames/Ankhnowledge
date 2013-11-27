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
#include "GameManager.h"

using namespace std;

class Network {
public:
	static void init();
	static void finish();
	virtual ~Network();
	static int connect(string ipaddress);
	static int listening(void *);
	static void disconnect();
	static void sendMessage(string message);
	static int receiveMessage(void *);
	static void receiveThread();
	static string readMessage();
	static void closeConnection();
	static int contagem(void *);
	static int host();
	static int getID();
	static bool isFirstTime();
	static void setFirstTime(bool value);
	static bool didLost();
	static void setLost(bool value);
	static bool endGame, connected, disconnected,cancel;
	static void listeningThread();
	static SDL_mutex *mutex2;
	static int player1Selection;
	static int player2Selection;

private:
	static int rc;
	static TCPsocket currentSocket, communicationSocket;
	static IPaddress ip, *receiverIp;
	static char buffer[512];
	Network();
	static vector<string> messageQueue;
	static SDL_Thread *thread,*lThread;
	static SDL_mutex *mutex;
	static int id;
	static bool firstTime;
	static bool lost;

};

#endif /* NETWORK_H_ */


