//
//  inputHandler.h
//  V1 - 03/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef input_handler_h
#define input_handler_h
#include "command.h"

class InputHandler {
	public:
		// ----- Member(s)
		// ----- Function(s)
		void handleInput();
	protected:
	private:
		// ----- Member(s)
		Command* button1;
		Command* button2;
		Command* button3;
		Command* button4;
		Command* upArrow;
		Command* downArrow;
		Command* leftArrow;
		Command* rightArrow;
		// ----- Function(s)
};

#endif
