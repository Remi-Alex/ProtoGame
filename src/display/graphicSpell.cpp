//
//  graphicSpell.cpp
//  V0.1 - 03/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "graphicSpell.h"
#include <iostream>

GraphicSpell::GraphicSpell(Spell* s, Window* w, const float& x, const float& y) : spell(s), window(w), x(x), y(y) {}

GraphicSpell::GraphicSpell(GraphicSpell* gs) : spell(gs->spell), window(gs->window), x(gs->x), y(gs->y) {}

void GraphicSpell::render() {
	++x;
	++y;
	SDL_SetRenderDrawColor(window->getGRenderer(), 0x00, 0x7C, 0x4E, 0x00);
	SDL_Rect outlineRect = {(int) x, (int) y, 10, 10};
	SDL_RenderDrawRect(window->getGRenderer(), &outlineRect);
}
