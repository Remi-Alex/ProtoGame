//
//  graphicUnit.h
//  V0.1 - 08/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef graphic_unit_h
#define graphic_unit_h

#include "../model/unit.h"
#include "window.h"
#include "lTexture.h"
#include "../inputs/mouseElement.h"
#include "../util/directions.h"

#define SIZE_RECT_ERROR 100

class GraphicUnit : public MouseElement {
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

		//@Override
		void mouseClicked(void);
		//@Override
		bool contain(int, int);

		Directions getLastDirection(void) const;

		int getX(void) const;
		int getY(void) const;

		int getWidth(void) const;
		int getHeight(void) const;

	private:
		// ----- Member(s)
		Unit* unit;
		Window* window;
		LTexture texture;
		bool loaded;
		int x;
		int y;
		static const int NB_FRAMES = 8;
		Directions lastDirection;
		// ----- Function(s)
		Directions chooseFrame();
};

#endif
