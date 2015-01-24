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
    unsigned short strength;
    unsigned short stamina;
    unsigned short dexterity;
    unsigned short intelligence;
    unsigned short will;
    unsigned short luck;
    
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
    int criticalChance;
    int lifeSteal;
    int penetration;
    int lifeRegen;
    // ----- Function(s)
    /**
     *  Computes all stats
     */
    void computeStats();
    
    /**
     *  Computes HP of the unit
     *  @return the amount of health points of the unit
     */
    int computeHP();
    
    /**
     *  Computes mana of the unit
     *  @return the amount of mana points of the unit
     */
    int computeMana();
    
    /**
     *  Computes the physical power of the unit
     *  @return the amount of physical power of the unit
     */
    int computePhysicalPower();
    
    /**
     *  Computes the magical power of the unit
     *  @return the amount of magical power of the unit
     */
    int computeMagicalPower();
    
    /**
     *  Computes the attack speed of the unit
     *  @return the amount of attack speed of the unit
     */
    float computeAttackSpeed();
    
    /**
     *  Computes the movement speed of the unit
     *  @return the amount of movement speed of the unit
     */
    float computeMovementSpeed();
    
    /**
     *  Computes the armore of the unit
     *  @return the amount of armor of the unit
     */
    int computeArmor();
    
    /**
     *  Computes the precision of the unit
     *  @return the amount of precision of the unit
     */
    int computePrecision();
    
    /**
     *  Computes the mana regen of the unit
     *  @return the amount of mana regen of the unit
     */
    int computeManaRegen();
    
    /**
     *  Computes the dodge of the unit
     *  @return the amount of dodge of the unit
     */
    int computeDodge();
    
    /**
     *  Computes the critical chance of the unit
     *  @return the amount of critical chance of the unit
     */
    int computeCriticalChance();
    public :
    // ----- Member(s)
    // ----- Function(s)
    /**
     *  Default constructor with no parameters
     */
    Unit();
    
    /**
     *  Constructor with one parameter for each caracteristic
     *  @param strength
     *  @param stamina
     *  @param will
     *  @param intelligence
     *  @param luck
     *  @param dexterity
     */
    Unit(unsigned short strength, unsigned short stamina, unsigned short will, unsigned short intelligence, unsigned short luck, unsigned short dexterity);
};

#endif /* defined(example__h) */
