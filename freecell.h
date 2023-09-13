#ifndef FREECELL_H
#define FREECELL_H
#include <iostream>
#include "carta.h"
using namespace std;

class freeCell
{
    public:
    freeCell(string Free_Cell, freeCell* pFC);
    bool Empty(int count, freeCell& cell);
    bool Full(int count);
    void PushFreeCell(int count, Carta c);
    void RemoveFreeCell(int count, Carta c);
    freeCell* nextfreeCell;
    void display();

    private:
    int count = 0;
    Carta current;
    string Free_Cell;
    
};
#endif