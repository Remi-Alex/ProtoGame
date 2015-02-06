//
//  window.h
//  V0.1 - 23/01/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#ifndef window_h
#define window_h

#include <SDL2/SDL.h>

class Window {
    private :
        //Screen dimension constants
        static const int SCREEN_WIDTH = 640;
        static const int SCREEN_HEIGHT = 480;
    
        //The window we'll be rendering to
        SDL_Window* gWindow;
    
        //The image we will load and show on the screen
        SDL_Texture* gTexture;

        //The window renderer
        SDL_Renderer* gRenderer;
    
        /**
         *  Loads a media
         *  @param image the media to be loaded
         *  @return true if it has been correctly loaded
         */
        bool loadMedia(char* image);

        SDL_Texture* loadTexture(char* path );

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
    
        SDL_Renderer* getGRenderer();

        SDL_Texture* getGTexture();
};

#endif
