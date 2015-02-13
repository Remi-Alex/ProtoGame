//
//  inputHandler.cpp
//  V0.1 - 03/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "inputHandler.h"
#include <stdlib.h>
#include <iostream>

int i, j = 0;

InputHandler::InputHandler() {
	commands = new Command* [NB_COMMAND_TYPES];
	for(unsigned short i = 0; i < NB_COMMAND_TYPES; ++i) {
		commands[i] = NULL;
	}
}

InputHandler::~InputHandler() {
	// TODO: Move it, if the handler doesn't create the Command objects
	// for(unsigned short i = 0; i < NB_COMMAND_TYPES; ++i) {
	// 	if(commands[i] != NULL) {
	// 		delete commands[i];
	// 	}
	// }
	delete commands;
}

void InputHandler::handleInput(const SDL_Event& e) {
	if(e.type == SDL_KEYDOWN) {
		CommandTypes ct;
		switch(e.key.keysym.sym) {
			case SDLK_UP:
				ct = UP_ARROW;
				break;

			case SDLK_DOWN:
				ct = DOWN_ARROW;
				break;

			case SDLK_LEFT:
				ct = LEFT_ARROW;
				break;

			case SDLK_RIGHT:
				ct = RIGHT_ARROW;
				break;

			default:
				ct = OTHER;
				break;
		}

		if(ct != OTHER) {
			Command* c = commands[ct];
			if(c != NULL) c->execute(&ct);
		}
	} else {
		
	}
}

void InputHandler::bind(const CommandTypes& ct, Command* c) {
	commands[ct] = c;
}
