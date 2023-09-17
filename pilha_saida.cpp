// Alunos:
// Leonardo Franzin Ribeiro - 2108237
//
//

#include "pilha_saida.h"
#include <iostream>

// Pré-condição: É passado uma letra ("E", "C", "O", "P").
// Pós-condição: É criada uma pilha de saída com o naipe selecionado.
Pilha_Saida::Pilha_Saida(string n)
{
    current = Carta(14, n);
    naipe = n;
}

// Pré-condição: Outra pilha deve ter sido criada. É passado a letra
// do naipe, e um ponteiro para a outra pilha.
// Pós-condição: É criada uma pilha de saída com o naipe selecionado,
// e um ponteiro apontando para a próxima pilha.
Pilha_Saida::Pilha_Saida(string n, Pilha_Saida* p) {
    current = Carta(14, n);
    naipe = n;
    nextPilhaS = p;
}

// Pré-condição: A pilha foi criada. (Na prática, o jogo tem que ter acabado
// também)
// Pós-condição: A pilha tem seu valor resetado, ou seja, ela "se esvazia".
void Pilha_Saida::Reset() {
    current = Carta(14, naipe);
}

// Pré-condição: A pilha de saída foi criada
// Pós-condição: A pilha de saída é destruída
Pilha_Saida::~Pilha_Saida() {}

// Pré-condição: A pilha de saída foi criada, e essa função recebe uma carta
// Pós-condição: Se possível, a pilha de saída recebe a carta nova.
bool Pilha_Saida::Push(Carta c) {
    if(c.GetNaipe() == naipe && c.GetValor() == 1 + current.GetValor() || current.GetValor() == 14 && c.GetValor() == 1 && c.GetNaipe() == naipe) {
        current = c;
        return true;
    }
    else
    {
        return false;
    }
}

// Pré-condição: A pilha de saída foi criada
// Pós-condição: A pilha de saída ira avisar se a sua condição de vitória foi
// atingida. (Ou seja, a sua carta é um rei, indicando que todas as cartas desse)
// naipe já foram colocadas aqui.
bool Pilha_Saida::CheckWin()
{
    if (current.GetValor() == 13)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Pré-condição: A pilha de saída foi criada
// Pós-condição: A pilha de saída vai mostrar a sua carta.
void Pilha_Saida::Display()
{
    current.Display();
    cout << "   ";
}