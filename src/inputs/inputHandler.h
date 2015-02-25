//
//  inputHandler.h
//  V0.1 - 03/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef input_handler_h
#define input_handler_h

#include "command.h"
#include "commandTypes.h"
#include "mouseElement.h"
#include "../display/window.h"
#include "../model/unit.h"
#include <SDL2/SDL.h>
#include <vector>

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
		std::vector<Command*> handleInput(const SDL_Event&);

		/**
		 *	Binds a command to a command type
		 */
		void bind(const CommandTypes&, Command*);

		/**
		 *	Adds a mouse element to the list of elements which are mouse interactive
		 */
		static void AddMouseElement(MouseElement* me) {
			mouseElements.push_back(me);
		}

		/**
		 *	Deletes a mouse element to the list of elements which are mouse interactive
		 */
		 // TODO
		static void DeleteMouseElement(MouseElement*);
	protected:
	private:
		// ----- Member(s)
		Command** commands;
		static std::vector<MouseElement*> mouseElements;
		// ----- Function(s)
};

#endif
