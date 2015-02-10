//
//  player.cpp
//  V0.1 - 23/01/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.
//

#include "player.h"

Player::Player() : Unit() {

}

void Player::move(const float& moveX, const float& moveY) {
	this->posX += moveX*movementSpeed;
	this->posY += moveY*movementSpeed;
}
