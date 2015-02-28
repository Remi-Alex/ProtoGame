//
//  element.h
//  V0.1 - 28/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.
//

#ifndef element_h
#define element_h

/**
 *  @class Element
 *  
 */
class Element {
	private :
		// ----- Member(s)
		// ----- Function(s)
	protected :
		// ----- Member(s)
		int width, height;
		float posX, posY;
		// ----- Function(s)
	public :
		// ----- Member(s)
		// ----- Function(s)
		Element(int width, int height, float x, float y);

		int getWidth() { return width; }
		int getHeight() { return height; }
		float getPosX() { return posX; }
		float getPosY() { return posY; }
		void setPosX(const float& x) { posX = x; }
		void setPosY(const float& y) { posY = y; }
};

#endif
