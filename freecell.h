// Alunos:
// Leonardo Franzin Ribeiro - 2108237
// Luís Felipe Rotondo Kobelnik - 2125543
// Augusto Coimbra de Oliveira - 2136390

#ifndef FREECELL_H
#define FREECELL_H
#include <iostream>
#include "carta.h"
using namespace std;

// Um elemento de freecell segura uma única carta.
class freeCell
{
public:
    freeCell();
    freeCell(freeCell *pFC);
    ~freeCell();
    bool Empty();
    bool Full();
    bool PushFreeCell(Carta c);
    bool RemoveFreeCell();
    Carta GetCurrent();
    void display();
    freeCell *nextfreeCell;
private:
    Carta current;
};
#endif