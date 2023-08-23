#include "carta.h"
#include <iostream>

using namespace std;

// Pré-condição: 1 <= val <= 13 | naip = 'E', 'C', 'O', 'P'.
// Pós-condição: A carta é criada
Carta::Carta(int val, string naip) {
    valor = val;
    naipe = naip;

    if(val >= 2 && val <= 10) { // Caso o valor passado esteja entre 2 e 10
        display = "[" + to_string(val) + naipe + "]";
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

// Pré-condição: Nenhuma
// Pós-condição: É imprimido um gráfico que mostra as informações da carta.
void Carta::Display() {
    cout << "Display: " << display << " - Valor: " << valor << " - Naipe: " << naipe;
}