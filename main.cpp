//
// Created by Jacques Sarraffe on 11/25/20.
//

#include <iostream>
#include <string>
#include <curses.h>
#include "getChar.hpp"
#include <stdlib.h>
#include "Worm.h"
#include "Cell.h"
#include "Screen.h"
#include "time.h"

void startup(void);
void terminate(void);

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cout << "ERROR: Enter arguments. numRows numColumns" << std::endl;
        exit(1);
    }
    // change the seed for the time
    srand(time(NULL));

    int numRows = atoi(argv[1]);
    int numCols = atoi(argv[2]);


    if(!(numRows >= 9 && numRows <= 25)){
        std::cout<<"ERROR: Enter a valid row size "<<std::endl;
        exit(1);
        
    }
    if(!(numCols >= 9 && numCols <= 80)){
        std::cout<<"ERROR: Enter a valid column size "<<std::endl;
        exit(1);
   
    }
    startup();

    refresh();
    bool isAlive = true;

    int currRow = numRows / 2;
    int currCol = numCols / 2;
    Screen* screen = new Screen(numRows, numCols);

    Worm* worm = new Worm((numRows - 2) * (numCols - 2) - 1);

    auto headCell = new Cell(currRow, currCol);
    int currGameScore = 0;
    screen->displayScore(currGameScore);

    int segmentsToAdd = 0;

    worm->Enqueue(headCell);
    screen->makeOccupied(headCell);

    move(currRow, currCol);
    addch('@');
    //gen random mumchie
    int ranInt = (rand() % 9) + 1;
    int ranNum = '0' + ranInt;
    auto munchie = screen->genRandomCell();
    move(munchie->getRow(), munchie->getCol());
    addch(ranNum);

    refresh();
    while (isAlive) {
        switch (get_char()) {
        case 'j':
            currRow++;
            break;
        case 'l':
            currCol++;
            break;
        case 'h':
            currCol--;
            break;
        case 'k':
            currRow--;
            break;
        default:
            continue;
        }
        if (screen->isFree(currRow, currCol)) {

            auto oldHead = worm->getRear();

            headCell = new Cell(currRow, currCol);
            move(currRow, currCol);
            worm->Enqueue(headCell);
            screen->makeOccupied(headCell);
            addch('@');
            auto oldRear = worm->getFront();
            if (oldRear != headCell) {
                //if it's not just the @. When the head moves, add an o.
                mvaddch(oldHead->getRow(), oldHead->getCol(), 'o');
            }
            if (segmentsToAdd > 0) {
                segmentsToAdd--;
            }
            else {
                //remove the previous tail. if it's not growing 
                worm->Dequeue();
                screen->makeFree(oldRear);
                move(oldRear->getRow(), oldRear->getCol());
                addch(' ');
            }
            if ((munchie->getRow() == currRow && munchie->getCol() == currCol)) {
                //generate munchie
                segmentsToAdd += ranInt;
                screen->displayScore(ranInt);
                ranInt = (rand() % 9) + 1;
                ranNum = '0' + ranInt;
                munchie = screen->genRandomCell();
                move(munchie->getRow(), munchie->getCol());
                addch(ranNum);
            }
        }
        else {
            isAlive = false;
        }

        refresh();
    }
    terminate();

    std::cout << "The worm died since it ran into something!" << std::endl;
    std::cout << "Your final score: " << screen->getGameScore() << std::endl;
    delete screen;
}

void startup(void)
{
    initscr(); /* activate the curses */
    curs_set(0); /* do not display the cursor */
    clear(); /* clear the screen that curses provides */
    noecho(); /* prevent the input chars to be echoed to the screen */
    cbreak(); /* change the stty so that characters are delivered to the
		    program as they are typed--no need to hit the return key!*/
}
void terminate(void)
{
    mvcur(0, COLS - 1, LINES - 1, 0);
    clear();
    refresh();
    endwin();
}