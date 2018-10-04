#ifndef SHIP_HPP
#define SHIP_HPP
#include <string>

class Ship
{
private:
    
    std::string name;
    int length;
    int damage;
    
public:
    
    Ship(std::string, int);
    std::string getName();
    int getLength();
    int getDamage();
    int takeHit(bool);
    
    ~Ship();
    
};

#endif