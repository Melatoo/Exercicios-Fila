#include <iostream>
#include <string>

using namespace std;

class Noh {
        friend class Fila;
        private:
            int dado; // poderia ser outro tipo de variável
            Noh *proximo;
        public:
            Noh(int info){
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
        void enfileira(int info);
        int desenfileira();
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


void Fila::enfileira(int info) {
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

int Fila::desenfileira() {  
    //IMPLEMENTAR A RETIRADA DE UM ELEMENTO NA FILA
    if (estaVazia()){
        return -1;
    } else {
        Noh* aux = inicio;
        int valor = aux->dado;
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
    
    Fila fila1;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++){
        int valor;
        cin >> valor;
        fila1.enfileira(valor);
    }
    cin >> k;
    for (int i = 0; i < n; i++){
        int valor = fila1.desenfileira();
        if (valor < 0){
            cout << valor << endl;
            break;
        }
        if (i == k-1){
            cout << "inexistente" << endl;
            break;
        }
    }
}