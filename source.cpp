#include <iostream>
#include "carta.h"
#include "pilha.h"
#include <cstdlib>
using namespace std;

int main () {
        srand(time(0));
    int index;
    Carta carta[52]; // vetor de 52 carta
    string naipes[] = {"P", "O", "C", "E"};
    //O for ta preenchendo o vetor com as 52 cartas
    for(int valor = 1; valor <= 13; valor++){
        for(int naipe = 0; naipe < 4; naipe++){
            carta[index] = Carta(valor, naipes[naipe]);
            index++;
        }
    }
    //Tentei fazer um embaralhamento das cartas
    for(int i = 51; i > 0; i--){
        swap(carta[i], carta[rand()%(i+1)]);
    }
    
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
// - Agente devia criar um vetor com 52 espaços no começo, e preencher eles com as cartas. (ja estou fazendo isso - Augusto)
// Esse preenchimento devia ser aleatório.(ja estou fazendo isso - Augusto)
// - As freecells, um objetinho básico pra guardar uma única carta.
// ----------------------------
// Feito isso, falta começar a implementar a lógica de mover as cartas, pegar input do jogador, etc.

// - Leo. 
