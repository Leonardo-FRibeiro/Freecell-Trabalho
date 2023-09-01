#ifndef PILHA_H
#define PILHA_H

#include "carta.h"
const int MAXSTACK = 26; // A pilha guardará no máximo 26 elementos

// Essa classe vai representar uma pilha. Cada pilha ira gerenciar duas colunas
// do jogo. (4 pilhas para as 8 colunas principais, 2 pilhas para as pilhas de saída)
class Pilha{
    public:
    Pilha(); // A função construtora já cria a pilha, não é necessário uma função p/ inicializar
    ~Pilha(); // Função destrutora
    void Push(Carta c); // Adiciona uma carta
    Carta Pop(); // Remove uma carta
    bool Full(); // Avisa se a pilha está cheia
    void Display(); // Imprime todas as cartas da pilha

    private:
    int top;
    Carta Entry[MAXSTACK];
};

// Nota: Eu acredito que essa pilha não vai ser necessária. Acho que nós conseguimos fazer tudo
// com a pilha normal.
class Pilha_Saida{
    public:
    
    Pilha_Saida();
    void Push_Saida();
    void Pop_Saida();
    void Full_Saida();

    private:
    int top_saida;
};
#endif