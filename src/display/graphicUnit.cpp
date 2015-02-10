//
//  graphicUnit.cpp
//  V0.1 - 08/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "graphicUnit.h"

GraphicUnit::GraphicUnit(Unit* u, Window* w) : unit(u), window(w), texture(w), loaded(false) {
	loaded = texture.loadFromFile("img/spriteSheet.png");
	gSpriteClips[ 0 ].x =   0;
	gSpriteClips[ 0 ].y =   0;
	gSpriteClips[ 0 ].w =  64;
	gSpriteClips[ 0 ].h = 205;

	gSpriteClips[ 1 ].x =  64;
	gSpriteClips[ 1 ].y =   0;
	gSpriteClips[ 1 ].w =  64;
	gSpriteClips[ 1 ].h = 205;

	gSpriteClips[ 2 ].x = 128;
	gSpriteClips[ 2 ].y =   0;
	gSpriteClips[ 2 ].w =  64;
	gSpriteClips[ 2 ].h = 205;

	gSpriteClips[ 3 ].x = 196;
	gSpriteClips[ 3 ].y =   0;
	gSpriteClips[ 3 ].w =  64;
	gSpriteClips[ 3 ].h = 205;
}

void GraphicUnit::render() {
	static int frame = 0;
	if(loaded) {
		SDL_Rect* currentClip = &gSpriteClips[ frame / 4 ];
		texture.render(unit->getPosX(), unit->getPosY(), currentClip );
	} else {
		SDL_SetRenderDrawColor(window->getGRenderer(), 0x00, 0x7C, 0x4E, 0x00); 
		SDL_Rect outlineRect = {unit->getPosX(), unit->getPosY(), 100, 100};
		SDL_RenderDrawRect(window->getGRenderer(), &outlineRect);
	}

	//++frame;

	//Cycle animation
	if(frame / 4 >= 4)
	{
    	frame = 0;
	}
}
