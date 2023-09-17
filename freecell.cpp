// Alunos:
// Leonardo Franzin Ribeiro - 2108237
// Luís Felipe Rotondo Kobelnik - 2125543
// Augusto Coimbra de Oliveira - 2136390

#include "freecell.h"
#include "carta.h"
#include "pilha.h"
#include <iostream>
using namespace std;

int count = 0;
const int MAXVALOR = 1;
const int numFreeCells = 4;

freeCell::freeCell(string n)
{
    current = Carta(14, n);
    naipe = n;
}

// Pré-condição: < nenhuma >
// Pós-Condição: FreeCell é criada
freeCell::freeCell(string n, freeCell *p)
{
    current = Carta(14, n);
    naipe = n;
    nextfreeCell = p;
}

// Pré-condição: FreeCell criada
// Pós-Condição: FreeCell é destruída
freeCell::~freeCell(){};

// Pré-condição: Verifica se a freeCell ja possui uma carta ou não
// Pós-Condição: subtrairá 1 ao contador para que a freeCel fique vazia
bool freeCell::Empty()
{
    return (count == 0);
}

// Pré-condição: Verifica se a freeCell ja possui uma carta ou não
// Pós-Condição: Adicionará 1 ao contador para que a freeCel fique cheia
bool freeCell::Full()
{
    return (count == MAXVALOR);
}

// Pré-condição: A FreeCell ter sido criada e estar vazia
// Pós-Condição: Inserir Carta desejada na FreeCell
bool freeCell::PushFreeCell(Carta c)
{
    if (Full())
    {
        cout << "Nao e possivel inserir uma carta nessa FreeCell, escolha outra" << endl;
        return false;
    }
    else
    {
        count++;
        current = c;
        return true;
    }
}

// Pré-condição: FreeCell possuir uma carta nela, ou seja, está cheia
// Pós-Condição: Se a pilha não estiver vazia, ira retirar a carta desejada para realizar a jogada
bool freeCell::RemoveFreeCell(Carta c)
{
    if (Empty())
    {
        cout << "Pilha vazia, nao e possivel retirar cartas daqui" << endl;
        return false;
    }
    else 
    {
        count--;
        return true;
    }
}

void freeCell::display()
{
    current.Display();
    cout << "   ";
}