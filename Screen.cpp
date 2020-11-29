//
// Created by Jacques Sarraffe on 11/24/20.
//
#include "Screen.h"
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <iostream>
#include "Cell.h"

Screen::Screen(int numRows, int numColumns) : numRows(numRows), numColumns(numColumns)
{
    lastIndex = (numRows - 2) * (numColumns - 2) - 1;
    int cellNum = 0;
    for (int i = 0; i < numRows + 1; i++)
    {

        std::vector<int> row;
        for (int j = 0; j < numColumns; j++)
        {

            if (i == 0)
            {
                mvaddch(i, j, ' ');
                break;
            }

            if (j == 0 || i == 1 || i == numRows || j == numColumns - 1)
            {
                row.push_back(-1);
                mvaddch(i, j, '*');
            }
            else
            {
                freePool.push_back(new Cell(i, j));
                row.push_back(cellNum);
                mvaddch(i, j, ' ');
                cellNum++;
            }
        }
        screen.push_back(row);
    }
}
void Screen::makeFree(Cell *cell)
{
    if (isFree(cell->getRow(), cell->getCol()))
    {
        std::cout << "Already is a free cell " << std::endl;
    }
    else
    {
        screen.at(cell->getRow()).at(cell->getCol()) = lastIndex;
        freePool.at(lastIndex) = cell;
        lastIndex++;
    }
}
void Screen::makeOccupied(Cell *cell)

{
    int fpIndex = screen.at(cell->getRow()).at(cell->getCol());

    if (!isFree(cell->getRow(), cell->getCol()))
    {
        std::cout << "Already is occupied" << std::endl;
    }
    else
    {
        screen.at(cell->getRow()).at(cell->getCol()) = -1;
        freePool.at(fpIndex) = freePool.at(lastIndex - 1);
        lastIndex--;
    }
}
Cell *Screen::genRandomCell()
{

    int cellNum = rand() % lastIndex;
    return freePool.at(cellNum);
}
bool Screen::isFree(int row, int column)
{
    if (screen.at(row).at(column) == -1)
    {
        return false;
    }
    return true;
}

void Screen::displayScore()
{

    move(0, 3);
    addstr("Worm");

    move(0, numColumns - 12);
    addstr("Score  0");
}
