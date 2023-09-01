#include <iostream>
#include "carta.h"
#include "pilha.h"
using namespace std;

int main () {

    Carta c(10, "C");
    Carta c2(1, "P");
    Pilha p1;
    
    p1.Push(c);
    p1.Push(c2);
    p1.Push(Carta(3, "O"));
    p1.Display();
    p1.Pop();
    p1.Display();
    p1.Push(c);
    p1.Display();

    return 1;
}

// Atualizações: 
// A pilha está construída e está funcionando para adicionar, remover, ver se está cheia, etc.
// O que eu acho que seriam os próximos passos: 
// - Agente devia criar um vetor com 52 espaços no começo, e preencher eles com as cartas. 
// Esse preenchimento devia ser aleatório.
// - A pilha devia ser bi-dimensional, para guardar duas colunas, ou ter duas propriedades de
// entry. Ambos funcionam, vai depender da nossa preferência.
// - As freecells, um objetinho básico pra guardar uma única carta.

// - Leo. 
