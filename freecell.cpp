// Alunos:
// Leonardo Franzin Ribeiro - 2108237
// Luís Felipe Rotondo Kobelnik - 2125543
// Augusto Coimbra de Oliveira - 2136390

#include "freecell.h"
#include <iostream>
using namespace std;

const int MAXVALOR = 1;
const int numFreeCells = 4;

// Pré-condição: Nenhuma
// Pós-condição: A freecell é criada e preenchida com uma carta "vazia"
freeCell::freeCell() {
    current = Carta(14, " ");
}

// Pré-condição: Uma freecell anterior tenha sido criada.
// Pós-condição: A freecell é criada e preenchida com uma carta "vazia", e um ponteiro para a próxima freecell.
freeCell::freeCell(freeCell *p)
{
    current = Carta(14, " ");
    nextfreeCell = p;
}

// Pré-condição: FreeCell criada
// Pós-Condição: FreeCell é destruída
freeCell::~freeCell(){};

// Pré-condição: Verifica se a freeCell ja possui uma carta ou não
// Pós-Condição: subtrairá 1 ao contador para que a freeCel fique vazia
bool freeCell::Empty()
{
    return (current.GetValor() == 14);
}

// Pré-condição: Verifica se a freeCell ja possui uma carta ou não
// Pós-Condição: Adicionará 1 ao contador para que a freeCel fique cheia
bool freeCell::Full()
{
    return (current.GetValor() != 14);
}

// Pré-condição: A FreeCell ter sido criada e estar vazia
// Pós-Condição: Inserir Carta desejada na FreeCell
bool freeCell::PushFreeCell(Carta c)
{
    if (Full())
    {
        //cout << "Não é possível inserir uma carta nessa FreeCell, escolha outra" << endl;
        return false;
    } else {
        current = c;
        return true;
    }
}

// Pré-condição: FreeCell possuir uma carta nela, ou seja, está cheia
// Pós-Condição: Remove a carta da freecell
bool freeCell::RemoveFreeCell()
{
    if (Empty())
    {
        //cout << "Pilha vazia, não é possível retirar cartas daqui" << endl;
        return false;
    }
    else {
        current = Carta(14, " ");
        return true;
    }
}

// Pré-condição: Freecell foi criada (e possui uma carta).
// Pós-condição: Retorna essa carta.
Carta freeCell::GetCurrent() {
    if(Empty()) {
        cout << "A freecell está vazia.";
        return Carta();    
    } else {
        return current;
    }
}

// Pré-condição: Freecell foi criada
// Pós-condição: A freecell vai "renderizar".
void freeCell::display()
{
    current.Display();
    string espaco = (current.GetValor() == 10) ? "  " : "   "; // Questão de espaçamento, a
    cout << espaco; // carta 10 é mais "gordinha", então ela dá um espaço a menos pra ficar alinhada.
}