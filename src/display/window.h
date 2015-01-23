//
//  window.h
//  src
//
//  Created by Rémi MARTIN on 23/01/2015.
//  Copyright (c) 2015 Rémi MARTIN. All rights reserved.
//

#ifndef src_window_h
#define src_window_h

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
