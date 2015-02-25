//
//  movementCommand.cpp
//  V0.1 - 08/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "movementCommand.h"
#include "commandTypes.h"

MovementCommand::MovementCommand(Player* p) : player(p){}

void MovementCommand::execute(void* direction) {
	signed char* dir = (signed char*)direction;
	//FIXME : movement in diagonal is faster 
	//-> using int instead of float
	int newSpeed = SPEED;
	if(dir[X] != 0 && dir[Y] != 0) {
		newSpeed *= sqrt(2);
	}
	if(dir[Y] == -1) {
		player->setPosY(player->getPosY() - newSpeed);
	} else if(dir[Y] == 1) {
		player->setPosY(player->getPosY() + newSpeed);
	} if(dir[X] == -1) {
		player->setPosX(player->getPosX() - newSpeed);
	} else if(dir[X] == 1) {
		player->setPosX(player->getPosX() + newSpeed);
	}
}
