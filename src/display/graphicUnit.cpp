//
//  graphicUnit.cpp
//  V0.1 - 08/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "graphicUnit.h"
#include <iostream>

GraphicUnit::GraphicUnit(Unit* u, Window* w) : unit(u), window(w), texture(w), loaded(false), x(u->getPosX()), y(u->getPosY()),
	width(WIDTH), height(HEIGHT), lastDirection(S) {
	loaded = texture.loadFromFile("img/spriteSheet.png");
}

void GraphicUnit::render() {
	Directions frame = chooseFrame();
	if(loaded) {
		SDL_Rect currentClip;
		currentClip = {frame * width, 0, width, height};
		texture.render(unit->getPosX(), unit->getPosY(), &currentClip );
	} else {
		SDL_SetRenderDrawColor(window->getGRenderer(), 0x00, 0x7C, 0x4E, 0x00); 
		SDL_Rect outlineRect = {unit->getPosX(), unit->getPosY(), width, height};
		SDL_RenderDrawRect(window->getGRenderer(), &outlineRect);
	}
	x = unit->getPosX();
	y = unit->getPosY();
	lastDirection = frame;
}

Directions GraphicUnit::chooseFrame() {
	int unitX = unit->getPosX();
	int unitY = unit->getPosY();
	int difX = x - unitX;
	int difY = y - unitY;
	if(difX < 0) { // E
		if(difY < 0) { // S
			return SE;
		} else if(difY > 0) { // N
			return NE;
		} else {
			return E;
		}
	} else if(difX) { // W
		if(difY < 0) { // S
			return SW;
		} else if(difY > 0) { // N
			return NW;
		} else {
			return W;
		}
	} else { // No vertical movement
		if(difY < 0) { // S
			return S;
		} else if(difY > 0) { // N
			return N;
		} else {
			return lastDirection; // No movement, last position;
		}
	}
}

void GraphicUnit::mouseClicked() {
	std::cout << "test" << std::endl;
}

bool GraphicUnit::contain(int x, int y) {
	int posX = unit->getPosX();
	int posY = unit->getPosY();
	return x >= posX && x <= posX + width && y >= posY && y <= posY + height;
}
