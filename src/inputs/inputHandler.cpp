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

signed char* InputHandler::handleMovement() {
	//Set texture based on current keystate 
	const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL ); 
	
	//Direction table
	// X => -1 Left, 1 Right
	// Y => -1 Up, 1 Down
	signed char* dir = new signed char[2];
	dir[X] = 0;
	dir[Y] = 0;

	if(currentKeyStates[SDL_SCANCODE_UP]) { 
		dir[Y]--;
	} if(currentKeyStates[SDL_SCANCODE_DOWN]) {
		dir[Y]++;
	} if(currentKeyStates[SDL_SCANCODE_LEFT]) { 
		dir[X]--;
	} if(currentKeyStates[SDL_SCANCODE_RIGHT]) { 
		dir[X]++;
	}

	return dir;
}

void InputHandler::executeMovement(signed char* dir){
	commands[MOVE]->execute(dir);
	delete[] dir;
}

void InputHandler::bind(const CommandTypes& ct, Command* c) {
	commands[ct] = c;
}

Command* InputHandler::handleSpells(const SDL_Event& e) {
	Command* c = NULL;
	switch(e.key.keysym.sym){
		case SDLK_a:
			c = commands[BUTTON_1];
			break;
		case SDLK_z:
			c = commands[BUTTON_2];
			break;
		case SDLK_e:
			c = commands[BUTTON_3];
			break;
		case SDLK_r:
			c = commands[BUTTON_4];
			break;
		default:
			break;
	}
	if(c != NULL)
		c->execute(NULL);
	return c;
}
