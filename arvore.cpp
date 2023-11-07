#include <iostream>

using namespace std;

struct NoArvore{
	int data;
	NoArvore *esquerda;
	NoArvore *direita;
};
	
void preOrdem(NoArvore *raiz){
	if (raiz != NULL){
		cout << raiz -> data << " ";
		preOrdem (raiz -> esquerda);
		preOrdem (raiz -> direita);
	}
};

void emOrdem(NoArvore *raiz){
	if (raiz != NULL){
		emOrdem(raiz -> esquerda);
		cout << raiz -> data << " ";
		emOrdem(raiz -> direita);
	}
};

void posOrdem (NoArvore *raiz){
	if (raiz != NULL){
		posOrdem (raiz -> esquerda);
		posOrdem (raiz -> direita);
		cout << raiz -> data << " ";
	}
}

void destruirMemoria (NoArvore *raiz){
	if (raiz != NULL){
		destruirMemoria (raiz -> esquerda);
		destruirMemoria (raiz -> direita);
		raiz = NULL;
		delete raiz;
	}
}

void contadorESoma(NoArvore *raiz, float &contador, float &soma){
	if (raiz != NULL){
		contador ++;
		soma += raiz -> data;
		
		contadorESoma (raiz -> esquerda, contador, soma);
		contadorESoma (raiz -> direita, contador, soma);
	}
};

int main(int argc, char** argv) {
	
	float contador;
	float soma;
	float media;
	
	// pra ficar mais fácil pra eu entender, coloquei que a raiz é um, 
	//elemento a esquerda é 2, elemento a direita 3, etc
	
	cout << "Criando arvore binaria:";
	
	NoArvore *raiz = new NoArvore;
	raiz -> data = 2;
	raiz -> esquerda = NULL;
	raiz -> direita = NULL;
	
	NoArvore *elementoEsquerda = new NoArvore;
	elementoEsquerda -> data = 7;
	elementoEsquerda -> esquerda = NULL;
	elementoEsquerda -> direita = NULL;
	
	NoArvore *elementoDireita = new NoArvore;
	
	elementoDireita -> data = 5;
	elementoDireita -> esquerda = NULL;
	elementoDireita -> direita = NULL;
	
	raiz -> esquerda = elementoEsquerda;
	raiz -> direita = elementoDireita;
	
	NoArvore *elementoEsquerda2 = new NoArvore;
	
	elementoEsquerda2  -> data = 2;
	elementoEsquerda2  -> esquerda = NULL;
	elementoEsquerda2  -> direita = NULL;
	
	NoArvore *elementoDireita2 = new NoArvore;
	
	elementoDireita2  -> data = 6;
	elementoDireita2  -> esquerda = NULL;
	elementoDireita2 -> direita = NULL;
	
	elementoEsquerda -> esquerda = elementoEsquerda2;
	elementoEsquerda -> direita = elementoDireita2;
	
	NoArvore *elementoDireita3 = new NoArvore;
	
	elementoDireita3  -> data = 9;
	elementoDireita3  -> esquerda = NULL;
	elementoDireita3  -> direita = NULL;
	
	elementoDireita -> esquerda = elementoDireita3;
	
	NoArvore *elementoEsquerda5 = new NoArvore;
	
	elementoEsquerda5  -> data = 5;
	elementoEsquerda5  -> esquerda = NULL;
	elementoEsquerda5  -> direita = NULL;
	
	NoArvore *elementoDireita5 = new NoArvore;
	
	elementoDireita5  -> data = 11;
	elementoDireita5  -> esquerda = NULL;
	elementoDireita5 -> direita = NULL;
	
	elementoDireita2 -> esquerda = elementoEsquerda5;
	elementoDireita2 -> direita = elementoDireita5;
	
	NoArvore *elementoEsquerda6 = new NoArvore;
	
	elementoEsquerda6  -> data = 4;
	elementoEsquerda6  -> esquerda = NULL;
	elementoEsquerda6  -> direita = NULL;
	
	elementoDireita3 -> esquerda = elementoEsquerda6;
	
	cout << endl << "\nPre Ordem: ";
	preOrdem(raiz);
	cout << "\n\nEm Ordem: ";
	emOrdem(raiz);
	cout << "\n\nPos Ordem: ";
	posOrdem(raiz);
	
	contadorESoma(raiz, contador, soma);
	cout << "\n\nA arvore analisada tem " << contador << " elementos" << endl;
	cout << "\nA soma dos elementos desta arvore eh " << soma << endl;
	media = soma/contador;
	cout << "\nA media eh " << media;
	
	
	cout << "\nDestruindo Memoria";
	destruirMemoria(raiz);
	cout << endl << "\nPre Ordem: ";
	preOrdem(raiz);

	return 0;
}
