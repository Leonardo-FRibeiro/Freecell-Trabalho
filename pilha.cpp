#include "pilha.h"
#include "carta.h"


Pilha::Pilha(){ //Ação que indica o valor inicial da Pilha
    top = 0;
}

void Pilha::Push(){ //Ação que verifica se a pilha não esta cheia ou se possui um lixo de momoria
    if(Full()){
        cout << "Pilha cheia" << endl;
        abort();
        return;
    }else{
        top++;
        Entry[];
    }

}

void Pilha::Inicializar(int val, string naip){
    
}



Pilha_Saida::Pilha_Saida(){
    top_saida = 0;
}