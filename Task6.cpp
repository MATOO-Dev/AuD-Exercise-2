#include <iostream>
#include <stack>

namespace Task6 
{

    void TowersOfHanoiRecursive(int topPlateSize, std::string originTower, std::string targetTower, std::string storageTower)
    {
        //if no more plates remain on the origin tower, jump up 1 level of recursion
        if(topPlateSize == 0) return;

        //move plate from origin tower to storage tower
        TowersOfHanoiRecursive(topPlateSize-1, originTower, storageTower, targetTower);

        //print movement of plate
        std::cout << "Moved plate of size " << topPlateSize << " from " << originTower << " tower to " << targetTower << " tower"<< std::endl;

        //move plate from storage tower to target tower
        TowersOfHanoiRecursive(topPlateSize-1, storageTower, targetTower, originTower);
    }

    ///questions? answers!

    //a)
    //Wie viele Scheibenbewegungen werden für einen Turm der Höhe 3, 4 oder 5 benötigt?
    //TowersOfHanoi for size 3 = 7 steps
    //TowersOfHanoi for size 4 = 15 steps
    //TowersOfHanoi for size 3 = 31 steps

    //b)
    //Geben Sie eine Formel für die Anzahl der benötigten Scheibenbewegungen für einen Turm der Höhe n an.
    //Steps(n) = (2 * Steps(n - 1)) + 1

    //as code:

    int HanoiStepCalculator(int n)
    {
        if(n == 0) return n;
        return 2 * HanoiStepCalculator(n - 1) + 1;
    }

    //explaination (see function TowersOfHanoiRecursive() for reference):

    //n is the remaining height of the tower
    //first, n-1 plates are moved from the origin tower to the storage tower
    //then, the largest remaining plate is moved from the origin tower to the target tower
    //then, n-1 plates are moved from the storage tower to the target tower

    //the tower of n-1 plates is moved twice, so multiply this by 2
    //then add 1 to compensate for the bottom plate which is not part of the n-1 stack

    //steps to move n-1 can be calculated by calling recursively
    //eventually, n == 0 is reached, so 0 is returned (empty tower)
    //the previous function calls will multipy by 2 then add one, so n = 1, 3, 7, 15, 31, etc.

    //in other words:
    //the lower most plate in the 'moving' stack is moved once
    //the next plate must be moved thrice, and so on
    //the higher up the plate is, there more it has to be moved back-and-forth to get to the bottom plates
}