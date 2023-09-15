// Alunos:
// Leonardo Franzin Ribeiro - 2108237
//
//

#ifndef CARTA_H
#define CARTA_H

#include <iostream>
using namespace std;

// Essa classe vai representar uma carta individual. 
class Carta {
    public:
        Carta(); // Um construtor padrão (não deve ser usado no código)
        Carta(int val, string naip); // Construtor
        ~Carta(); // Destrutor
        void Display(); // Gráfico
        void DebugPrint(); // Função para debugar
        int GetValor(); // Retorna o valor
        string GetCor(); // Retorna a cor
        string GetNaipe(); // Retorna o naipe
    private:
        string display; // "A, 2, V"
        string naipe; // "Copas, ouro"
        string cor; // "P" ou "V"
        int valor; // "1, 2, 11"
};
#endif