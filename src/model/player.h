//
//  player.h
//  V0.1 - 23/01/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.
//

#ifndef player__h
#define player__h

#include "unit.h"

/**
 *  @class Player
 *  
 */
class Player : public Unit {
    private :
        // ----- Member(s)
        
        // ----- Function(s)
        
    protected :
        // ----- Member(s)
        // ----- Function(s)
    public :
        // ----- Member(s)
        // ----- Function(s)
        Player();
        //@Override
        void move(const float& moveX, const float& moveY);
        //@Override
        void mouseClicked(void);
};

#endif
