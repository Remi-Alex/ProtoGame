//
//  unit.cpp
//  V1 - 23/01/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.
//

#include "unit.h"
#include <stdlib.h>
#include <time.h>

Unit::Unit() : posX(0), posY(0), strength(1), stamina(1), will(1), intelligence(1), luck(1), dexterity(1), lifeSteal(0), penetration(0), lifeRegen(0) {
    this->computeStats();
}

Unit::Unit(unsigned short strength, unsigned short stamina, unsigned short will, unsigned short intelligence, 
    unsigned short luck, unsigned short dexterity) 
: posX(0), posY(0), strength(strength), stamina(stamina), will(will), intelligence(intelligence), luck(luck), dexterity(dexterity), lifeSteal(0), penetration(0), lifeRegen(0) {
    this->computeStats();
}

void Unit::computeStats() {
    this->maxHP = this->computeHP();
    this->HP = this->maxHP;
    this->maxMana = this->computeMana();
    this->mana = this->maxMana;
    this->physicalPower = this->computePhysicalPower();
    this->magicalPower = this->computeMagicalPower();
    this->attackSpeed = this->computeAttackSpeed();
    this->movementSpeed = this->computeMovementSpeed();
    this->armor = this->computeArmor();
    this->precision = this->computePrecision();
    this->manaRegen = this->computeManaRegen();
    this->dodge = this->computeDodge();
    this->criticalChance = this->computeCriticalChance();
}

int Unit::computeHP() {
    return 100 + this->stamina * 10;
}

int Unit::computeMana() {
    return 100 + this->intelligence * 10;
}

int Unit::computePhysicalPower() {
    return this->strength * 2 + 10;
}

int Unit::computeMagicalPower() {
    return this->intelligence * 2 + 10;
}

float Unit::computeAttackSpeed() {
    return this->dexterity / 5;
}

float Unit::computeMovementSpeed() {
    return 6 / this->dexterity;
}

int Unit::computeArmor() {
    return this->strength * 3;
}

int Unit::computePrecision() {
    return (10 + (this->dexterity + 0.5 * this->luck)) * 4;
}

int Unit::computeManaRegen() {
    return this->will;
}

int Unit::computeDodge() {
    return 2 * this->dexterity;
}

int Unit::computeCriticalChance() {
    return this->luck;
}

void Unit::attack(Unit* ennemi) {
    // TODO : Make different attacks (physical and magical)
    int damages = 0, r;
    
    // initialize random seed
    srand(time(NULL));
    
    // generate rand number between 0 and 100
    r = rand() % 100;
    if(this->precision - ennemi->dodge < r) {
        damages = this->physicalPower - (100 * this->penetration) * ennemi->armor;
    }
    
    // deal damages
    ennemi->HP -= damages;
    if(ennemi->HP < 0) ennemi->HP = 0;
}
