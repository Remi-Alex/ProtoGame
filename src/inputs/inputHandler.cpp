//
//  inputHandler.cpp
//  V1 - 03/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "inputHandler.h"
#include <stdlib.h>

InputHandler::InputHandler() {
	commands = (Command**) malloc(sizeof(Command*) * NB_COMMAND_TYPES);
}

InputHandler::~InputHandler() {
	free(commands);
}

void InputHandler::handleInput() {
	/*if (isPressed(BUTTON_X)) {
		buttonX_->execute();
	}*/
}