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
    

    Worm *worm = new Worm((numRows - 2) * (numCols - 2) - 1);

    auto headCell = new Cell(currRow, currCol);
    int currGameScore = 0;
    screen->displayScore(currGameScore);

    
    int segmentsToAdd = 0;
    

    worm->Enqueue(headCell);
    screen->makeOccupied(headCell);

    move(currRow, currCol);
    addch('@');

        int ranInt = (rand() % 9) + 1;
        int ranNum = '0' + ranInt;

        auto munchie = screen->genRandomCell();
        move(munchie->getRow(), munchie->getCol());
        
        addch(ranNum);
        
        
 refresh();
    while (isAlive)
    {    
        std::string r = std::to_string(currRow);
        std::string c = std::to_string(currCol);
        std::string munchieRow = std::to_string(munchie->getRow());
        std::string munchieCol = std::to_string(munchie->getCol());

        screen->printFreePool();
        refresh();
        mvaddstr(6, 16,munchieRow.c_str());
        refresh();
        mvaddstr(7, 16,munchieCol.c_str());
        refresh();
        refresh();
        mvaddstr(2, 16,r.c_str());
        refresh();
        mvaddstr(3, 16,c.c_str());
        refresh();
        refresh();
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
        if (screen->isFree(currRow, currCol))
        {
                
                auto oldHead = worm->getRear();


                headCell = new Cell(currRow, currCol);
                move(currRow, currCol);
                worm->Enqueue(headCell);
                screen->makeOccupied(headCell);
                addch('@');
                auto oldRear = worm->getFront();
                screen->printFreePool();

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
            

              if((munchie->getRow() == currRow && munchie->getCol() == currCol)){
                  segmentsToAdd += ranInt;
                  screen->displayScore(ranInt);
                ranInt = (rand() % 9) + 1;
                ranNum = '0' + ranInt;
                munchie = screen->genRandomCell();
                move(munchie->getRow(), munchie->getCol());
                addch(ranNum);

                
           }  
        }
        else
        {
          isAlive = false;
        }
        
        refresh();
    }
    
    terminate();

    std::cout<<"The worm died since it ran into something!"<<std::endl;
    std::cout<<"Your final score: "<<screen->getGameScore()<<std::endl;
    delete screen;

     
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