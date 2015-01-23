//
//  unit.h
//  V1 - 23/01/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.
//
// TODO: think about smarter types

#ifndef unit__h
#define unit__h

#include <stdio.h>

/**
 *  @class Unit
 *  Useful comments
 */
class Unit {
    private :
    // ----- Member(s)
    /**
     *  Description
     */
    // ----- Function(s)
    protected :
    // ----- Member(s)
    int maxHP;
    int HP;
    int maxMana;
    int mana;
    int physicalPower;
    int magicalPower;
    float attackSpeed;
    float movementSpeed;
    int armor;
    int precision;
    int manaRegen;
    int dodge;
    int criticalLuck;
    // ----- Function(s)
    public :
    // ----- Member(s)
    // ----- Function(s)
    /**
     *  Default constructor with no parameters
     */
    Unit();
};

#endif /* defined(example__h) */
