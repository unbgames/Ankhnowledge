#include "TileMap.h"
#include <iostream>
#include "BlockMovable.h"
#include "BlockTreasure.h"
#include "BlockSand.h"
#include "BlockWater.h"
#define MOVABLE_BLOCK 1
#define NORMAL_TILE   0
#define TREASURE 2
#define SAND_BLOCK 3
#define WATER_BLOCK 4

using namespace std;

//Construtor do TileMap, passando o arquivo com o mapa dos tiles, o tileset e o tilesize
TileMap::TileMap(std::string mapa, Sprite* tile, Sprite* block, float posX, float posY)
{
    this->mapColumns = 0;
    this->mapRows = 0;
    this->tile = tile;
    this->block = block;
    this->posX = posX;
    this->posY = posY;
    //carrega o mapa
    load(mapa);

}

void TileMap::load(std::string mapPath) {
    //abre o arquivo indicando leitura
    FILE* mapFile = fopen(mapPath.c_str(), "r");
    if(mapFile == NULL) {
        return;
    }
    int index = 0;
    //pega a largura, altura e layers do mapa, indicados na primeira linha do arquivo
    fscanf(mapFile, "%d,%d,", &mapColumns, &mapRows);
    //pula 4 linhas para cair na posição exata dos indices dos tiles indicados no arquivo txt
    fscanf(mapFile, "\n\n\n\n");
    int id = 0;
    //loop que percorre as colunas, linhas e os layers do arquivo txt
    	cout<<"POS X "<<posX<<" POS T "<<posY<<"\n"<<endl;

        for(int y = 0;y < mapRows;y++)
        {
            for(int x = 0; x < mapColumns;x++)
            {

                fscanf(mapFile, "%d,", &index);
                cout<<"Index "<<index<<endl;
                if(index == NORMAL_TILE)
                {
                	cout<<"Entrei 1 x: "<<posX+ tile->getWidth()*x<< " y:" <<posY + tile->getHeight()*y<< "id "<<id<<"\n"<<endl;
                	tiles.push_back(new Tile(tile, 0,posX+ tile->getWidth()*((int)(id%mapColumns)), posY + tile->getHeight()*((int)(id/mapColumns)), id));
                }
                else if(index == MOVABLE_BLOCK)
                {
                	cout<<"Entrei 2 x: "<<posX+ tile->getWidth()*x<< " y:" <<posY + tile->getHeight()*y<< "id "<<id<<"\n"<<endl;
                	tiles.push_back(new Tile(tile
											, new BlockMovable(block,posX+ tile->getWidth()*((int)(id%mapColumns)), posY + tile->getHeight()*((int)(id/mapColumns)))
											, posX+ tile->getWidth()*((int)(id%mapColumns))
											, posY + tile->getHeight()*((int)(id/mapColumns))
											, id));
                }
                else if(index == TREASURE)
                {
                	cout<<"Entrei 2 x: "<<posX+ tile->getWidth()*x<< " y:" <<posY + tile->getHeight()*y<< "id "<<id<<"\n"<<endl;
					tiles.push_back(new Tile(tile
											, new BlockTreasure(block,posX+ tile->getWidth()*((int)(id%mapColumns)), posY + tile->getHeight()*((int)(id/mapColumns)))
											, posX+ tile->getWidth()*((int)(id%mapColumns))
											, posY + tile->getHeight()*((int)(id/mapColumns))
											, id));
                }
                else if(index == SAND_BLOCK)
                {
                    cout<<"Entrei 2 x: "<<posX+ tile->getWidth()*x<< " y:" <<posY + tile->getHeight()*y<< "id "<<id<<"\n"<<endl;
                    Sprite *sprite = new Sprite(SDLBase::resourcesPath + "areiamovedica.png");
                    tiles.push_back(new Tile(tile
                                            , new BlockSand(sprite,posX+ tile->getWidth()*((int)(id%mapColumns)), posY + tile->getHeight()*((int)(id/mapColumns)))
                                            , posX+ tile->getWidth()*((int)(id%mapColumns))
                                            , posY + tile->getHeight()*((int)(id/mapColumns))
                                            , id));
                }
                else if(index == WATER_BLOCK)
                {
                    cout<<"Entrei 2 x: "<<posX+ tile->getWidth()*x<< " y:" <<posY + tile->getHeight()*y<< "id "<<id<<"\n"<<endl;
                    Sprite *sprite = new Sprite(SDLBase::resourcesPath + "pote1.png");
                    tiles.push_back(new Tile(tile
                                            , new BlockWater(sprite,posX+ tile->getWidth()*((int)(id%mapColumns)), posY + tile->getHeight()*((int)(id/mapColumns)))
                                            , posX+ tile->getWidth()*((int)(id%mapColumns))
                                            , posY + tile->getHeight()*((int)(id/mapColumns))
                                            , id));
                }
                id++;
            }
            fscanf(mapFile, "\n");
            fscanf(mapFile, "\n");
        }
    //fecha arquivo
    fclose(mapFile);

}


vector<Tile* > TileMap::getTiles(){
	return this->tiles;
}

int TileMap::getColumns(){
	return this->mapColumns;
}

int TileMap::getRows(){
	return this->mapRows;
}

TileMap::~TileMap()
{

}
