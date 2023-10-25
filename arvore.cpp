#include <iostream>

using namespace std;

struct NoArvore{
	int data;
	NoArvore *esquerda;
	NoArvore *direita;
	};
	
void imprimir (NoArvore *raiz){
	if (raiz != NULL){
		cout << raiz -> data << " ";
		imprimir (raiz -> esquerda);
		imprimir (raiz -> direita);
	}
};

int main(int argc, char** argv) {
	NoArvore *raiz = new NoArvore;
	raiz -> data = 1;
	raiz -> esquerda = NULL;
	raiz -> direita = NULL;
	
	NoArvore *elementoEsquerda = new NoArvore;
	elementoEsquerda -> data = 2;
	elementoEsquerda -> esquerda = NULL;
	elementoEsquerda -> direita = NULL;
	
	NoArvore *elementoDireita = new NoArvore;
	
	elementoDireita -> data = 3;
	elementoDireita -> esquerda = NULL;
	elementoDireita -> direita = NULL;
	
	raiz -> esquerda = elementoEsquerda;
	raiz -> direita = elementoDireita;
	
	NoArvore *elementoEsquerda2 = new NoArvore;
	
	elementoEsquerda2  -> data = 4;
	elementoEsquerda2  -> esquerda = NULL;
	elementoEsquerda2  -> direita = NULL;
	
	NoArvore *elementoDireita2 = new NoArvore;
	
	elementoDireita2  -> data = 5;
	elementoDireita2  -> esquerda = NULL;
	elementoDireita2 -> direita = NULL;
	
	elementoEsquerda -> esquerda = elementoEsquerda2;
	elementoEsquerda -> direita = elementoDireita2;
	
	NoArvore *elementoEsquerda3 = new NoArvore;
	
	elementoEsquerda3  -> data = 6;
	elementoEsquerda3  -> esquerda = NULL;
	elementoEsquerda3  -> direita = NULL;
	
	elementoDireita -> esquerda = elementoEsquerda3;
	
	imprimir (raiz);
	return 0;
}
