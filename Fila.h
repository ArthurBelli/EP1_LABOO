#ifndef FILA_H
#define FILA_H
#include "Datagrama.h"

class Fila {
private:
    int inicio, fim, tamanho;
    Datagrama **vetFila;
public:
    Fila(int tamanho);
    ~Fila();
    bool enqueue(Datagrama* d);
    Datagrama* dequeue();
    bool isEmpty();

    void imprimir();
}

#endif // FILA_H
