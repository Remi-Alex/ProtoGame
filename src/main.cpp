//
//  main.cpp
//  V1 - 24/01/2015
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
				w.close();
			} else if(e.type == SDL_KEYDOWN) {
				ih.handleInput(e, &w);
			}
		}
		SDL_RenderPresent(w.getGRenderer());
	}
}

int main (int argc, char* args[]) {
	Window w;
	if(!w.init()) {
		printf( "Failed to initialize!\n" );
	}
	else {
		//w.displayImage("img/hello_world.bmp");

		gameLoop(w);
	}

	return 0;
}
