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

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Error you need the fucking arguments dumbass" << std::endl;
        exit(1);
    }
    int c;
    // change the seed for the time
    srand(time(NULL));

    int numRows = atoi(argv[1]);
    int numCols = atoi(argv[2]);
    startup();

    refresh();

    bool isAlive = true;

    int currRow = numRows / 2;
    int currCol = numCols / 2;
    Screen *screen = new Screen(numRows, numCols);
    screen->displayScore(0);

    Worm *worm = new Worm((numRows - 2) * (numCols - 2) - 1);

    auto headCell = new Cell(currRow, currCol);

    auto headCell1 = new Cell(currRow, currCol - 1);
    auto headCell2 = new Cell(currRow, currCol - 2);
    auto headCell3 = new Cell(currRow, currCol - 3);
    auto headCell4 = new Cell(currRow, currCol - 4);
    auto headCell5 = new Cell(currRow, currCol - 5);

    int segmentsToAdd = 0;
    

    worm->Enqueue(headCell);
    //worm->Enqueue(headCell1);
    // worm->Enqueue(headCell2);
    // worm->Enqueue(headCell3);
    // worm->Enqueue(headCell4);
    // worm->Enqueue(headCell5);

    screen->makeOccupied(headCell);
    //screen->makeOccupied(headCell1);
    // screen->makeOccupied(headCell2);
    // screen->makeOccupied(headCell3);
    // screen->makeOccupied(headCell4);
    // screen->makeOccupied(headCell5);

    move(currRow, currCol);
    addch('@');
    // move(currRow, currCol - 1);
    // addch('o');
    // move(currRow, currCol - 2);
    // addch('o');
    // move(currRow, currCol - 3);
    // addch('o');
    // move(currRow, currCol - 4);
    // addch('o');
    // move(currRow, currCol - 5);
    // addch('o');

   

        int ranInt = rand() % 10;
        int ranNum = '0' + ranInt;

        auto munchie = screen->genRandomCell();
        move(munchie->getRow(), munchie->getCol());
        screen->makeOccupied(munchie);
        addch(ranNum);



 refresh();
    while (isAlive)
    {    
        char nextC = inch();
        switch (get_char())
        {

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
        if (!screen->isFree(currRow, currCol))
        {
           if((munchie->getRow() != currRow && munchie->getCol() != currCol)){
               isAlive = false;
           } else{

               screen->displayScore(ranInt);


                auto oldHead = worm->getRear();


                headCell = new Cell(currRow, currCol);
                move(currRow, currCol);
                worm->Enqueue(headCell);
                screen->makeOccupied(headCell);
                addch('@');
                auto oldRear = worm->getFront();

            if (oldRear != headCell)
            {
                //only move it its not just the @ sign
                mvaddch(oldHead->getRow(), oldHead->getCol(), 'o');
            }


            if (segmentsToAdd > 0)
            {   
                segmentsToAdd--;
            }
            else
            {
                worm->Dequeue();
                screen->makeFree(oldRear);
                move(oldRear->getRow(), oldRear->getCol());
                addch(' ');
            }
            segmentsToAdd += ranInt;
            

            screen->makeFree(munchie);
                ranInt = rand() % 10;
                ranNum = '0' + ranInt;
                munchie = screen->genRandomCell();
                move(munchie->getRow(), munchie->getCol());
                screen->makeOccupied(munchie);
                addch(ranNum);
           }  
        }
        else
        {
            auto oldHead = worm->getRear();
            headCell = new Cell(currRow, currCol);
            move(currRow, currCol);
            worm->Enqueue(headCell);
            screen->makeOccupied(headCell);
            addch('@');

            auto oldRear = worm->getFront();

            if (oldRear != headCell)
            {
                //only move it its not just the @ sign
                mvaddch(oldHead->getRow(), oldHead->getCol(), 'o');
            }
            if (segmentsToAdd > 0)
            {   
                segmentsToAdd--;
            }
            else
            {
                worm->Dequeue();
                screen->makeFree(oldRear);
                move(oldRear->getRow(), oldRear->getCol());
                addch(' ');
            }
        }
        
        refresh();
    }
    terminate();
}

void startup(void)
{
    initscr();   /* activate the curses */
    curs_set(0); /* do not display the cursor */
    clear();     /* clear the screen that curses provides */
    noecho();    /* prevent the input chars to be echoed to the screen */
    cbreak();    /* change the stty so that characters are delivered to the
		    program as they are typed--no need to hit the return key!*/
}
void terminate(void)
{
    mvcur(0, COLS - 1, LINES - 1, 0);
    clear();
    refresh();
    endwin();
}


