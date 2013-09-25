#ifndef AUDIOHANDLER_H_
#define AUDIOHANDLER_H_

class AudioHandler {
public:
	static AudioHandler* getInstance();
	void update();
	virtual ~AudioHandler();
private:
	AudioHandler();
	static AudioHandler *instance;
};

#endif /* AUDIOHANDLER_H_ */
