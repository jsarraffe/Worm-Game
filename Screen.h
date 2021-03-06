//
// Created by Jacques Sarraffe on 11/24/20.
//

#ifndef SCREENEXAMPLE_SCREEN_H
#define SCREENEXAMPLE_SCREEN_H

#include <vector>
#include <curses.h>
#include "Cell.h"


class Screen
{
public:
    Screen(int numRows, int numColumns);
    
    void makeFree(Cell *cell);

    void makeOccupied(Cell *cell);

    bool isFree(int row, int column);

    Cell *genRandomCell();

    int getGameScore(){return gameScore;}

    void displayScore(int munchSize);

    //function was used for debugging
    int getLastIndex(){return lastIndex;}

    ~Screen();
     
     void printFreePool();

private:
    
    std::vector<std::vector<int> > screen;
    std::vector<Cell *> freePool;
   

    int lastIndex = 0;
    int numRows, numColumns;
    int gameScore = 0;
};
#endif //SCREENEXAMPLE_SCREEN_H
