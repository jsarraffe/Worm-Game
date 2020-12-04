//
// Created by Jacques Sarraffe on 11/25/20.
//

#include <vector>
#include <iostream>
#include <queue>
#include "Cell.h"
#include <memory>

class Worm
{

public:
    //Constructor
    //Remeber to initliaze the size to (row -1 * column -1)
    Worm(int size) :_front(-1), _rear(-1){worm.resize(size);}

    void printWorm();
    Cell *getFront();
    Cell *getRear();
    void Enqueue(Cell *cell);
    void Dequeue();
    ~Worm(){};

private:
    int _front;
    int _rear;
    std::vector<Cell *> worm;
};