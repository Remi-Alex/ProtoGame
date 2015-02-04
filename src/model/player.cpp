//
//  player.cpp
//  V1 - 23/01/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.
//

#include "player.h"

Player::Player() : Unit() {

}

void Player::move(float moveX, float moveY) {
	this->posX += moveX;
	this->posY += moveY;
}
