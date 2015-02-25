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

void InputHandler::handleMouse(const SDL_Event& e) {
	
	if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {
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

void InputHandler::handleKeyboard() {
	//Set texture based on current keystate 
	const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL ); 
	
	if(currentKeyStates[SDL_SCANCODE_UP]) { 
		commands[UP_ARROW]->execute();
	} if(currentKeyStates[SDL_SCANCODE_DOWN]) { 
		commands[DOWN_ARROW]->execute();
	} if(currentKeyStates[SDL_SCANCODE_LEFT]) { 
		commands[LEFT_ARROW]->execute();
	} if(currentKeyStates[SDL_SCANCODE_RIGHT]) { 
		commands[RIGHT_ARROW]->execute();
	}
}

void InputHandler::bind(const CommandTypes& ct, Command* c) {
	commands[ct] = c;
}
