//
//  graphicSpell.h
//  V0.1 - 04/03/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef graphic_spell_h
#define graphic_spell_h

#include "../model/spell.h"

class GraphicSpell {
	public:
		// ----- Member(s)
		// ----- Function(s)
		GraphicSpell(Spell* s);

		~GraphicSpell() {}
	protected:
	private:
		Spell* spell;
};

#endif
