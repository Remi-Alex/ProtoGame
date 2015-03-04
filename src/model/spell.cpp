//
//  inputHandler.cpp
//  V0.1 - 03/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "spell.h"

Spell::Spell(const int& d) : duration(d) {}

int Spell::getDuration() const {
	return duration;
}
