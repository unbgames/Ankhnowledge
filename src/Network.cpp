/*
 * Network.cpp
 *
 *  Created on: Sep 24, 2013
 *      Author: al
 */

#include "Network.h"
#include <iostream>

Network * Network::instance = 0;

Network::Network() {

	rc = SDLNet_Init();

	if(rc == -1)
	{
		cout << "Erro na inicializacao da NET: " << SDLNet_GetError() << endl;
	}
	connected = 0;
	currentSocket = 0;
	communicationSocket = 0;
	endGame = false;
}

Network::~Network() {

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

void Network::receiveMessage(){

	if(connected)
	{
		//cout<<"trying to receive message"<<endl;

		if(SDLNet_TCP_Recv(communicationSocket, buffer, 512) > 0)
		{
			string message = buffer;
			//cout<<"recebi a msn: "<<message<<endl;
			messageQueue.push_back(message);
		}
	}


}

string Network::readMessage()
{
	string message = "";
	if(!messageQueue.empty())
	{
		message = messageQueue.at(0);
		messageQueue.erase(messageQueue.begin());
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

Network* Network::getInstance(){

	if(!instance) instance = new Network();
	return instance;
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
