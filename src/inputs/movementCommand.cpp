//
//  movementCommand.cpp
//  V0.1 - 08/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "movementCommand.h"
#include "commandTypes.h"

MovementCommand::MovementCommand(Player* p, Directions direction) : player(p), direction(direction){}

void MovementCommand::execute() {
	if(direction == N) {
		player->setPosY(player->getPosY() - SPEED);
	} else if(direction == S) {
		player->setPosY(player->getPosY() + SPEED);
	} else if(direction == W) {
		player->setPosX(player->getPosX() - SPEED);
	} else if(direction == E) {
		player->setPosX(player->getPosX() + SPEED);
	}
}
