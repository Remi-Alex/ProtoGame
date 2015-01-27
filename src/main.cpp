//
//  main.cpp
//  V1 - 24/01/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include <stdio.h>
#include "display/window.h"
#include "model/unit.h"

int main( int argc, char* args[] )
{
	Window w;
	if( !w.init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		w.displayImage("img/hello_world.bmp");

		bool quit = false;
		SDL_Event e;

		// Game loop
		while( !quit )
		{
			//Handle events on queue
			while( SDL_PollEvent( &e ) != 0 )
			{
				//User requests quit
				if( e.type == SDL_QUIT )
				{
					quit = true;
					w.close();
				}
			}
		}
	}

return 0;
}
