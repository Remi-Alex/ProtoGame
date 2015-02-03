//
//  command.cpp
//  V1 - 03/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef command_h
#define command_h

class Command {
	public:
		// ----- Member(s)
		// ----- Function(s)
		virtual ~Command() {}
		virtual void execute() = 0;
	protected:
	private:
};

#endif
