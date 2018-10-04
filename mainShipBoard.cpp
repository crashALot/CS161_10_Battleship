#include "BBoard.hpp"
#include "Ship.hpp"
#include <iostream>

int main()
{
    BBoard newGame;
    Ship  Destroyer("my destroyer",5), Submarine("my submarine",3), Boaty("Boaty McBoatface",4);
    //std::cout << Destroyer.getLength() << std::endl;
    //std::cout << Destroyer.getName() << std::endl;
    newGame.placeShip(&Destroyer,3,3,'C');
    newGame.placeShip(&Submarine,5,6,'R');
    newGame.placeShip(&Boaty,8,6,'R');
    
    newGame.attack(3,3);
    newGame.attack(4,3);
    newGame.attack(5,3);
    newGame.attack(6,3);
    newGame.attack(7,3);

 
    newGame.attack(5,6);
    newGame.attack(5,7);
    newGame.attack(5,8);

    
    newGame.attack(8,6);
    newGame.attack(8,7); 
    newGame.attack(8,8); 
    newGame.attack(8,9);     
    
    //newGame.print();
    std::cout << newGame.getNumShipsRemaining() << std::endl;
    std::cout << newGame.allShipsSunk() << std::endl;
    return 0;
}