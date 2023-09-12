#include "freecell.h"
#include "carta.h"
#include "pilha.h"
#include "pilha_saida.h"
#include <iostream>
using namespace std;

    const int MAXVALOR = 1;
    const int numFreeCells = 4;
    int FC[4] = {10,11,12,13};

    freeCell::freeCell()
    {
        int *p = FC;
    } 

    bool Empty(int count, const freeCell& cell)
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

    bool Full(int count)
    {
        if(count == MAXVALOR) 
        {
            return true;
            cout << "FreeCell cheia, favor colocar em outro lugar" << endl;
        } 
        else 
        {
            return false;
            count--;
        }
    }

    void PushFreeCell(int count, int i)
    {
        if(Full)
        {
            cout << "FreeCell cheia, não é possível inserir uma carta em uma FreeCell já ocupada" << endl;
        }
        else
        {
            cout << "Selecione a FreeCell desejada (10,11,12 ou 13)" << endl;
            cin >> i;
            //Falta fazer a carta selecionada ser inserida na FreeCell desejada;
            FC[i]; // não sei como continuar :p;
            count++;
        }
    }

    void RemoveFreeCell(int count, int i)
    {
        if(Empty) 
        {
            cout << "FreeCell vazia, não há presença de cartas" << endl;
        } 
        else 
        {
            // Falta o processo para transferir a carta da FC selecionada para uma pilha novamente
            count--;
        }
    }
