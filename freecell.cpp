// Alunos:
// Leonardo Franzin Ribeiro - 2108237
// Luís Felipe Rotondo Kobelnik - 2125543
// Augusto Coimbra de Oliveira - 2136390

#include "freecell.h"
#include <iostream>
using namespace std;

const int MAXVALOR = 1;
const int numFreeCells = 4;

// Pré-condição: < nenhuma >
// Pós-Condição: FreeCell é criada
freeCell::freeCell(string n, freeCell *p)
{
    count = 0;
    current = Carta(17, n);
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
    return (count == MaxFreeCell);
}

// Pré-condição: A FreeCell ter sido criada e estar vazia
// Pós-Condição: Inserir Carta desejada na FreeCell
bool freeCell::PushFreeCell(Carta c)
{
    if (Full())
    {
        cout << "Não é possível inserir uma carta nessa FreeCell, escolha outra" << endl;
        return true;
    }
    else
    {
        current = c;
        count++;
        return false;
    }
}

// Pré-condição: FreeCell possuir uma carta nela, ou seja, está cheia
// Pós-Condição: Se a pilha não estiver vazia, ira retirar a carta desejada para realizar a jogada
bool freeCell::RemoveFreeCell(Carta c)
{
    if (Empty())
    {
        cout << "Pilha vazia, não é possível retirar cartas daqui" << endl;
        return true;
    }
    else 
    {
        count--;
        return false;
    }
}

void freeCell::display()
{
    current.Display();
    cout << "   ";
}