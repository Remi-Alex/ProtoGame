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
	for(unsigned short i = 0; i < NB_COMMAND_TYPES; ++i) {
		if(commands[i] != NULL) {
			delete commands[i];
		}
	}
	delete commands;
}

void InputHandler::handleInput(SDL_Event e, Window* w) {
	CommandTypes ct;
	switch(e.key.keysym.sym) {
		case SDLK_UP:
			ct = UP_ARROW;
			j--;
			break;

		case SDLK_DOWN:
			ct = DOWN_ARROW;
			j++;
			break;

		case SDLK_LEFT:
			ct = LEFT_ARROW;
			i--;
			break;

		case SDLK_RIGHT:
			ct = RIGHT_ARROW;
			i++;
			break;

		default:
			ct = OTHER;
			break;
	}

	if(ct != OTHER) {
		Command* c = commands[ct];
		if(c != NULL) c->execute();
	}

	if(i < 0) i = 0;
	if(j < 0) j = 0;

	SDL_SetRenderDrawColor( w->getGRenderer(), 0x00, 0x7C, 0x4E, 0x00 ); 
	SDL_Rect outlineRect = { i, j, 100, 100};
	SDL_RenderDrawRect( w->getGRenderer(), &outlineRect );
}

void InputHandler::bind(CommandTypes ct, Command* c) {
	commands[ct] = c;
}
