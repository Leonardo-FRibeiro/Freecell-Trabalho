#include <iostream>
#include "carta.h"
#include "pilha.h"
#include "pilha_saida.h"
#include <cstdlib>
using namespace std;

// Pré-condição: Os elementos do jogo foram inicializados, e são passados como parâmetros
// Pós-condição: Renderiza os elementos do jogo.
void DisplayBoard(Pilha pilha1, Pilha pilha2, Pilha pilha3, Pilha pilha4, Pilha_Saida ps1, Pilha_Saida ps2, Pilha_Saida ps3, Pilha_Saida ps4) {
    cout << "Pilhas de jogo:                                 | Pilhas de saida: " << endl;
    cout << " (1)   (2)   (3)   (4)   (5)   (6)   (7)   (8)  |  (9)   (10)   (11)   (12)" << endl;
    for (int i = 0; i < 13; i++)
    {
        pilha1.DisplayLine(i);
        pilha2.DisplayLine(i);
        pilha3.DisplayLine(i);
        pilha4.DisplayLine(i);
        cout << "| ";
        if(i == 0) {
            ps1.Display();
            ps2.Display();
            ps3.Display();
            ps4.Display();
        }
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

// Pré-condição: O usuário está movendo a carta para um lugar válido.
// Essa função deve achar a pilha para qual a carta está sendo movida e adiciona-la. Se não for possível,
// ele retorna false. (Se der certo retorna true)
bool FindAndPush(int local, int index, Pilha* pilhaInicio, Carta c) {
    Carta check;
    if(index == local) {
        if(pilhaInicio->Empty(0)) {
            pilhaInicio->Push(c, 0);
            return true;
        } else {
            check = pilhaInicio->GetTop(0); // A carta no topo da pilha selecionada.
            if (check.GetCor() != c.GetCor() && check.GetValor() == 1 + c.GetValor()) {
                pilhaInicio->Push(c, 0);
                return true;
            } else {
                return false;
            }
        }
    } else if(index + 1 == local) {
        if(pilhaInicio->Empty(1)) {
            pilhaInicio->Push(c, 1);
            return true;
        } else {
            check = pilhaInicio->GetTop(1);
            if (check.GetCor() != c.GetCor() && check.GetValor() == 1 + c.GetValor()) {
                pilhaInicio->Push(c, 1);
                return true;
            } else {
                return false;
            }   
        }
    } else {
        return FindAndPush(local, index + 2, pilhaInicio->proximaPilha, c);
    }
}

bool FindAndPush(int local, int index, Pilha_Saida* pilhaInicio, Carta c) {
    if(index == local) {
        return pilhaInicio->Push(c);
    } else {
        return FindAndPush(local, index + 1, pilhaInicio->nextPilhaS, c);
    }
}

bool MoveCard(int destino, int origem, Pilha* pilhaInicio, Carta c, Pilha_Saida* pilhaSInicio) {
    if(destino <= 8) {
        if (FindAndPush(destino, 1, pilhaInicio, c)) {
            FindAndPop(origem, 1, pilhaInicio);
            return true;
        } else {
            return false;
        }
    } else if(destino > 8 && destino < 13 ) {
        if (FindAndPush(destino, 9, pilhaSInicio, c)) {
            FindAndPop(origem, 1, pilhaInicio);
            return true;
        } else {
            return false;
        }
    } else {
        return false;
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

    int origem, destino, gameState = 1; // Esta variavel guarda a situação em que o jogo se encontra.
    Pilha p4 = Pilha(); // Estas são as estruturas que guardam as cartas.
    Pilha p3 = Pilha(&p4);
    Pilha p2 = Pilha(&p3);
    Pilha p1 = Pilha(&p2);
    Pilha_Saida psP = Pilha_Saida("P");
    Pilha_Saida psO = Pilha_Saida("O", &psP);
    Pilha_Saida psC = Pilha_Saida("C", &psO);
    Pilha_Saida psE = Pilha_Saida("E", &psC);
    p1.Push(Carta(1, "E"), 0);
    p1.Push(Carta(1, "C"), 1);
    p2.Push(Carta(1, "O"), 0);
    p2.Push(Carta(1, "P"), 1);

    
    Carta cartaSelecionada; // Esta é a carta que o jogador está "segurando".
    while(gameState != 0) {
        if(gameState == 1) {
            cout << "Escolha uma carta para mover" << endl;
            DisplayBoard(p1, p2, p3, p4, psE, psC, psO, psP);
            cin >> origem;
            cartaSelecionada = GetCarta(origem, 1, &p1);
            system("cls"); // Nota: Isso funciona apenas no windows.
            if(cartaSelecionada.GetValor() == -1) {
                cout << "Erro: a coluna selecionada nao tem uma carta" << endl;
            } else {
                gameState = 2;
            }
        } else if (gameState == 2) {
            //system("cls");
            DisplayBoard(p1, p2, p3, p4, psE, psC, psO, psP);
            cout << "A carta selecionada: ";
            cartaSelecionada.Display();
            cout << endl << "Escolha onde voce quer mover a carta(0 para cancelar): " << endl;
            cin >> destino;
            if(destino == 0) {
                cartaSelecionada = Carta();
                gameState = 1;
            }
            else if(MoveCard(destino, origem, &p1, cartaSelecionada, &psE) == true) {
                gameState = 1;
            } else {
                cout << "Houve um erro na hora de mover a carta" << endl;
                gameState = 2;
            }
        }
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
