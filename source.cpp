#include <iostream>
#include "carta.h"
#include "pilha.h"
using namespace std;

int main () {

    Carta c(10, "C");
    Carta c2(1, "P");
    Pilha p1;

    p1.Push(Carta(3, "O"), 0);
    p1.Push(Carta(4, "P"), 0);
    p1.Push(c, 0);
    p1.Push(c2, 0);
    p1.Push(c, 1);
    p1.Push(Carta(3, "O"), 1);
    p1.Push(c2, 1);
    p1.Push(Carta(4, "P"), 1);
    p1.Display();
    if(p1.Full(0)) {
        cout << "A M O G U S" << endl;
    }
    if(p1.Full(1)) {
        cout << "AAAAAAAAAAA" << endl;
    }

    return 1;
}

// Atualizações: 
// A pilha foi adaptada para trabalhar com duas colunas. Eu preferi fazer uma matriz 2d mesmo,
// além disso, a variável "top" agora é um vetor com dois espaços, 0 pra esquerda, 1 pra direita.
// ----------------------------
// O que eu acho que seriam os próximos passos: 
// - Criar uma função que lista as linhas de uma forma mais "intuitiva", que nem o exemplo que o
// professor deu na sala de aula. (Eu vou fazer isso, não se preocupem)
// - Agente devia criar um vetor com 52 espaços no começo, e preencher eles com as cartas. 
// Esse preenchimento devia ser aleatório.
// - As freecells, um objetinho básico pra guardar uma única carta.
// ----------------------------
// Feito isso, falta começar a implementar a lógica de mover as cartas, pegar input do jogador, etc.

// - Leo. 
