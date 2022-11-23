#include <iostream>

using namespace std;

class No {
    friend class Fila;
    private:
        int dado;
        No *prox;
    public:
        No(int valor) {
            dado = valor;
            prox = NULL;
        }
        ~No() {
            prox = NULL;
            delete prox;
        }
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
        int getTamanho();
        int getInicio();
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
    No *novo = new No(valor);
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
    return inicio->dado;
}

int main () {
    int n, m, a, ultimoNum;
    cin >> n;
    Fila fila1, fila2, fila3;
    for (int i = 0; i < n; i++) {
        cin >> a;
        fila1.insere(a);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a;
        fila2.insere(a);
    }
    //fila 3 vai receber os elementos da fila 1 e 2 em ordem crescente e sem repetir elemento
    while (!fila1.vazia() && !fila2.vazia()) {
        if (fila1.getInicio() < fila2.getInicio()) {
            if (fila1.getInicio() != ultimoNum) {
                fila3.insere(fila1.getInicio());
                ultimoNum = fila1.getInicio();
            } else {
                fila1.remove();
            }
        } else if (fila1.getInicio() > fila2.getInicio()) {
            if (fila2.getInicio() != ultimoNum) {
                fila3.insere(fila2.getInicio());
                ultimoNum = fila2.getInicio();
            } else {
                fila2.remove();
            }
        } else {
            if (fila1.getInicio() != ultimoNum) {
                fila3.insere(fila1.getInicio());
                ultimoNum = fila1.getInicio();
            } else {
                fila1.remove();
            }
        }
    }
    while (!fila1.vazia()) {
        if (fila1.getInicio() != ultimoNum) {
            fila3.insere(fila1.getInicio());
            ultimoNum = fila1.getInicio();
        } else {
            fila1.remove();
        }
    }
    while (!fila2.vazia()) {
        if (fila2.getInicio() != ultimoNum) {
            fila3.insere(fila2.getInicio());
            ultimoNum = fila2.getInicio();
        } else {
            fila2.remove();
        }
    }
    //imprimir a fila 3
    while (!fila3.vazia()) {
        cout << fila3.remove() << " ";
    }
    return 0;
}