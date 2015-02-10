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
    gTexture = NULL;
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
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if( gRenderer == NULL )
            {
                if((gRenderer = SDL_GetRenderer(gWindow)) == NULL) {
                    printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                    success = false;
                }
            } else {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading 
                int imgFlags = IMG_INIT_PNG; 
                if( !( IMG_Init( imgFlags ) & imgFlags ) ) { 
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() ); 
                    success = false; 
                }
                loadMedia("img/hello_world.bmp");
            }
        }
    }
    
    return success;
}

bool Window::loadMedia(const std::string image)
{
    bool success = true;
    
    gTexture = loadTexture(image);
    if(gTexture == NULL)
    {
        printf( "Unable to load image %s! SDL Error: %s\n", image.c_str(), SDL_GetError() );
        success = false;
    }
    
    return success;
}

void Window::close()
{
    //Free loaded image 
    SDL_DestroyTexture( gTexture ); 
    gTexture = NULL;

    if(gRenderer != NULL) {
        SDL_RenderClear(gRenderer);
        SDL_DestroyRenderer(gRenderer);
        gRenderer = NULL;
    }

    //Destroy window
    if(gWindow != NULL) {
        SDL_DestroyWindow(gWindow);
        gWindow = NULL;
    }
    
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* Window::loadTexture(const std::string path) { 
    //The final texture 
    SDL_Texture* newTexture = NULL; 
    //Load image at specified path 
    SDL_Surface* loadedSurface = IMG_Load(path.c_str()); 
    
    if( loadedSurface == NULL ) { 
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() ); 
    } else { 
        //Create texture from surface pixels 
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface ); 

        if( newTexture == NULL ) { 
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() ); 
        } 
        //Get rid of old loaded surface 
        SDL_FreeSurface( loadedSurface ); 
    }

    return newTexture; 
} 

SDL_Renderer* Window::getGRenderer() {
    return gRenderer;
}

SDL_Texture* Window::getGTexture() {
    return gTexture;
}
