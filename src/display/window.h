//
//  window.h
//  V1 - 23/01/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef window_h
#define window_h

#include <SDL2/SDL.h>

class Window {
    private :
        //Screen dimension constants
        const int SCREEN_WIDTH = 640;
        const int SCREEN_HEIGHT = 480;
    
        //The window we'll be rendering to
        SDL_Window* gWindow;
    
        //The surface contained by the window
        SDL_Surface* gScreenSurface;
    
        //The image we will load and show on the screen
        SDL_Surface* gHelloWorld;
    
        //Loads media
        bool loadMedia(void);

    public :
        Window();
    
        //Starts up SDL and creates window
        bool init(void);

        //Frees media and shuts down SDL
        void close(void);
    
        void displayImage(void);
};

#endif

