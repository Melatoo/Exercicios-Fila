#include <iostream>

using namespace std;

//definir uma fila por encadeamento usando classes

class No {
    public:
        int dado;
        No *prox;
};

class Fila {
    private:
        No *inicio;
        No *fim;
        int tamanho;
    public:
        Fila();
        ~Fila();
        void insere(int valor);
        int remove();
        bool vazia();
        int getInicio();
        int getTamanho();
};

Fila::Fila () {
    inicio = NULL;
    fim = NULL;
}
//definir ~fila
Fila::~Fila () {
    No *aux;
    while (inicio != NULL) {
        aux = inicio;
        inicio = inicio->prox;
        delete aux;
    }
    fim = NULL;
}
//definir as funcoes da fila
void Fila::insere (int valor) {
    No *novo = new No();
    novo->dado = valor;
    novo->prox = NULL;
    if (vazia ()) {
        inicio = novo;
    } else {
        fim->prox = novo;
    }
    fim = novo;
    tamanho++;
}
//funcao para remover um elemento da fila
int Fila::remove () {
    if (vazia()) {
        return -1;
    }
    No *aux = inicio;
    int valor = aux->dado;
    inicio = aux->prox;
    delete aux;
    tamanho--;
    return valor;
} 
//funcao para verificar se a fila esta vazia
bool Fila::vazia () {
    return (inicio == NULL);
}
//funcao para retornar o inicio da fila
int Fila::getInicio () {
    if (vazia()) {
        return -1;
    }
    return inicio->dado;
}

int Fila::getTamanho () {
    return tamanho;
}

int main () {
    //primeiro vou receber o tamanho da fila
    int n, m, valor, tam;
    cin >> n;
    //criar a fila
    Fila fila1, fila2;
    //inserir os elementos na fila
    for (int i = 0; i < n; i++) {
        cin >> valor;
        fila1.insere(valor);
    }
    //receber o tamanho da fila 2
    cin >> m;
    //inserir os elementos na fila 2
    for (int i = 0; i < m; i++) {
        cin >> valor;
        fila2.insere(valor);
    }
    //remover os elementos da fila que sejam iguais a algum elemento da fila 2

    //imprimir a fila 1
    tam = fila1.getTamanho();
    for (int i = 0; i < tam; i++) {
        cout << fila1.remove() << " ";
    }
    return 0;
}