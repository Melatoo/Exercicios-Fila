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

int main() {
    Fila normal, prioridade;
    int i;
    string comando;
    string info;
    while (comando != "fim") {
        cin >> comando;
        //o comando normal enfileira na fila normal
        if (comando == "normal") {
            cin >> info;
            normal.enfileira(info);
        }
        //o comando prioridade enfileira na fila de prioridade
        else if (comando == "prioridade") {
            cin >> info;
            prioridade.enfileira(info);
        }
        //o comando atender atende pessoas normais apenas se tres prioridades ja foram atendidas, ou se nao houver prioridades
        else if (comando == "atender") {
            if (prioridade.estaVazia()) {
                cout << normal.desenfileira() << endl;
                i = 0;
            } else {
                if (i == 3) {
                    cout << normal.desenfileira() << endl;
                    i = 0;
                } else {
                    cout << prioridade.desenfileira() << endl;
                    if (i < 3) {
                        i++;
                    }
                }
            }
        }
    }
    return 0;
    
}