//
//  graphicSpell.cpp
//  V0.1 - 03/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "graphicSpell.h"

GraphicSpell::GraphicSpell(Spell* s, Window* w, const float& x, const float& y, Directions d) : spell(s), window(w), x(x), y(y), direction(d) {}

GraphicSpell::GraphicSpell(GraphicSpell* gs) : spell(gs->spell), window(gs->window), x(gs->x), y(gs->y) {}

void GraphicSpell::render() {
	switch(direction) {
		case N:
			--y;
			break;
		case NE:
			--y;
			++x;
			break;
		case E:
			++x;
			break;
		case SE:
			++x;
			++y;
			break;
		case S:
			++y;
			break;
		case SW:
			++y;
			--x;
			break;
		case W:
			--x;
			break;
		case NW:
			--x;
			--y;
			break;
		default:
			break;
	}
	SDL_SetRenderDrawColor(window->getGRenderer(), 0x00, 0x7C, 0x4E, 0x00);
	SDL_Rect outlineRect = {(int) x, (int) y, 10, 10};
	SDL_RenderDrawRect(window->getGRenderer(), &outlineRect);
}

void GraphicSpell::setCoordinates(const float& nx, const float& ny, Directions d) {
	x = nx;
	y = ny;
	direction = d;
}
