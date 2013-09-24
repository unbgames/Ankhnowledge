#include "TileMap.h"
#include <iostream>

TileMap::TileMap(int mapWidth, int mapHeight, int tileSize, int layers, TileSet * tileSet) {
	this->mapWidth = mapWidth;
	this->mapHeight = mapHeight;
	this->mapLayers = layers;
	this->tileSet = tileSet;

	this->tileMatrix = new std::vector< std::vector< std::vector<int> > >(tileSize, std::vector< std::vector<int> >(tileSize, std::vector<int>(tileSize,-1 ) ) );
}

TileMap::TileMap(std::string mapa, TileSet * tileSet) {
	this->tileSet =  tileSet;
	this->mapWidth = 0;
	this->mapHeight = 0;
	this->mapLayers = 0;

	load(mapa);

	/*
	 * Metodo Load
	 */
}

TileMap::TileMap(std::string mapa, int tileSize, TileSet * tileSet){
	this->tileSet =  tileSet;
	this->mapWidth = 0;
	this->mapHeight = 0;
	this->mapLayers = 0;
	this->tileMatrix = new std::vector< std::vector< std::vector<int> > >(tileSize, std::vector< std::vector<int> >(tileSize, std::vector<int>(tileSize,-1 ) ) );
	load(mapa);
}


TileMap::~TileMap() {
	// TODO Auto-generated destructor stub
}

void TileMap::load(std::string mapPath){
	    FILE* FileHandle = fopen(mapPath.c_str(), "r");

	    if(FileHandle == NULL) {
	        return;
	    }

	    fscanf(FileHandle, "%d,%d,%d,", &this->mapHeight, &this->mapWidth, &this->mapLayers);
	    fscanf(FileHandle, "\n");
	    fscanf(FileHandle, "\n");
	    fscanf(FileHandle, "\n");
	    fscanf(FileHandle, "\n");

	    for(int Z = 0; Z < mapLayers; Z++){
			for(int X = 0;X < mapHeight;X++) {
				for(int Y = 0;Y < mapWidth;Y++) {
					int aux;

					fscanf(FileHandle, "%d,", &aux);

					tileMatrix->at(Z).at(X).at(Y) = aux;
				}
				fscanf(FileHandle, "\n");
				fscanf(FileHandle, "\n");
			}
			fscanf(FileHandle, "\n");
			fscanf(FileHandle, "\n");
	    }

	    fclose(FileHandle);
}

void TileMap::setTileSet(TileSet * tileSet){
	this->tileSet = tileSet;
}

int& TileMap::at(int x, int y, int z){
	return tileMatrix->at(z).at(x).at(y);
}

void TileMap::render(float cameraX, float cameraY){
	if(!tileSet)
		return;

	for(int Z = 0; Z < mapLayers; Z++){
		for(int X = 0; X < mapHeight; X++){
			for(int Y = 0; Y < mapWidth; Y++){
				std::cout<<"X"<<X<<std::endl;
				std::cout<<"Y"<<Y<<std::endl;
				std::cout<<"Z"<<Z<<std::endl;
				if(tileMatrix->at(Z).at(Y).at(X) - 1 < 0)
				{

				}else{
				tileSet->render(tileMatrix->at(Z).at(Y).at(X) - 1, ((float)X - cameraX)*tileSet->getTileWidth(), ((float)Y - cameraY)*tileSet->getTileHeight());
				}
			}
		}
	}
}

void TileMap::renderLayer(float cameraX, float cameraY, int layer){
	if(!tileSet)
			return;

		for(int X = 0; X < mapWidth; X++){
			for(int Y = 0; Y < mapHeight; Y++){
				if(tileMatrix->at(layer).at(Y).at(X) - 1< 0)
					continue;

				tileSet->render(tileMatrix->at(layer).at(Y).at(X) - 1 , ((float)X - cameraX)*tileSet->getTileWidth(), ((float) Y - cameraY)*tileSet->getTileHeight());
			}
		}
}

int TileMap::width(){
	return this->mapWidth;
}

int TileMap::height(){
	return this->mapHeight;
}

int TileMap::layers(){
	return this->mapLayers;
}



