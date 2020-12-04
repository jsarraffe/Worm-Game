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
    int i = _front;
    std::cout << "Current Circular Queue Status\n";
    std::cout << "==============================\n";
    if(_rear == -1){
        std::cout<<"Worm Empty"<<std::endl;
        return;
    }

    std::cout << "Space " << i << ": " << worm.at(i)->getRow() <<" ,"<< worm.at(i)->getCol()<<std::endl;
    
    while (i != _rear){
        i = (i + 1) % worm.size();
        std::cout << "Space " << i << ": " << worm.at(i)->getRow() <<","<< worm.at(i)->getCol()<<std::endl;
        if (i == _front)
        {
            std::cout << "Head ";
        }
        if (i == _rear)
        {
            std::cout << " TAIL " << std::endl;
        }
    } 
}
void Worm::Enqueue(Cell *cell)
{
    //is the queue FUll?

    if ((_rear + 1) % worm.size() == _front)
    {
        std::cout << "the queue is full" << std::endl;
    }
    else
    {
        _rear = (_rear + 1) % worm.size();
        worm.at(_rear) = cell;
        //initliaze it
        if (_front == -1)
        {
            _front = 0;
        }
    }
}
void Worm::Dequeue()
{
    //nothing else to remove, list is empty
    if (_front == -1)
    {
        std::cout << "The queue is empty " << std::endl;
    }
    else
    {
        if (_front == _rear)
        {
            _front = _rear = -1;
            //set the to false
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
        std::cout << "Queue is empty!" << std::endl;
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
        std::cout << "Queue is empty!" << std::endl;
    }
    else
    {
        return worm.at(_rear);
    }
}
