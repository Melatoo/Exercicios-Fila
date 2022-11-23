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
        int getTamanho();  
        int getInicio();
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

int Fila::getTamanho() {
    return tamanho;
}

int Fila::getInicio() {
    return inicio->dado;
}

int main () {
    Fila A, B, C;
    int valor;
    char opcao, qualFila;
    while (opcao != 't') {
        cin >> opcao;
        //se a opcao for 'a', enfileira na fila que tambem vai ser recebida
        if (opcao == 'i') {
            cin >> qualFila >> valor;
            if (qualFila == 'a') {
                A.enfileira(valor);
            } else {
                B.enfileira(valor);
            }
        //se a opcao for 'e', imprime a fila que tambem vai ser recebida
        } else if (opcao == 'e') {
            int aux;
            cin >> qualFila;
            if (qualFila == 'a') {
                for (int i = 0; i < A.getTamanho(); i++) {
                    aux = A.getInicio();
                    cout << A.desenfileira() << " ";
                    A.enfileira(aux);
                }
                cout << endl;
            } else {
                for (int i = 0; i < B.getTamanho(); i++) {
                    aux = B.getInicio();
                    cout << B.desenfileira() << " ";
                    B.enfileira(aux);
                }
                cout << endl;
            } 
            //se a opcao for 'm', mescla as filas A e B em uma fila C de maneira ordenada, sem desmontar as filas A e B
        } else if (opcao == 'm') {
            int auxA, auxB;
            Fila auxA1, auxB1;
            while (!A.estaVazia() && !B.estaVazia()) {
                auxA = A.getInicio();
                auxB = B.getInicio();
                if (auxA < auxB) {
                    C.enfileira(A.desenfileira());
                    auxA1.enfileira(auxA);
                } else {
                    C.enfileira(B.desenfileira());
                    auxB1.enfileira(auxB);
                }
            }
            while (!A.estaVazia()) {
                auxA = A.getInicio();
                C.enfileira(A.desenfileira());
                auxA1.enfileira(auxA);
            }
            while (!B.estaVazia()) {
                auxB = B.getInicio();
                C.enfileira(B.desenfileira());
                auxB1.enfileira(auxB);
            }
            //destruir C depois de imprimir
            for (int i = 0; i < C.getTamanho(); i++) {
                cout << C.desenfileira() << " ";
            }
            //copiar auxA1 e auxB1 para A e B
            while (!auxA1.estaVazia()) {
                A.enfileira(auxA1.desenfileira());
            }
            while (!auxB1.estaVazia()) {
                B.enfileira(auxB1.desenfileira());
            }
        }
    }
    return 0;
}