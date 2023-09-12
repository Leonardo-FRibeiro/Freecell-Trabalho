#ifndef FREECELL_H
#define FREECELL_H
#include <iostream>
#include "carta.h"
using namespace std;

class freeCell
{
    public:
    freeCell();
    bool Empty(int count, const freeCell& cell);
    bool Full(int count);
    void PushFreeCell(int count, int i);
    void RemoveFreeCell(int count, int i);

    private:
    int count = 0;
    Carta Entry;
    
};
#endif