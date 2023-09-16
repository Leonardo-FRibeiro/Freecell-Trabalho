#include "pilha_saida.h"
#include <iostream>

// Pré-condição: Nenhuma.
// Pós-condição: É criada uma pilha de saída com o naipe selecionado.
Pilha_Saida::Pilha_Saida(string n)
{
    current = Carta(14, n);
    naipe = n;
}

Pilha_Saida::Pilha_Saida(string n, Pilha_Saida *p)
{
    current = Carta(14, n);
    naipe = n;
    nextPilhaS = p;
}

// Pré-condição: A pilha de saída foi criada
// Pós-condição: A pilha de saída é destruída
Pilha_Saida::~Pilha_Saida() {}

// Pré-condição: A pilha de saída foi criada, e essa função recebe uma carta
// Pós-condição: Se possível, a pilha de saída recebe a carta nova.
bool Pilha_Saida::Push(Carta c)
{
    if (c.GetNaipe() == naipe && c.GetValor() == 1 + current.GetValor() || current.GetValor() == 14)
    {
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