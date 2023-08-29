#include "pilha.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Pilha::Pilha(){ //Ação que indica o valor inicial da Pilha
    top = 0;
}

Pilha::~Pilha() {
    cout << "Essa pilha foi deletada";
}

void Pilha::Push(){ //Ação que verifica se a pilha não esta cheia ou se possui um lixo de momoria
    if(Full()){
        cout << "Pilha cheia" << endl;
        abort();
        return;
    }else{
        top++;
        //Entry[];
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

Pilha_Saida::Pilha_Saida(){
    top_saida = 0;
}