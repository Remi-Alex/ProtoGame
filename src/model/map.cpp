//
//  map.cpp
//  V0.1 - 04/03/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.
//
#include "map.h"

Map::Map(Player* p) : player(p) {
	for (int i = 0; i<MAP_HEIGHT; i++){
		for(int j = 0; j<MAP_WIDTH; j++){
			elements[i][j] = NULL;
		}
	}
}

Map::~Map() {
	for (int i = 0; i<MAP_HEIGHT; i++){
		for(int j = 0; j<MAP_WIDTH; j++){
			delete elements[i][j];
		}
	}
}

signed char* Map::handleMovementCollision(signed char* dir) {
	if ((dir[X] < 0 && player->getPosX() <= 0) || 
		(dir[X] > 0 && player->getPosX()+player->getWidth() >= MAP_WIDTH*BOX_SIZE)) {
		dir[X] = 0;
	}
	if ((dir[Y] < 0 && player->getPosY() <= 0) ||
		(dir[Y] > 0 && player->getPosY()+player->getHeight() >= MAP_HEIGHT*BOX_SIZE)) {
		dir[Y] = 0;
	}

	return dir;
}

void Map::addElement(Element* element, int x, int y) {
	elements[x][y] = element;
}
