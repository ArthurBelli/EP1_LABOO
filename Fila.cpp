#include "Fila.h"
#include "Datagrama.h"
using namespace std;

Fila::Fila(int tamanho) {
    this->tamanho = tamanho;
    inicio = 0;
    fim = 0;
    vetFila = new Datagrama*[tamanho+1]; //fila circular com uma posicao a mais que o permitido
}

Fila::~Fila() {
    delete[] vetFila;
}

bool Fila::enqueue(Datagrama* d) {
    if (inicio==fim+1 || (inicio==0 && fim==tamanho)) return false; //condicoes de fila cheia do video de alg
    vetFila[fim] = d;
    if (fim==tamanho) fim=0; //fila circular
    else fim++;
    return true;
}

Datagrama* Fila::dequeue() {
    if (this->isEmpty()) return NULL;
    Datagrama* retirada = vetFila[inicio];
    if (inicio == tamanho) inicio=0; // fila circular
    else inicio++;
    return retirada;
}

bool Fila::isEmpty() {
    if (inicio==fim) return true;
    else return false;
}

void Fila::imprimir() {
    //implementar
}
