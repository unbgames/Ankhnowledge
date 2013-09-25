/*
 * Network.h
 *
 *  Created on: Sep 24, 2013
 *      Author: al
 */

#ifndef NETWORK_H_
#define NETWORK_H_

class Network {
public:
	virtual ~Network();
	void connect();
	void disconnect();
	void sendMessage();
	void receiveMessage();
	static Network* getInstance();
private:
	Network();
	static Network* instance;
};

#endif /* NETWORK_H_ */
