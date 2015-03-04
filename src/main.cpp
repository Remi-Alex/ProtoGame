//
//  main.cpp
//  V0.1 - 24/01/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include <stdio.h>
#include <iostream>
#include <string>
#include "display/window.h"
#include "display/renderer.h"
#include "display/graphicUnit.h"
#include "display/text.h"
#include "display/textManager.h"
#include "display/graphicSpell.h"
#include "model/player.h"
#include "inputs/inputHandler.h"
#include "inputs/movementCommand.h"
#include "inputs/commandTypes.h"
#include "inputs/spellCommand.h"
#include "sound/sound.h"
#include "model/map.h"
#include "util/directions.h"

void gameLoop(Window w) {
	bool quit = false;
	SDL_Event e;
	InputHandler ih;

	Renderer* r = &Renderer::getInstance();

	Player p;
	Map map(&p);

	GraphicUnit gu(&p, &w);
	r->addUnit(&gu);
	InputHandler::AddMouseElement(&gu);

	std::string tTest = "test";
	SDL_Color tColor = {0, 0, 0};
	Text text(tTest, tColor, &w, 100, 200, 12);
	TextManager::addText(text);

	MovementCommand mc(&p);
	ih.bind(MOVE, &mc);

	Spell spell(10);
	GraphicSpell gs(&spell, &w, 10, 10, S);
	SpellCommand sc(&gs, &gu);
	ih.bind(BUTTON_1, &sc);
	
	Sound s("sound/music.wav");
	s.play();
	// Game loop
	while(!quit) {

		SDL_RenderClear(w.getGRenderer());
		SDL_RenderCopy(w.getGRenderer(), w.getGTexture(), NULL, NULL );

		//Handle events on queue
		while(SDL_PollEvent(&e) != 0 && !quit) {
			//User requests quit
			if(e.type == SDL_QUIT) {
				quit = true;
			} else if(e.type == SDL_KEYDOWN) {
				ih.handleSpells(e);
			} else {
				ih.handleMouse(e);
			}
		}

		signed char* dir = ih.handleMovement();
		//Handle collisions
		dir = map.handleMovementCollision(dir);
		ih.executeMovement(dir);

		r->render();
		TextManager::render();

		SDL_RenderPresent(w.getGRenderer());
	}
	w.close();
}

int main (int argc, char* args[]) {
	Window w;
	if(!w.init()) {
		printf( "Failed to initialize!\n" );
	}
	else {
		gameLoop(w);
	}

	return 0;
}
