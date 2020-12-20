//
// Created by Jacques Sarraffe on 11/24/20.
//
#include "Screen.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "Cell.h"

Screen::Screen(int numRows, int numColumns) : numRows(numRows), numColumns(numColumns)
{
    //populates the screen, and initilizes the freePool.
    lastIndex = (numRows - 2) * (numColumns - 2);
    int cellNum = 0;
    for (int i = 0; i < numRows + 1; i++) {
        std::vector<int> row;
        for (int j = 0; j < numColumns; j++) {
            if (i == 0) {
                mvaddch(i, j, ' ');
                break;
            }
            if (j == 0 || i == 1 || i == numRows || j == numColumns - 1) {
                row.push_back(-1);
                mvaddch(i, j, '*');
            }
            else {
                freePool.push_back(new Cell(i, j));
                row.push_back(cellNum);
                mvaddch(i, j, ' ');
                cellNum++;
            }
        }
        screen.push_back(row);
    }
}
void Screen::makeFree(Cell* cell)
{
    if (isFree(cell->getRow(), cell->getCol())) {
        return;
    }
    else {
        screen.at(cell->getRow()).at(cell->getCol()) = lastIndex;
        freePool.at(lastIndex) = cell;
        lastIndex++;
    }
}
void Screen::makeOccupied(Cell* cell)

{
    int fpIndex = screen.at(cell->getRow()).at(cell->getCol());

    if (!isFree(cell->getRow(), cell->getCol())) {
        return;
    }
    else {

        screen.at(cell->getRow()).at(cell->getCol()) = -1;
        auto cellToMove = freePool.at(lastIndex - 1);
        freePool.at(fpIndex) = cellToMove;
        
        freePool.at(lastIndex - 1) = NULL;
        screen.at(cellToMove->getRow()).at(cellToMove->getCol()) = fpIndex;

        lastIndex--;
    }
}
Cell* Screen::genRandomCell()
{
    int cellNum = rand() % (lastIndex);
    return freePool.at(cellNum);
}

bool Screen::isFree(int row, int column)
{
    if (screen.at(row).at(column) == -1) {
        return false;
    }
    return true;
}
void Screen::displayScore(int munchSize)
{
    //updates and displayes game score.
    gameScore += munchSize;
    std::string s = std::to_string(gameScore);
    move(0, 3);
    addstr("Worm");

    move(0, numColumns - 12);

    addstr("Score  ");
    move(0, numColumns - 6);
    addstr(s.c_str());
}
Screen::~Screen()
{
     for(int i = 0; i < lastIndex; i++){

         if(freePool.at(i) != NULL)
         delete freePool.at(i);
    }
}
void Screen::printFreePool()
{
    //USED FOR DEBUGGING
    auto row = 0;
    auto col = 0;

    for (int i = 0; i < freePool.size(); i++) {
        row = freePool.at(i)->getRow();
        col = freePool.at(i)->getCol();

        if (screen.at(row).at(col) == -1 && i < lastIndex) {
            return;
        }

        std::string lastIndexString = std::to_string(lastIndex);
        std::string rowNum = std::to_string(row);
        std::string colNum = std::to_string(col);
        std::string indexNum = std::to_string(i);

        mvaddstr(4, 16, lastIndexString.c_str());
        mvaddstr(i, 20, indexNum.c_str());
        mvaddstr(i, 24, rowNum.c_str());
        mvaddstr(i, 26, colNum.c_str());
    }
}
