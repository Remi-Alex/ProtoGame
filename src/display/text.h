//
//  text.h
//  V0.1 - 16/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef text_h
#define text_h

#include "window.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Text {
	public:
		// ----- Member(s)
		Text(std::string&, SDL_Color);
		~Text();
		// ----- Function(s)
		void render(Window*);
	private:
		// ----- Member(s)
		std::string text;
		SDL_Color color;
		TTF_Font* gFont;
		SDL_Texture* mTexture;
		// ----- Function(s)
};

#endif
