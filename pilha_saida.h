#ifndef PILHA_SAIDA_H
#define PILHA_SAIDA_H
#include "carta.h"

class Pilha_Saida
{
public:
    Pilha_Saida(string naipe);
    Pilha_Saida(string naipe, Pilha_Saida *pPil);
    ~Pilha_Saida();
    bool Push(Carta c);
    bool CheckWin();
    Pilha_Saida *nextPilhaS;
    void Display();

private:
    Carta current;
    string naipe;
};
#endif