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

		/**
		 *	@return the width of the unit
		 */
		int getWidth() { return width; }

		/**
		 *	@return the height of the unit
		 */
		int getHeight() { return height; }

		/**
		 *	@return the posX of the unit
		 */
		float getPosX() { return posX; }

		/**
		 *	@return the posY of the unit
		 */
		float getPosY() { return posY; }

		/**
		 *	@param the new posX of the unit
		 */
		void setPosX(const float& x) { posX = x; }

		/**
		 *	@param the new posY of the unit
		 */
		void setPosY(const float& y) { posY = y; }
};

#endif
