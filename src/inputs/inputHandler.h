//
//  inputHandler.h
//  V0.1 - 03/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef input_handler_h
#define input_handler_h

#include "command.h"
#include "commandTypes.h"
#include "../display/window.h"
#include "../model/unit.h"
#include <SDL2/SDL.h>

#define NB_COMMAND_TYPES OTHER

class InputHandler {
	public:
		// ----- Member(s)
		// ----- Function(s)
		InputHandler();

		~InputHandler();

		/**
		 *	Handles a new even a call the associated command
		 */
		void handleInput(SDL_Event, Window* w);

		/**
		 *	
		 */
		void bind(CommandTypes, Command*);
	protected:
	private:
		// ----- Member(s)
		Command** commands;
		// ----- Function(s)
};

#endif
