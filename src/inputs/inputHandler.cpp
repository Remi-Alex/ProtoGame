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
	switch(e.key.keysym.sym) {
		case SDLK_UP:
			j--;
			break;

		case SDLK_DOWN:
			j++;
			break;

		case SDLK_LEFT:
			i--;
			break;

		case SDLK_RIGHT:
			i++;
			break;

		default:
			break;
	}

	if(i < 0) i = 0;
	if(j < 0) j = 0;

	SDL_SetRenderDrawColor( w->getGRenderer(), 0x00, 0x00, 0x00, 0x00 ); 
	SDL_Rect outlineRect = { i, j, 100, 100};
	SDL_RenderDrawRect( w->getGRenderer(), &outlineRect );
}