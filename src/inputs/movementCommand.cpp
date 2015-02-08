//
//  movementCommand.cpp
//  V0.1 - 08/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "movementCommand.h"
#include "CommandTypes.h"

MovementCommand::MovementCommand(Player* p) : player(p) {}

void MovementCommand::execute(void* param) {
	int direction = *((int*) param);
	if(direction == UP_ARROW) {
		player->setPosY(player->getPosY() - SPEED);
	} else if(direction == DOWN_ARROW) {
		player->setPosY(player->getPosY() + SPEED);
	} else if(direction == LEFT_ARROW) {
		player->setPosX(player->getPosX() - SPEED);
	} else if(direction == RIGHT_ARROW) {
		player->setPosX(player->getPosX() + SPEED);
	}
}
