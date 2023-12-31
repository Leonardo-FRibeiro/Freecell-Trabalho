// Alunos:
// Leonardo Franzin Ribeiro - 2108237
// Luís Felipe Rotondo Kobelnik - 2125543
// Augusto Coimbra de Oliveira - 2136390

#ifndef PILHA_SAIDA_H
#define PILHA_SAIDA_H
#include "carta.h"

// A pilha de saída segura uma única carta porque as cartas da freecell devem ser movidas em ordem.
// As cartas anteriores são sobrescritas.
class Pilha_Saida {
    public:
        Pilha_Saida(string naipe);
        Pilha_Saida(string naipe, Pilha_Saida* pPil);
        ~Pilha_Saida();
        bool Push(Carta c);
        bool CheckWin();
        Pilha_Saida* nextPilhaS;
        void Display();
        void Reset();
    private:
        Carta current;
        string naipe;
};
#endif