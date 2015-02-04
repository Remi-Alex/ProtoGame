//
//  inputHandler.cpp
//  V1 - 03/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "inputHandler.h"
#include <stdlib.h>
#include <iostream>

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

void InputHandler::handleInput(SDL_Event e) {
	switch(e.key.keysym.sym) {
		case SDLK_UP:
			std::cout << "Key up";
			break;

		case SDLK_DOWN:
			std::cout << "Key down";
			break;

		case SDLK_LEFT:
			std::cout << "Key left";
			break;

		case SDLK_RIGHT:
			std::cout << "Key right";
			break;

		default:
			std::cout << "Lauwl";
			break;
	}
}