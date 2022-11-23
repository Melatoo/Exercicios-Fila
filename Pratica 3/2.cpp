#include <iostream>

using namespace std;

class FilaCircular {
private:
	int mInicio;
	int mFim;
	int *mDados;
	unsigned mCapacidade;
	//tamanho aqui funciona para marcar posições ocupadas
	unsigned tamanho;
public:
	FilaCircular(int capacidade = 10);
	~FilaCircular();
	unsigned getTamanho();
	void enfileira(int valor);
	int desenfileira();
	bool vazia();
	void depura();
    int getCapacidade();
    int getInicio();
    int getFim();
};


//é chamado assim que eu crio um objeto do tipo pilha
FilaCircular::FilaCircular(int capacidade) {
	mInicio = -1;
	mFim = -1;
	mCapacidade = capacidade;
	mDados = new int[mCapacidade];
	tamanho = 0;
}
//precisa limpar tudo que foi feito
FilaCircular::~FilaCircular() {
	delete[] mDados;
}


unsigned FilaCircular::getTamanho() {
	return tamanho;
}

bool FilaCircular::vazia() {
	return (tamanho == 0);
}

void FilaCircular::enfileira(int valor) {
	if(tamanho <= mCapacidade) {
		mFim++;
		mFim = mFim % mCapacidade;
		mDados[mFim] = valor;
		if(tamanho == 0){
			mInicio++;
		}
		tamanho++;
	}else{
		cout << "Fila cheia, meu parceiro" << endl;
	}
}

int FilaCircular::desenfileira() {
	if (tamanho > 0) {
		int valor = mDados[mInicio];
		tamanho--;
		if (tamanho > 0) {
			mInicio++;
			mInicio = mInicio % mCapacidade;
		} else {
			mInicio = -1;
			mFim = -1;
		}
		return valor;
	} else {
		cerr << "Fila cheia, meu parceiro" << endl;
		return -1;
	}
}

void FilaCircular::depura() {
	for (unsigned i=0; i < tamanho; i++){
		cout << mDados[i] << " ";
	}
	cout << endl;
}

int FilaCircular::getCapacidade() {
    return mCapacidade;
}

int FilaCircular::getInicio() {
    return mInicio;
}

int FilaCircular::getFim() {
    return mFim;
}

int main () {
    char opcao;
    int valor, tam;
    cin >> tam;
    FilaCircular fila1(tam);
    while (opcao != 't') {
        cin >> opcao;
        if (opcao == 'e') {
            cin >> valor;
            fila1.enfileira(valor);
        } else if (opcao == 'd') {
            cout << fila1.desenfileira() << endl;
        } else if (opcao == 'i') {
            cout << "tamanho=" << fila1.getTamanho() << " capacidade=" << fila1.getCapacidade() << " inicio=" << fila1.getInicio() << " fim=" << fila1.getFim() << endl;
            //mostra os elementos da fila
            fila1.depura();
        }
    }

}

