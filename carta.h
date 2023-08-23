#include <iostream>
using namespace std;

class Carta {
    public:
        Carta(int val, string naip);
        void Display();
    private:
        string display; // "Ás, dois, valete"
        string naipe; // "Copas, ouro"
        string cor; // "P" ou "V"
        int valor; // "1, 2, 11"
};