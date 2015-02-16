//
//  textManager.h
//  V0.1 - 16/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef text_manager_h
#define text_manager_h

#include <vector>
#include <SDL2/SDL.h>
#include "text.h"
#include "window.h"

class TextManager {
	public:
		// ----- Member(s)
		// ----- Function(s)
		static void render();
		static void addText(const Text&);
	private:
		// ----- Member(s)
		static std::vector<Text> texts;
		// ----- Function(s)
		TextManager();
};

#endif
