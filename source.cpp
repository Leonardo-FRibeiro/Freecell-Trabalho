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

// Pré-condição: O jogo foi inicializado.
// Pós-condição: A pilha que contem a carta é selecionada, e
// a função retorna a carta selecionada.
Carta GetCarta(int local, int index, Pilha* pilhaInicio) {
    // pilhaInicio: O começo da cadeia, é usada para navegação. Em chamadas futuras,
    // é a "próxima" pilha.
    // pilhaOrigem: A pilha de onde a carta é selecionada 
    if(index == local) {
        Carta r = pilhaInicio->GetTop(0);
        return r;
    } else if(index + 1 == local) {
        Carta r = pilhaInicio->GetTop(1);
        return r;
    } else {
        Carta r = GetCarta(local, index + 2, pilhaInicio->proximaPilha);
        return r;
    }
}

// Pré-condição: O usuário está movendo a carta para um lugar válido.
// Essa função deve achar a pilha e remover a carta.
void FindAndPop(int local, int index, Pilha* pilhaInicio) {
    if(index == local) {
        pilhaInicio->Pop(0);
    } else if(index + 1 == local) {
        pilhaInicio->Pop(1);
    } else {
        FindAndPop(local, index + 2, pilhaInicio->proximaPilha);
    }
}

void FindAndPush(int local, int index, Pilha* pilhaInicio, Carta c) {
    if(index == local) {
        pilhaInicio->Push(c, 0);
    } else if(index + 1 == local) {
        pilhaInicio->Push(c, 1);
    } else {
        FindAndPush(local, index + 2, pilhaInicio->proximaPilha, c);
    }
}

void MoveCard(int destino, int origem, Pilha* pilhaInicio, Carta c) {
    FindAndPush(destino, 1, pilhaInicio, c);
    FindAndPop(origem, 1, pilhaInicio);
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

    int origem, destino, gameState = 0; // Esta variavel guarda a situação em que o jogo se encontra.
    Pilha p4 = Pilha(); // Estas são as estruturas que guardam as cartas.
    Pilha p3 = Pilha(&p4);
    Pilha p2 = Pilha(&p3);
    Pilha p1 = Pilha(&p2);
    p1.Push(Carta(2, "O"), 1);
    p2.Push(Carta(13, "E"), 0);
    p4.Push(Carta(1, "C"), 1);
    p1.Push(Carta(3, "P"), 0);

    
    Carta cartaSelecionada; // Esta é a carta que o jogador está "segurando".
    while(gameState == 0) {
        system("cls"); // Nota: Isso funciona apenas no windows. 
        cout << "Escolha uma carta para mover" << endl;
        DisplayBoard(p1, p2, p3, p4);
        cin >> origem;
        cartaSelecionada = GetCarta(origem, 1, &p1);
        system("cls");
        DisplayBoard(p1, p2, p3, p4);
        cout << "A carta selecionada: ";
        cartaSelecionada.Display();
        DisplayBoard(p1, p2, p3, p4);
        cout << endl << "Escolha onde voce quer mover a carta: " << endl;
        cin >> destino;
        MoveCard(destino, origem, &p1, cartaSelecionada);
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

// - Leo. 
