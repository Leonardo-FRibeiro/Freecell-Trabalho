#include "freecell.h"
#include <iostream>
using namespace std;

const int MAXVALOR = 1;
const int numFreeCells = 4;

// Pré-condição: < nenhuma >
// Pós-Condição: FreeCell é criada
freeCell::freeCell()
{
    count = 0;
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
void freeCell::PushFreeCell(int x)
{
    if (Full())
    {
        cout << "Não é possível inserir uma carta nessa FreeCell, escolha outra" << endl;
    }
    count++;
    EntryFreeCell[count] = x;
}

// Pré-condição: FreeCell possuir uma carta nela, ou seja, está cheia
// Pós-Condição: Se a pilha não estiver vazia, ira retirar a carta desejada para realizar a jogada
void freeCell::RemoveFreeCell(int &x)
{
    if (Empty())
    {
        cout << "Pilha vazia, não é possível retirar cartas daqui" << endl;
    }
    x = EntryFreeCell[count];
    count--;
}
