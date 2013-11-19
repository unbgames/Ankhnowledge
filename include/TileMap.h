#ifndef TILEMAP_H
#define TILEMAP_H
#include <vector>
#include <string>
#include "Tile.h"
#include "Sprite.h"

class TileMap
{
    public:
        TileMap(std::string mapa, Sprite*tile,Sprite* block,float posX, float posY);
        void load(std::string mapPath);
        vector<Tile* > getTiles();
        int getColumns();
        int getRows();
        virtual ~TileMap();

    private:
        vector<Tile* > tiles;
        Sprite* tile, *block;
        int mapColumns, mapRows;
        float posX, posY;
};

#endif // TILEMAP_H
