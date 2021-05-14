//
// Created by Jacques Sarraffe on 11/25/20.
//

#include "Worm.h"
#include <vector>
#include <iostream>
#include <queue>
#include "Cell.h"

void Worm::printWorm()
{
    //for Debugging my worm
    int i = _front;
    std::cout << "Circular Queue \n";
    if(_rear == -1){
        exit(1);
        return;
    }

    std::cout << "Space " << i << ": " << worm.at(i)->getRow() <<" ,"<< worm.at(i)->getCol()<<std::endl;
    
    while (i != _rear){
        i = (i + 1) % worm.size();
        std::cout << "Section " << i << ": " << worm.at(i)->getRow() <<","<< worm.at(i)->getCol()<<std::endl;
        if (i == _front)
        {
            std::cout << "front ";
        }
        if (i == _rear)
        {
            std::cout << " rear " << std::endl;
        }
    } 
}
void Worm::Enqueue(Cell *cell)
{
    //adds to the rear of the queue

    if ((_rear + 1) % worm.size() == _front)
    {
        return;
    }
    else
    {
        _rear = (_rear + 1) % worm.size();
        worm.at(_rear) = cell;
        //initliaze front
        if (_front == -1)
        {
            _front = 0;
        }
    }
}
void Worm::Dequeue()
{
    //removes from the front of the queue
    if (_front == -1)
    {
        std::cout<<"Worm Empy"<<std::endl;
    }
    else
    {
        if (_front == _rear)
        {
            _front = _rear = -1;
            //empty
        }
        else
        {
            _front = (_front + 1) % worm.size();
        }
    }
}

Cell *Worm::getFront()
{
    if (_rear == -1)
    {
        std::cout<<"Worm empty"<<std::endl;
    }
    else
    {
        return worm.at(_front);
    }
}
Cell *Worm::getRear()
{
    if (_rear == -1)
    {   
        std::cout<<"Worm empty"<<std::endl;
    }
    else
    {
        return worm.at(_rear);
    }
}

bool Worm::isFull(){
    if(_front == - 1 && _rear == -1){
        exit(1);
    }

}
