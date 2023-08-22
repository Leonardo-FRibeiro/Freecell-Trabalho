#include "carta.h"
#include <iostream>

using namespace std;

void Carta::Inicializar(int val, string naip) {
    valor = val;
    naipe = naipe;

    if(val >= 2 && val <= 10) { // Caso o valor passado esteja entre 2 e 10
        display = "[" + to_string(val) + naipe + "]";
        cout << naip;
    } else { // Se não for o caso
        switch(val) {
            case 1: // Caso seja um ás
                display = "[A" + naipe + "]";
                break;
            case 11: // Caso seja um valete
                display = "[J" + naipe + "]";
                break;
            case 12: // Caso seja uma dama
                display = "[Q" + naipe + "]";
                break;
            case 13: // Caso seja um rei
                display = "[K" + naipe + "]";
                break;
            default: // Se cair aqui, alguma coisa deu catastroficamente errado.
                display = "[Erro]";
                break;
        }
    }
}

void Carta::Display() {
    cout << "Display: " << display << " - Valor: " << valor << " - Naipe: " << naipe;
}