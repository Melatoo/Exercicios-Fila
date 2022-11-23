#include <iostream>
#include <string>

using namespace std;

class Noh {
        friend class Fila;
        private:
            string dado; // poderia ser outro tipo de variável
            Noh *proximo;
        public:
            Noh(string info){
                dado = info;
                proximo = NULL;
            }
            ~Noh(){
                proximo = NULL;
                delete proximo;
            }
    };

// fila dinamicamente encadeada
class Fila {
    private:
        Noh* inicio;
        int tamanho;
    
    public:
        Fila();
        ~Fila();
        void enfileira(string info);
        string desenfileira();
        bool estaVazia(); // verifica se existem elementos na fila     
};


Fila::Fila() {
// IMPLEMENTE O CONSTRUTOR
    inicio = NULL;
    tamanho = 0;
}

Fila::~Fila() { 
// IMPLEMENTE O DESTRUTOR
    Noh* aux;
    while(inicio != NULL){
        aux = inicio;
        inicio = inicio->proximo;
        delete aux;
    }
    tamanho = 0;

}


void Fila::enfileira(string info) {
    //IMPLEMENTAR A INSERÇÃO DE UM ELEMENTO NA FILA
    Noh* novo = new Noh(info);
    if (estaVazia()){
        inicio = novo;
    } else {
        Noh* aux = inicio;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
    tamanho++;
}

string Fila::desenfileira() {  
    //IMPLEMENTAR A RETIRADA DE UM ELEMENTO NA FILA
    if (estaVazia()){
        return "Fila vazia";
    } else {
        Noh* aux = inicio;
        string valor = aux->dado;
        inicio = aux->proximo;
        delete aux;
        tamanho--;
        return valor;
    }
}
    
bool Fila::estaVazia() {
    //IMPLEMENTAR A VERIFICAÇÃO SE A FILA ESTÁ VAZIA
    if (tamanho == 0){
        return true;
    } else {
        return false;
    }
}

int main () {
    int n;
    cin >> n;
    Fila fila1;
    string i = "1";
    fila1.enfileira(i);
    //utilize a fila para gerar numeros binarios de 1 a n
    for (int i = 0; i < n; i++){
        string aux = fila1.desenfileira();
        cout << aux << endl;
        fila1.enfileira(aux + "0");
        fila1.enfileira(aux + "1");
    }
    return 0;
    

}