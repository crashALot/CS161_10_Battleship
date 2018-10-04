#include "Ship.hpp"
#ifndef BBOARD_HPP
#define BBOARD_HPP

class BBoard
{
private:

    bool boolArray[10][10];
    Ship* shipPointers[10][10];
    int unsunkShips;

public:

    BBoard();
    bool getAttacksArrayElement(int, int);
    Ship* getShipsArrayElement(int, int);
    int getNumShipsRemaining();
    bool placeShip(Ship *, int, int, char);
    bool attack(int, int);
    bool allShipsSunk();
    //void print();
    
    ~BBoard();
    
};

#endif