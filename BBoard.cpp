#include "Ship.hpp"
#include "BBoard.hpp"
#include <iostream>


/********************************************************************* 
** Description: BBoard::BBoard()
*               Initializes each element of the boolArray to false 
*               and each element of the Ship-pointer array to NULL.
*               unsunkShips initialized to 0.
*********************************************************************/
BBoard::BBoard()
{
    for (int row=0; row<10; row++)
    {
        for (int col=0; col<10; col++)
            boolArray[row][col]=false;
    }
    
    for (int row=0; row<10; row++)
    {
        for (int col=0; col<10; col++)
            shipPointers[row][col]=NULL;
    }
    unsunkShips=0;
    //std::cout << "Unsunk ships is now: " << unsunkShips << std::endl;
}

/********************************************************************* 
** Description: get Functions
*               Returns user requested information from class 
*               variables or Battleship game boards.
*********************************************************************/
bool BBoard::getAttacksArrayElement(int boolRowIn, int boolColIn)
{
    return boolArray[boolRowIn][boolColIn];
}

Ship* BBoard::getShipsArrayElement(int ptrRowIn, int ptrColIn)
{
    return shipPointers[ptrRowIn][ptrColIn];
}

int BBoard::getNumShipsRemaining()
{
    return unsunkShips;
}

/********************************************************************* 
** Description: bool BBoard::placeShip(Ship &shipIn, int rowIn, int colIn, char directionIn)
*               Takes as parameters: the address of a Ship object, the
*               row and column of the square of the Ship that is closest
*               to (0, 0), and the Ship's orientation (either 'R' if its 
*               squares occupy the same row or 'C' if its squares occupy
*               the same column). This method will set the elements of
*               the array that the Ship occupies to hold the address 
*               of the Ship. If a Ship would not fit entirely on the
*               Board, or if it would overlap any previously placed 
*               ships, the ship should not be added to the Board and 
*               the method should return false. Otherwise, the ship 
*               should be placed on the Board, the number of un-sunk
*               ships should be incremented, and the method should 
*               return true.
*********************************************************************/
bool BBoard::placeShip(Ship *shipPtr, int ptrRowIn, int ptrColIn, char directionIn)
{
    //Ship *shipPtr=&shipIn;
    int shipLength=shipPtr->getLength();
    
    if (directionIn=='C' && ptrRowIn+shipLength<=10) // If ship fills column and doesn't extend beyond border...
    {
        for (int i=0; i<shipLength; i++) // Check if ship will overlap any battleships
        {
            if (shipPointers[ptrRowIn+i][ptrColIn]!=NULL) // If an element on the board is not null, a ship is there
            {
                //std::cout << "I can't do that in row " << ptrRowIn+i << " Dave" << std::endl;
                //std::cout << "Unsunk ships is now: " << unsunkShips << std::endl;
                return false; // If it's not null, exit method
            }
        }
        for (int j=0; j<shipLength; j++) // Fill the empty elements with a ship object address
            shipPointers[ptrRowIn+j][ptrColIn]=shipPtr;
        unsunkShips++; // Incrememnt number of ships on board
        //std::cout << "Unsunk ships is now: " << unsunkShips << std::endl;
    }
    else if (directionIn=='C' && ptrRowIn+shipLength>10)
    {
        //std::cout << "Play inside the lines! You're at row " << ptrRowIn+shipLength << std::endl;
        return false;
    }

    if (directionIn=='R' && ptrColIn+shipLength<=10)
    {
        for (int i=0; i<shipLength; i++)
        {
            if (shipPointers[ptrRowIn][ptrColIn+i]!=NULL)
            {
                //std::cout << "I can't do thatin column " << ptrColIn+i <<" Dave" << std::endl;
                //std::cout << "Unsunk ships is now: " << unsunkShips << std::endl;
                return false;
            }
        }
        for (int j=0; j<shipLength; j++)
            shipPointers[ptrRowIn][ptrColIn+j]=shipPtr;
        unsunkShips++;
        //std::cout << "Unsunk ships is now: " << unsunkShips << std::endl;
    }
    else if (directionIn=='R' && ptrColIn+shipLength>10)
    {
        //std::cout << "Play inside the lines! You're at column: " << ptrColIn+shipLength << std::endl;
        return false;
    }
    
    return true;
}

/********************************************************************* 
** Description: bool BBoard::attack(int, int)
*               Takes as parameters the row and column of the attack.
*               If the attack hits a Ship the attack is recorded in the 
*               bool array. If that square has not been hit before, the
*               Ship's takeHit method is called. If all of a Ship's 
*               squares have been hit, a message is printed to consol
*               and the number of ships that remain un-sunk is 
*               decremented. Return true (even if that square was 
*               previously hit).If the attack is not a hit, the attack
                is updated in the bool array and function returns false.
*********************************************************************/
bool BBoard::attack(int rowHitIn, int colHitIn)
{
    bool impact=(shipPointers[rowHitIn][colHitIn]!=NULL);
    Ship *shipPtr = getShipsArrayElement(rowHitIn,colHitIn);
    if (impact && boolArray[rowHitIn][colHitIn]==false) // If attack hits ship address and bool array element is also false (no hit yet)
    {
        boolArray[rowHitIn][colHitIn]=true;
        if (shipPtr->getDamage()<shipPtr->getLength()-1)
        {
            shipPtr->takeHit(1);
            //std::cout << shipPtr->getName() << " is now at " << shipPtr->getDamage() << " damage" << std::endl;
        }
        else 
        {
            shipPtr->takeHit(1);
            std::cout << "They sank " << shipPtr->getName() << "!" << std::endl;
            unsunkShips--;
        }
        return true;
    }
    else
    {
        boolArray[rowHitIn][colHitIn]=true;
        return false;
    }
}

/********************************************************************* 
** Description: bool BBoard::allShipsSunk()
*               Returns true if all ships on the Board have been sunk, 
*               but returns false otherwise
*********************************************************************/
bool BBoard::allShipsSunk()
{
    if (unsunkShips)
        return false;
    else
        return true;
}

/********************************************************************* 
** Description: void BBoard::print()
*               Outputs to consol battleship board and associated
*               ships in play.
*********************************************************************/
/*
void BBoard::print()
{
    // Bool printout
    std::cout << " " << " 0 1 2 3 4 5 6 7 8 9" << std::endl;
    for (int row=0; row<10; row++)
    {
        std::cout << row << " ";
        for (int col=0; col<10; col++)
        {
            std::cout << boolArray[row][col] <<" ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    // Ship location printout
    std::cout << " " << " 0 1 2 3 4 5 6 7 8 9" << std::endl;
    for (int row=0; row<10; row++)
    {
        std::cout << row << " ";
        for (int col=0; col<10; col++)
        {
            std::cout << shipPointers[row][col] <<" ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
*/

/********************************************************************* 
** Description: BBoard::~BBoard()
*               Destructor function for BBoard class.
*********************************************************************/
BBoard::~BBoard()
{
}
