#include <iostream>
using namespace std;

// Essa classe vai representar uma carta individual. 
class Carta {
    public:
        Carta(int val, string naip); // Construtor
        ~Carta(); // Destrutor
        void Display(); // Gráfico
        void DebugPrint(); // Função para debugar
    private:
        string display; // "A, 2, V"
        string naipe; // "Copas, ouro"
        string cor; // "P" ou "V"
        int valor; // "1, 2, 11"
};