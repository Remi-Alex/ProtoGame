//
//  text.cpp
//  V0.1 - 16/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "text.h"

TTF_Font* Text::gFont = NULL;

Text::Text(std::string& t, SDL_Color c, Window* w, const int& x, const int& y, const int& size) : text(t), color(c), mTexture(w), x(x), y(y), size(size) {
	if(Text::gFont == NULL) {
		Text::gFont = TTF_OpenFont("fonts/lazy.ttf", size);
		if(Text::gFont == NULL) {
			printf("Unable to create font! SDL Error: %s\n", SDL_GetError());
		} else {
			mTexture.loadFromText(gFont, text, color);
		}
	}
}

Text::~Text() {
	mTexture.free();
}

void Text::render() {
	mTexture.render(x, y);
}
