#include "carta.h"
#include <iostream>

using namespace std;

// Pré-condição: A carta foi criada
// Pós-condição: Retorna uma carta indicando -1. 
// Nota: Esse constrtor não deve ser chamado no código.
// O compilador requeriu um construtor vazio assim, mas é para usar
// o segundo.
Carta::Carta() {
    valor = -1;
    cor = "-1";
    naipe = "X";
    display = "[-1X]";
}

// Pré-condição: 1 <= val <= 13 | naip = 'E', 'C', 'O', 'P'.
// Pós-condição: A carta é criada
Carta::Carta(int val, string naip) {
    valor = val;
    naipe = naip;
    
    if(naip == "E" || naip == "P") {
        cor = "P";
    } else {
        cor = "V";
    }

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

// Pre-condição: A carta foi criada
// Pós-condição: Deleta essa carta
Carta::~Carta() {}

// Pré-condição: A carta foi criada
// Pós-condição: É imprimido o gráfico dessa carta.
void Carta::Display() {
    cout << display;
}

// Pré-condição: A carta foi criada
// Pós-condição: Essa função retorna o valor da carta.
int Carta::GetValor() {
    return valor;
}

// Pré-condição: A carta foi criada
// Pós-condição: Essa função retorna a cor da carta.
string Carta::GetCor() {
    return cor;
}

// Pré-condição: A carta foi criada
// Pós condição: É imprimido os dados dessa carta (cor, valor, o gráfico, e o naipe)
// Nota: Isso só deveria ser usado durante o desenvolvimento do sistema.
void Carta::DebugPrint() {
    cout << "Display: " << display << " - Valor: " << valor << " - Naipe: " << naipe << " - Cor:" << cor << endl;
}