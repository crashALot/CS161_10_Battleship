#include "Ship.hpp"
#include <iostream>
#include <string>

Ship::Ship(std::string shipNameIn, int shipLengthIn)
{
    name=shipNameIn;
    length=shipLengthIn;
    damage=0;
}

std::string Ship::getName()
{
    return name;
}

int Ship::getLength()
{
    return length;
}

int Ship::getDamage()
{
    return damage;
}

int Ship::takeHit(bool hitDamage)
{
    damage+=hitDamage;
    return damage;
}
    
Ship::~Ship()
{
}
