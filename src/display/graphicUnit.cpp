//
//  graphicUnit.cpp
//  V0.1 - 08/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "graphicUnit.h"

GraphicUnit::GraphicUnit(Unit* u) : unit(u) {

}

void GraphicUnit::render(Window* w) {
	SDL_SetRenderDrawColor( w->getGRenderer(), 0x00, 0x7C, 0x4E, 0x00 ); 
	SDL_Rect outlineRect = { unit->getPosX(), unit->getPosY(), 100, 100};
	SDL_RenderDrawRect( w->getGRenderer(), &outlineRect );
}
