const int MAXSTACK = 26;

// Nota: Eu vou tentar implementar a funcionalidade de adicionar cartas a essa pilha,
// eu ainda nn consegui fazer isso pq eu não lembro como q usa uma classe dentro da
// outra. Talvez no meu almoço na quarta-feira eu consiga resolver isso. - Leo

class Pilha{
    public:
    Pilha(); // A função construtora já cria a pilha, não é necessário uma função p/ inicializar
    ~Pilha(); // Função destrutora
    void Push(); // Adiciona uma carta
    void Pop(); // Remove uma carta
    bool Full(); // Avisa se a pilha está cheia
    void Display(); // Imprime o gráfico da pilha

    private:
    int top;
    int Entry[MAXSTACK+1];
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