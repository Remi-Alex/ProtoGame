//
//  movementCommand.h
//  V0.1 - 08/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef movement_command_h
#define movement_command_h

#include "command.h"

class MovementCommand : public Command {
	public:
		// ----- Member(s)
		// ----- Function(s)
		MovementCommand(Player* p);

		~MovementCommand() {}

		void execute(void*);
	protected:
	private:
		Player* player;
};

#endif
