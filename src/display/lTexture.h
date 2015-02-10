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
		bool loadFromFile( std::string path );

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );
		
		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL );

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
