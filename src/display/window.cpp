//
//  window.cpp
//  V0.1 - 23/01/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "window.h"
#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

Window::Window() {
    // Initialize variables
    gWindow = NULL;
    gScreenSurface = NULL;
    gLoadedMedia = NULL;
    gRenderer = NULL;
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

            //gRenderer = SDL_GetRenderer(gWindow);
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                if((gRenderer = SDL_GetRenderer(gWindow)) == NULL) {
                    printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                    success = false;
                }
            } else {
                SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF ); 
            }
        }
    }
    
    return success;
}

bool Window::loadMedia(char* image)
{
    bool success = true;
    
    gLoadedMedia = IMG_Load(image);
    if( gLoadedMedia == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
        success = false;
    }
    
    return success;
}

void Window::close()
{
    if(gRenderer != NULL) {
        SDL_DestroyRenderer(gRenderer);
        gRenderer = NULL;
    }

    //Deallocate surface
    if(gLoadedMedia != NULL) {
        SDL_FreeSurface( gLoadedMedia );
        gLoadedMedia = NULL;
    }
    
    //Destroy window
    if(gWindow != NULL) {
        SDL_DestroyWindow( gWindow );
        gWindow = NULL;
    }
    
    //Quit SDL subsystems
    IMG_Quit();
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
        SDL_BlitSurface( gLoadedMedia, NULL, gScreenSurface, NULL );
        
        //Update the surface
        SDL_UpdateWindowSurface( gWindow );
        
        //Wait two seconds
        SDL_Delay( 2000 );
    }
}

SDL_Renderer* Window::getGRenderer() {
    return gRenderer;
}

