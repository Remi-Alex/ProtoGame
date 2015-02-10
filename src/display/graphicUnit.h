//
//  graphicUnit.h
//  V0.1 - 08/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef graphic_unit_h
#define graphic_unit_h

#include "../model/unit.h"
#include "window.h"
#include "LTexture.h"

typedef enum Directions {
	S,
	SW,
	W,
	NW,
	N,
	NE,
	E,
	SE
} Directions;

class GraphicUnit {
	public:
		// ----- Member(s)
		// ----- Function(s)
		/**
		 *	Constructor
		 */
		GraphicUnit(Unit*, Window*);

		/**
		 *	Used to render an Unit
		 */
		void render();

	private:
		// ----- Member(s)
		Unit* unit;
		Window* window;
		LTexture texture;
		bool loaded;
		int x;
		int y;
		int width;
		int height;
		static const int NB_FRAMES = 8;
		Directions lastDirection;
		// ----- Function(s)
		Directions chooseFrame();
};

#endif
