//
//  renderer.h
//  V0.1 - 08/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef renderer_h
#define renderer_h

#include "window.h"
#include "graphicUnit.h"
#include <list>

class Renderer {
	public:
		// ----- Member(s)
		// ----- Function(s)
		/**
		 *	Creates a static and unique instance of renderer and returns it
		 *	return the unique instance of class Renderer
		 */
		static Renderer& getInstance() {
			static Renderer	instance;
			return instance;
		}

		/**
		 *	Render all the elements of the game
		 */
		void render(void);

		/**
		 *	Adds a unit to the list of units to display
		 *	@param c the new unit to display
		 *	@return true if it as been correctly added to the list
		 */
		bool addUnit(GraphicUnit*);

		/**
		 *	Removes a unit from the list of units to display
		 *	@param c the unit to remove
		 *	@return true if it as been correctly removed from the list
		 */
		bool removeUnit(GraphicUnit*); 

	private:
		// ----- Member(s)
		// TODO: Change for GaphicalUnit
		std::list<GraphicUnit*> units;
		// ----- Function(s)
		Renderer();
		Renderer(Renderer const&) {}
		void operator=(Renderer const&)	{}
};

#endif
