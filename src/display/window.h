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
        SDL_Surface* gLoadedMedia;
    
        /**
         *  Loads a media
         *  @param image the media to be loaded
         *  @return true if it has been correctly loaded
         */
        bool loadMedia(char* image);

    public :
        /**
         *  Constructor of the Window class
         */
        Window();
    
        /**
         *  Initialize the window
         *  @return true if it's been correctly initialized
         */
        bool init(void);

        /**
         *  Used to properly close the window. Also free the memory
         */
        void close(void);
    
        /**
         *  Display an image in the window
         *  @param image the image to be displayed
         */
        void displayImage(char* image);
};

#endif
