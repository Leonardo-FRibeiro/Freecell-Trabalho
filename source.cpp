#include <iostream>
#include "carta.h"
#include "pilha.h"
#include <cstdlib>
using namespace std;

// Pré-condição: Os elementos do jogo foram inicializados, e são passados como parâmetros
// Pós-condição: Renderiza os elementos do jogo.
void DisplayBoard(Pilha pilha1, Pilha pilha2, Pilha pilha3, Pilha pilha4) {
    cout << "Pilhas de jogo: " << endl;
    cout << " (1)   (2)   (3)   (4)   (5)   (6)   (7)   (8)" << endl;
    for (int i = 0; i < 13; i++)
    {
        pilha1.DisplayLine(i);
        pilha2.DisplayLine(i);
        pilha3.DisplayLine(i);
        pilha4.DisplayLine(i);
        cout << endl;
    }
}

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
    int gameState = 0; // Esta variavel guarda a situação em que o jogo se encontra.
    Pilha p1, p2, p3, p4; // Estas são as estruturas que guardam as cartas.
    p1.Push(Carta(3, "O"), 0);
    p1.Push(Carta(5, "P"), 1);
    p1.Push(Carta(3, "P"), 1);
    p1.Push(Carta(12, "E"), 1);
    p2.Push(Carta(3, "E"), 0);
    p2.Push(Carta(6, "O"), 1);
    p3.Push(Carta(7, "P"), 0);
    p3.Push(Carta(11, "C"), 1);
    p4.Push(Carta(2, "E"), 0);
    p4.Push(Carta(13, "E"), 1);

    while(gameState == 0) {
        system("cls"); // Nota: Isso funciona apenas no windows. 
        cout << "Escolha uma carta para mover" << endl;
        DisplayBoard(p1, p2, p3, p4);
        cin.get();
    }
    return 1;
}

// Atualizações: 

// ----------------------------
// O que eu acho que seriam os próximos passos: 
// - Agente devia criar um vetor com 52 espaços no começo, e preencher eles com as cartas. (ja estou fazendo isso - Augusto)
// Esse preenchimento devia ser aleatório.(ja estou fazendo isso - Augusto)
// - As freecells, um objetinho básico pra guardar uma única carta.
// ----------------------------
// Feito isso, falta começar a implementar a lógica de mover as cartas, pegar input do jogador, etc.

// - Leo. 
