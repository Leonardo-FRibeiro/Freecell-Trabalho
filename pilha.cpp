#include "pilha.h"
#include "carta.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// Pré-condição: Nenhuma
// Pós-condição: É criada uma pilha
Pilha::Pilha(){
    top = 0;
}

// Pré-condição: Nenhuma
// Pós-condição: A pilha é destruída.
Pilha::~Pilha() {}

// Pré-condição: É passado uma carta.
// Pós-condição: A pilha adicionará essa carta ao topo da pilha.
void Pilha::Push(Carta c){
    if(Full()){
        cout << "Pilha cheia" << endl;
    }else{
        Entry[top] = c;
        top++;
    }
}

// Pré-condição: Nenhuma
// Pós-condição: A pilha remove a carta em seu topo, e retorna ela.
Carta Pilha::Pop() {
    if(top == 0) {
        cout << "Pilha vazia" << endl;
        return Carta();
    } else {
        top--;
        return Entry[top];
    }
}

// Pré-condição: Nenhuma
// Pós-condição: É retornado se a pilha está cheia
bool Pilha::Full() {
    if(top == MAXSTACK) {
        return true;
    } else {
        return false;
    }
}

// Pré-condição: Nenhuma
// Pós-condição: A pilha lista todas as suas cartas
void Pilha::Display() {
    if(top == 0) {
        cout << "Esta pilha está vazia";
    } else {
        for(int i = 0; i < top; i++) {
            cout << " ";
            Entry[i].Display();
        }
        cout << endl;
    }
}

Pilha_Saida::Pilha_Saida(){
    top_saida = 0;
}