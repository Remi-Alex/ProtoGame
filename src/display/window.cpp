//
//  window.cpp
//  V1 - 23/01/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "window.h"
#include <SDL2_image/SDL_image.h>

Window::Window() {
    // Initialize variables
    gWindow = NULL;
    gScreenSurface = NULL;
    gHelloWorld = NULL;
}

bool Window::init()
{
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "ProtoGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    
    return success;
}

bool Window::loadMedia(char* image)
{
    //Loading success flag
    bool success = true;
    
    //Load splash image
    gHelloWorld = IMG_Load(image);
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
        success = false;
    }
    
    return success;
}

void Window::close()
{
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;
    
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    
    //Quit SDL subsystems
    SDL_Quit();
}

void Window::displayImage(char* image) {
    //Load media
    if( !loadMedia(image) )
    {
        printf( "Failed to load media!\n" );
    }
    else
    {
        //Apply the image
        SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
        
        //Update the surface
        SDL_UpdateWindowSurface( gWindow );
        
        //Wait two seconds
        SDL_Delay( 2000 );
    }
}

