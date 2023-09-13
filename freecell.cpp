#include "freecell.h"
#include <iostream>
using namespace std;

    const int MAXVALOR = 1;
    const int numFreeCells = 4;

    freeCell::freeCell()
    {} 

    bool freeCell::Empty(int count, freeCell& cell)
    {
        if (count == 0)
        {
            return true;
            cout << "FreeCell vazia, não há como retirar uma carta" << endl;
        }
        else
        {
            return false;
        }
    }

    bool freeCell::Full(int count)
    {
        if(count == MAXVALOR) 
        {
            return true;
            cout << "FreeCell cheia, favor colocar em outro lugar" << endl;
        } 
        else 
        {
            return false;
        }
    }

    // Pré-condição: A FreeCell ter sido criada e estar vazia
    // Pós-Condição: Inserir Carta c na FreeCell
    void freeCell::PushFreeCell(int count, Carta c)
    {
        if(Full)
        {
            cout << "FreeCell cheia, não é possível inserir uma carta em uma FreeCell já ocupada" << endl;
        }
        else
        {
            c.GetNaipe() == naipe && c.GetValor() == 1 + current.GetValor() || current.GetValor() == 14; 
            current = c;
            count++;
        }
    }

    void freeCell::RemoveFreeCell(int count, Carta c)
    {
        if(Empty) 
        {
            cout << "FreeCell vazia, não há presença de cartas" << endl;
        } 
        else 
        {       

            count--;
        }
    }

    void freeCell::display()
    {
        
    }
