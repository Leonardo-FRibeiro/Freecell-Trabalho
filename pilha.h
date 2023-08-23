#include "carta.cpp"
const int MAXSTACK = 26;

class carta; //Chama o metodo da Classe Carta
class Pilha{
    public:
    Pilha();
    void Push();
    void Pop();
    void Full();
    void Inicializar(int val, string naip); //Com o chamado da Classe Carta, pode se usar os parametros de carta, dentro da pilha 
    void Display();


    private:
    int top;
    int Entry[MAXSTACK+1];
};


class Pilha_Saida{
    public:
    
    Pilha_Saida();
    void Push_Saida();
    void Pop_Saida();
    void Full_Saida();

    private:
    int top_saida;
};