#include <iostream>
using namespace std;

class Carta {
    public:
        void Inicializar(int val, string naip);
        void Display();
        string display; // "Ás, dois, valete"
        string naipe; // "Copas, ouro"
        int valor; // "1, 2, 11"
    private:
};