//
//  element.cpp
//  V0.1 - 28/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.
//

#include "element.h"
#include <iostream>

Element::Element(int w, int h, float x, float y) : posX(x), posY(y), width(w), height(h) {
}

bool Element::collides(Element e) {
	if(posX < e.getPosX() + e.getWidth() &&
		posX + getWidth() > e.getPosX() &&
		posY < e.getPosY() + e.getHeight() &&
		posY + getHeight() > e.getPosY()) {
		return true;
	}
	return false;
}
