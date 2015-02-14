//
//  inputHandler.cpp
//  V0.1 - 03/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "inputHandler.h"
#include <stdlib.h>
#include <iostream>

/** static members **/
std::vector<MouseElement*> InputHandler::mouseElements;

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
	} else if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {
		int x, y;
		SDL_GetMouseState(&x, &y);

		MouseElement* me;
		std::vector<MouseElement*>::iterator it = InputHandler::mouseElements.begin();
		while(it != InputHandler::mouseElements.end()) {
			// Change depending on type of event
			me = (*it);
			if(me->contain(x, y)) {
				if(e.type == SDL_MOUSEBUTTONDOWN) me->mouseClicked();
			}
			++it;
        }
	}
}

void InputHandler::bind(const CommandTypes& ct, Command* c) {
	commands[ct] = c;
}
