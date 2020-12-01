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

    ~Screen();

private:
    int numRows, numColumns;
    std::vector<std::vector<int>> screen;
    std::vector<Cell *> freePool;
    int lastIndex = 0;
    int gameScore = 0;
};
#endif //SCREENEXAMPLE_SCREEN_H
