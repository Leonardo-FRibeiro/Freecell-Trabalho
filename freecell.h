// Alunos:
// Leonardo Franzin Ribeiro - 2108237
// Luís Felipe Rotondo Kobelnik - 2125543
// Augusto Coimbra de Oliveira - 2136390

#ifndef FREECELL_H
#define FREECELL_H
#include <iostream>
#include "carta.h"
using namespace std;

const int MaxFreeCell = 1;
class freeCell
{
public:
    freeCell(string naipe, freeCell *pFC);
    ~freeCell();
    bool Empty();
    bool Full();
    void PushFreeCell(int x, Carta c);
    void RemoveFreeCell(int &x, Carta c);
    freeCell *nextfreeCell;
    void display();

private:
    int count;
    Carta current;
    int EntryFreeCell[MaxFreeCell];
    string naipe;
};
#endif