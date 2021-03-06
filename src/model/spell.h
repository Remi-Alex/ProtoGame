//
//  spell.h
//  V0.1 - 04/03/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef spell_h
#define spell_h


class Spell {
	public:
		// ----- Member(s)
		// ----- Function(s)
		Spell(const int&);

		~Spell() {}

		int getDuration() const;
	protected:
	private:
		int duration; //seconds
};

#endif
