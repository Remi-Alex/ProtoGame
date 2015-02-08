//
//  main.cpp
//  V0.1 - 24/01/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include <stdio.h>
#include "display/window.h"
#include "display/renderer.h"
#include "model/unit.h"
#include "inputs/inputHandler.h"

void gameLoop(Window w) {
	bool quit = false;
	SDL_Event e;
	InputHandler ih;

	Renderer* r = &Renderer::getInstance(w);

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
			} else if(e.type == SDL_KEYDOWN) {
				ih.handleInput(e, &w);
			}
		}

		r->render();

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
