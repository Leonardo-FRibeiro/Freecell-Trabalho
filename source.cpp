#include <iostream>
#include "carta.h"
#include "pilha.h"
using namespace std;

int main () {

    Carta c1(10, "C");
    Carta c2(1, "P");
    Pilha p1;
    Pilha p2;
    p1.Push(Carta(3, "O"), 0);
    p1.Push(c1, 0);
    p1.Push(c2, 1);
    p1.Push(Carta(5, "P"), 0);
    p1.DisplayLine(0);
    cout << endl;
    p1.DisplayLine(1);
    cout << endl;
    p1.DisplayLine(2);

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
