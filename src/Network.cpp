/*
 * Network.cpp
 *
 *  Created on: Sep 24, 2013
 *      Author: al
 */

#include "Network.h"
#include <iostream>

IPaddress Network::ip, * Network::receiverIp;
int Network::rc;
TCPsocket Network::currentSocket, Network::communicationSocket;
char Network::buffer[512];
vector<string> Network::messageQueue;
SDL_Thread * Network::thread;
bool Network::endGame, Network::connected;
SDL_mutex *Network::mutex;

Network::Network() {

}

void Network::init(){
	rc = SDLNet_Init();

	if(rc == -1)
	{
		cout << "Erro na inicializacao da NET: " << SDLNet_GetError() << endl;
	}
	connected = 0;
	currentSocket = 0;
	communicationSocket = 0;
	endGame = false;
	mutex = NULL;

}

void Network::finish(){
	if(currentSocket)
	{
		SDLNet_TCP_Close(currentSocket);
	}

	if(communicationSocket)
	{
		SDLNet_TCP_Close(communicationSocket);
	}

	messageQueue.clear();

	SDLNet_Quit();

	cout << "\nOk!\n" << endl;
	SDL_KillThread(thread);
	SDL_DestroyMutex(mutex);
}

Network::~Network() {


}

int Network::connect(string ipaddress){

	rc = SDLNet_ResolveHost(&ip, /*ipaddress.c_str()*/"localhost", 3000);

	if(rc == -1)
	{
		cout << "Erro na localizacao do HOST: " << SDLNet_GetError() << endl;
		return -1;
	}

	communicationSocket = SDLNet_TCP_Open(&ip);

	if(communicationSocket == NULL)
	{
		cout << "Erro na inicializacao do SOCKET: " << SDLNet_GetError() << endl;
		return -1;
	}

	connected = true;
	cout<<"Cliente Conectou"<<endl;
}

void Network::disconnect(){

}

void Network::sendMessage(string message){
	if(SDLNet_TCP_Send(communicationSocket, (void *) message.c_str(), message.size()+1) < message.size())
	{
		cout << "Erro no envio da MENSAGEM: " << SDLNet_GetError() << endl;
		return;
	}
}

int Network::receiveMessage(void *){

	if((connected) && (SDL_mutexP(mutex) == 0))
	{
		//cout<<"trying to receive message"<<endl;

		if(SDLNet_TCP_Recv(communicationSocket, buffer, 512) > 0)
		{
			string message = buffer;
			//cout<<"recebi a msn: "<<message<<endl;
			messageQueue.push_back(message);
		}
		SDL_mutexV(mutex);
	}

	return 0;
}

void Network::receiveThread(){
	thread = SDL_CreateThread(receiveMessage, NULL);
}

string Network::readMessage()
{
	string message = "";
	if(!messageQueue.empty() && (SDL_mutexP(mutex) == 0))
	{
		message = messageQueue.at(0);
		messageQueue.erase(messageQueue.begin());
		SDL_mutexV(mutex);
	}
	return message;
}

int Network::host()
{
	rc = SDLNet_ResolveHost(&ip, NULL, 3000);

	if(rc == -1)
	{
		cout << "Erro na inicializacao do HOST: " << SDLNet_GetError() << endl;
		return -1;
	}

	currentSocket = SDLNet_TCP_Open(&ip);

	if(currentSocket == NULL)
	{
		cout << "Erro na inicializacao do SOCKET: " << SDLNet_GetError() << endl;
		return -1;
	}

	cout << "Servidor Iniciado!" << endl;
	cout << "Aguardando cliente ..." << endl;
}

int Network::listening()
{
	while(!connected)
	{
		//cout<<"Escutando"<<endl;
		if(communicationSocket = SDLNet_TCP_Accept(currentSocket))
		{
			connected = true;
			//cout<<"Servidor Conectou"<<endl;
		}
	}

}

