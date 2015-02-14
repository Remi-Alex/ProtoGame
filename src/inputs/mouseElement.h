//
//  mouseElement.h
//  V0.1 - 13/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef mouse_element_h
#define mouse_element_h

class MouseElement {
	public:
		// ----- Member(s)
		// ----- Function(s)
		MouseElement() {}

		~MouseElement() {}

		/**
		 *	Handles a new even a call the associated command
		 */
		virtual void mouseClicked(void) = 0;

		/**
		 *	Test if the MouseElement object contains a point of coordinates x,y
		 */
		virtual bool contain(int, int) = 0;
	protected:
	private:
		// ----- Member(s)
		// ----- Function(s)
};

#endif
