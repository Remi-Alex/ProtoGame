//
//  main.cpp
//  V0.1 - 24/01/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include <stdio.h>
#include <string>
#include "display/window.h"
#include "display/renderer.h"
#include "display/graphicUnit.h"
#include "display/text.h"
#include "display/textManager.h"
#include "model/player.h"
#include "inputs/inputHandler.h"
#include "inputs/movementCommand.h"
#include "inputs/commandTypes.h"
#include "sound/sound.h"

void gameLoop(Window w) {
	bool quit = false;
	SDL_Event e;
	InputHandler ih;

	Renderer* r = &Renderer::getInstance();

	Player p;
	GraphicUnit gu(&p, &w);
	r->addUnit(&gu);
	InputHandler::AddMouseElement(&gu);

	std::string tTest = "test";
	SDL_Color tColor = {0, 0, 0};
	Text text(tTest, tColor, &w, 100, 200, 12);
	TextManager::addText(text);

	MovementCommand mc(&p);
	ih.bind(MOVE, &mc);
	
	Sound s("sound/beat.wav", EFFECT);
	s.play();

	// Game loop
	while(!quit) {

		// FIXME: The square is not displayed when not beeing moved
		SDL_RenderClear(w.getGRenderer());
		SDL_RenderCopy(w.getGRenderer(), w.getGTexture(), NULL, NULL );

		//Handle events on queue
		while(SDL_PollEvent(&e) != 0 && !quit) {
			//User requests quit
			if(e.type == SDL_QUIT) {
				quit = true;
			} else {
				ih.handleMouse(e);
			}
		}
		signed char* dir = ih.handleKeyboard();
		//Handle collisions
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
