#ifndef PILHA_H
#define PILHA_H

#include "carta.h"
const int MAXSTACK = 13; // A pilha guardará no máximo 13 elementos em uma coluna. (Para um total máximo de 26)

// Essa classe vai representar uma pilha. Cada pilha ira gerenciar duas colunas
// do jogo. (4 pilhas para as 8 colunas principais, 2 pilhas para as pilhas de saída)
class Pilha{
    public:
    Pilha(); // A função construtora já cria a pilha, não é necessário uma função p/ inicializar
    Pilha(Pilha* pPil); // Versão do construtor que define uma próxima pilha para apontar
    ~Pilha(); // Função destrutora
    void Push(Carta c, int lado); // Adiciona uma carta no lado selecionado
    Carta GetTop(int lado); // Obtem a carta no topo no lado selecionado
    Carta Pop(int lado); // Remove uma carta no lado selecionado
    bool Full(int lado); // Avisa se a pilha do lado selecionado está cheia
    bool Empty(int lado); // Avisa se a pilha do lado selecionado está vazia
    void Display(); // Imprime todas as cartas da pilha
    void DisplayLine(int linha); // Imprime as cartas de uma linha
    Pilha* proximaPilha; // Este ponteiro aponta para a pilha que aprece a esquerda do usuário.

    private:
    int top[2]; // Nota: Do jeito que está implementado, essa variável para "1 acima" da verdadeira carta do topo.
    Carta Entry[MAXSTACK][2];
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