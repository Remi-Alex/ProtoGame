/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
 and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <stdio.h>
#include "display/window.h"
#include "model/unit.h"

int main( int argc, char* args[] )
{
    Window w;
    //Start up SDL and create window
    if( !w.init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        w.displayImage();
    }
    
    //Free resources and close SDL
    //w.close();
    
    return 0;
}
