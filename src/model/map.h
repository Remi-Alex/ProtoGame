//
//  map.h
//  V0.1 - 04/03/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef map_h
#define map_h

#include "player.h"
#include "element.h"
#include "../inputs/direction.h"

//Number of boxes 
#define MAP_WIDTH 15
#define MAP_HEIGHT 10
#define BOX_SIZE 30

class Map {
	public:
		// ----- Member(s)
		// ----- Function(s)
		Map(Player* p);
		
		~Map();

		/*
		 *	Handles the player collisions 
		*/
		signed char* handleMovementCollision(signed char* dir);

		/*
		 *	Adds an element to the matrix
		 */
		void addElement(Element*, int x, int y);
	protected:
	private:
		// ----- Member(s)
		Player* player;

		//Matrix of elements that are on the map
		Element* elements[MAP_HEIGHT][MAP_WIDTH];
		// ----- Function(s)
};
#endif
