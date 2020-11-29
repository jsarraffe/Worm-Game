//
// Created by Jacques Sarraffe on 11/25/20.
//

#ifndef SCREENEXAMPLE_CELL_H
#define SCREENEXAMPLE_CELL_H

class Cell{
public:
   Cell(int rowValue, int colValue) : _rowValue(rowValue), _colValue(colValue) {}

   void setRow(int rowVal) { _rowValue = rowVal; } // set the row value

   void setCol(int colValue) { _colValue = colValue; }

   int getRow() { return _rowValue; }

   int getCol() { return _colValue; } // get the row value

   ~Cell(){};

private:
   int _rowValue, _colValue;
   bool isFree;
};
#endif //SCREENEXAMPLE_CELL_H
