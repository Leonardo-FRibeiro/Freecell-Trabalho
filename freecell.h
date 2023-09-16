#ifndef FREECELL_H
#define FREECELL_H
#include <iostream>
#include "carta.h"
using namespace std;

const int MaxFreeCell = 1;
class freeCell
{
public:
    freeCell();
    ~freeCell();
    bool Empty();
    bool Full();
    void PushFreeCell(int x);
    void RemoveFreeCell(int &x);
    freeCell *nextfreeCell;
    void display();

private:
    int count;
    int EntryFreeCell[MaxFreeCell];
};
#endif