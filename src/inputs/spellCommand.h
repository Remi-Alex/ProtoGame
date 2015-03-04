//
//  movementCommand.h
//  V0.1 - 04/03/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef spell_command_h
#define spell_command_h

#include "command.h"
#include "../display/graphicSpell.h"

class SpellCommand : public Command {
	public:
		// ----- Member(s)
		// ----- Function(s)
		SpellCommand(GraphicSpell*);

		~SpellCommand() {}

		void execute(void*);
	protected:
	private:
		GraphicSpell* graphicSpell;
};

#endif
