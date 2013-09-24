#ifndef TILEMAP_H_
#define TILEMAP_H_

#include <vector>
#include <string>
#include <stdlib.h>
#include "TileSet.h"

class TileMap {

public:

	TileMap(int mapWidth, int mapHeight, int tileSize, int layers = 1, TileSet * tileSet = NULL);
	TileMap(std::string mapa, TileSet * tileSet = NULL);
	TileMap(std::string mapa, int tileSize, TileSet* tileSet);
	virtual ~TileMap();
	void load(std::string mapPath);
	void setTileSet(TileSet * tileset);
	int& at(int x, int y, int z = 0);
	void render(float cameraX = 0.0, float cameraY = 0.0);
	void renderLayer(float cameraX = 0.0, float cameraY = 0.0, int layer = 0);
	int width();
	int height();
	int layers();

private:
	std::vector<std::vector <std::vector <int> > > * tileMatrix;
	TileSet * tileSet;
	int mapWidth, mapHeight, mapLayers;
};

#endif /* TILEMAP_H_ */
