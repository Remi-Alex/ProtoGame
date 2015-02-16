//
//  text.cpp
//  V0.1 - 16/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "text.h"

Text::Text(std::string& t, SDL_Color c) : text(t), color(c), gFont(NULL), mTexture(NULL) {
	gFont = TTF_OpenFont("fonts/lazy.ttf", 28);
	if(gFont == NULL) {
		printf("Unable to create font! SDL Error: %s\n", SDL_GetError());
	}
}

Text::~Text() {
	if(mTexture != NULL) SDL_DestroyTexture(mTexture);
}

void Text::render(Window* window) {
	if(gFont != NULL) {
		SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, text.c_str(), color);
		if(textSurface == NULL) {
			printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
		} else {
			//Create texture from surface pixels
			mTexture = SDL_CreateTextureFromSurface(window->getGRenderer(), textSurface);
			if(mTexture == NULL) {
				printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
			}

			//Get rid of old surface
			SDL_FreeSurface(textSurface);
		}
	}
}
