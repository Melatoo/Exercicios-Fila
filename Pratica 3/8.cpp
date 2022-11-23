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
        int getTamanho();
        string getInicio();
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

int Fila::getTamanho() {
    return tamanho;
}

string Fila::getInicio() {
    if (estaVazia()){
        return "Fila vazia";
    } else {
        return inicio->dado;
    }
}

int main () {
    Fila carros, aux;
    char opcao;
    string carro;
    while (opcao != 'S') {
        cin >> opcao;
        if (opcao == 'E') {
            cin >> carro;
            carros.enfileira(carro);
        } // se a opcao for 'D' desenfileira o carro pedido e imprime a quantidade de carros que foram desenfileirados 
        else if (opcao == 'D') {
            cin >> carro;
            while (carros.getInicio() != carro) {
                aux.enfileira(carros.desenfileira());
            }
            carros.desenfileira();
            cout << aux.getTamanho() + 1 << endl;
            while (!aux.estaVazia()) {
                carros.enfileira(aux.desenfileira());
            }
            //imprimir carros da fila
            for (int i = 0; i < carros.getTamanho(); i++) {
                string carroAux = carros.desenfileira();
                cout << carroAux << endl;
                carros.enfileira(carroAux);
            }

        }


    }
}