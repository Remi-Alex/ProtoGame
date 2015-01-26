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
        w.displayImage();
    }
    
    //Free resources and close SDL
    w.close();
    
    return 0;
}
