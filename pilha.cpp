#include "pilha.h"
#include "carta.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// Pré-condição: Nenhuma
// Pós-condição: É criada uma pilha
Pilha::Pilha(){
    top[0] = 0;
    top[1] = 0;
    // Nota: Por algum motivo, "int top[2] = {0, 0}" não funciona. Eu devia investigar isso.
}

// Pré-condição: Outra pilha foi criada
// Pós-condição: É criada outra pilha, com o ponteiro apontando para a próxima pilha.
Pilha::Pilha(Pilha* p) {
    top[0] = 0;
    top[1] = 0;
    proximaPilha = p;
}

// Pré-condição: A pilha foi criada
// Pós-condição: A pilha é destruída.
Pilha::~Pilha() {}

// Pré-condição: É passado uma carta, e um valor do lado
// (0 = pilha da esquerda), (1 = pilha da direita). (E a pilha foi criada)
// Pós-condição: A pilha adicionará essa carta ao topo da pilha.
void Pilha::Push(Carta c, int lado){
    if(Full(lado)){
        cout << "Pilha cheia" << endl;
    }else{
        Entry[top[lado]][lado] = c;
        top[lado]++;
    }
}

// Pré-condição: A pilha foi criada.
// Se houver uma carta nesse lado, ele retorna ela. Retorna uma carta-erro no caso da pilha
// estar vazia. 
Carta Pilha::GetTop(int lado) {
    if(top[lado] == 0) {
        cout << "Pilha vazia" << endl;
        return Carta();
    } else {
        return Entry[top[lado]-1][lado];
    }
}

// Pré-condição: A pilha foi criada.
// Pós-condição: A pilha remove a carta no topo da coluna selecionada, e retorna ela 
// (retorna uma carta-erro se não tiver uma carta ali).
Carta Pilha::Pop(int lado) {
    if(top == 0) {
        //cout << "Pilha vazia" << endl;
        return Carta();
    } else {
        top[lado]--;
        Carta c = Entry[top[lado]][lado];
        Entry[top[lado]][lado] = Carta();
        return c;
    }
}

// Pré-condição: A pilha foi criada
// Pós-condição: É retornado se a pilha está cheia ou não.
bool Pilha::Full(int lado) {
    if(top[lado] == MAXSTACK) {
        return true;
    } else {
        return false;
    }
}

// Pré-condição: A pilha foi criada
// Pós- condição: Retorna se a pilha está vazia ou não.
bool Pilha::Empty(int lado) {
    if(top[lado] == 0) {
        return true;
    } else {
        return false;
    }
}

// Pré-condição: A pilha foi criada
// Pós-condição: A pilha lista todas as suas cartas
void Pilha::Display() {
    for(int x = 0; x < 2; x++) {        
        if(top[x] == 0) {
            cout << "Esta coluna esta vazia" << endl;
        } else {
            for(int y = 0; y < top[x]; y++) {
                Entry[y][x].Display();
            }
            cout << endl;
        }
    }
}

// Pré-condição: A pilha foi criada
// Pós-condição: A pilha lista as suas cartas de uma linha.
void Pilha::DisplayLine(int linha) {
    for(int i = 0; i < 2; i++) {
        if(top[i] > linha) {
            Entry[linha][i].Display();
            string t = (Entry[linha][i].GetValor() == 10) ? " " : "  "; // Questão de espaçamento, a
            cout << t; // carta 10 é mais "gordinha", então ela dá um espaço a menos pra ficar alinhada.
        } else {
            cout << "      ";
        }
    }
}

Pilha_Saida::Pilha_Saida(){
    top_saida = 0;
}