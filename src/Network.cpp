/*
 * Network.cpp
 *
 *  Created on: Sep 24, 2013
 *      Author: al
 */

#include "Network.h"
#include <iostream>

IPaddress Network::ip, * Network::receiverIp;
int Network::rc, Network::id;
TCPsocket Network::currentSocket, Network::communicationSocket;
char Network::buffer[512];
vector<string> Network::messageQueue;
SDL_Thread * Network::thread,* Network::lThread;
bool Network::endGame, Network::connected, Network::firstTime, Network::lost, Network::disconnected;
bool Network::cancel;
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
	mutex = SDL_CreateMutex();
	cout<<"mutex criado"<<endl;
	id = -1;
	firstTime = false;
	lost = false;
	disconnected = false;
	Network::cancel = false;

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
	SDL_KillThread(lThread);
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

	id = 2;
	connected = true;
	firstTime = true;
	lost = false;
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

	while((connected))
	{
		//cout<<"trying to receive message"<<endl;

		if(SDLNet_TCP_Recv(communicationSocket, buffer, 512) > 0)
		{
			if(SDL_mutexP(mutex) == 0)
			{
				string message = buffer;
				//cout<<"recebi a msn: "<<message<<endl;
				messageQueue.push_back(message);
				SDL_mutexV(mutex);
			}
			else
			{
				cout<<"mutex nao funcionou"<<endl;
			}

		}else
		{
			cout<<"Desconectou"<<endl;
			connected = false;
			if(GameManager::currentScene->changeScene("SceneMainMenu") == 1)
					GameManager::fadeScreen->fadeIn(1,2);
			if(currentSocket)
			{
				SDLNet_TCP_Close(currentSocket);
			}

			if(communicationSocket)
			{
				SDLNet_TCP_Close(communicationSocket);
			}
			currentSocket = NULL;
			communicationSocket = NULL;
			id = -1;
			disconnected = true;
		}

	}

	return 0;
}

void Network::receiveThread(){
	thread = SDL_CreateThread(receiveMessage, NULL);
}

void Network::listeningThread(){
	lThread = SDL_CreateThread(listening, NULL);
}

string Network::readMessage()
{
	string message = "";
	if(SDL_mutexP(mutex) == 0)
	{
		if(!messageQueue.empty())
		{
			message = messageQueue.at(0);
			messageQueue.erase(messageQueue.begin());

		}
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

int Network::listening(void *)
{
	while(!connected && !cancel)
	{
		//cout<<"Escutando"<<endl;
		if(communicationSocket = SDLNet_TCP_Accept(currentSocket))
		{
			connected = true;
			firstTime = true;
			lost = false;
			id = 1;
			//cout<<"Servidor Conectou"<<endl;
		}
	}

}

void Network::closeConnection(){
	if(currentSocket)
	{
		SDLNet_TCP_Close(currentSocket);
	}

	if(communicationSocket)
	{
		SDLNet_TCP_Close(communicationSocket);
	}
}

int Network::getID()
{
	return id;
}

bool Network::isFirstTime()
{
	return firstTime;
}

bool Network::didLost()
{
	return lost;
}

