// specific headers
#include "GameManager.h"

int main(){
	GameManager *gm = new GameManager();
	gm->run();
	delete gm;
	return 0;
}

int WinMain(){
	return main();
}
