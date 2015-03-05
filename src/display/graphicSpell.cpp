//
//  graphicSpell.cpp
//  V0.1 - 03/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "graphicSpell.h"

GraphicSpell::GraphicSpell(Spell* s, Window* w, const float& x, const float& y, Directions d) : spell(s), window(w), x(x), y(y), direction(d), duration(0) {}

GraphicSpell::GraphicSpell(GraphicSpell* gs) : spell(gs->spell), window(gs->window), x(gs->x), y(gs->y), duration(gs->duration) {}

void GraphicSpell::render() {
	switch(direction) {
		case N:
			y-=SPEED;
			break;
		case NE:
			y-=SPEED;
			x+=SPEED;
			break;
		case E:
			x+=SPEED;
			break;
		case SE:
			x+=SPEED;
			y+=SPEED;
			break;
		case S:
			y+=SPEED;
			break;
		case SW:
			y+=SPEED;
			x-=SPEED;
			break;
		case W:
			x-=SPEED;
			break;
		case NW:
			x-=SPEED;
			y-=SPEED;
			break;
		default:
			break;
	}

	SDL_SetRenderDrawColor(window->getGRenderer(), 0x00, 0x7C, 0x4E, 0x00);
	SDL_Rect outlineRect = {(int) x, (int) y, 10, 10};
	SDL_RenderDrawRect(window->getGRenderer(), &outlineRect);

	++duration;
}

void GraphicSpell::setCoordinates(const float& nx, const float& ny, Directions d) {
	x = nx;
	y = ny;
	direction = d;
}

int GraphicSpell::getRemainingDuration() const {
	return spell->getDuration() - duration;
}
