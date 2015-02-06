//
//  main.cpp
//  V0.1 - 24/01/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include <stdio.h>
#include "display/window.h"
#include "model/unit.h"
#include "inputs/inputHandler.h"

void gameLoop(Window w) {
	bool quit = false;
	SDL_Event e;
	InputHandler ih;

	// Game loop
	while(!quit) {
		//Handle events on queue
		while(SDL_PollEvent(&e) != 0) {
			//User requests quit
			if(e.type == SDL_QUIT) {
				quit = true;
			} else if(e.type == SDL_KEYDOWN) {
				ih.handleInput(e, &w);
			}
		}
		
		//Update screen
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
		//Clear screen 
		SDL_RenderClear(w.getGRenderer()); 
		//Render texture to screen 
		SDL_RenderCopy(w.getGRenderer(), w.getGTexture(), NULL, NULL );

		gameLoop(w);
	}

	return 0;
}
