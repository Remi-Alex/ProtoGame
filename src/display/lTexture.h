//
//  lTexture.h
//  V0.1 - 10/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef l_texture_h
#define l_texture_h

#include <SDL2/SDL.h>
#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif
#include <string>
#include "window.h"

class LTexture {
	public:
		//Initializes variables
		LTexture(Window*);

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile(const std::string& path);

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor(const Uint8& red, const Uint8& green, const Uint8& blue);

		//Set blending
		void setBlendMode(const SDL_BlendMode& blending);

		//Set alpha modulation
		void setAlpha(const Uint8& alpha);
		
		//Renders texture at given point
		void render(const int& x, const int& y, SDL_Rect* clip = NULL );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;
		Window* window;

		//Image dimensions
		int mWidth;
		int mHeight;
};

#endif
