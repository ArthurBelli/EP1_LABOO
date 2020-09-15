#ifndef FILA_H
#define FILA_H
#include "Datagrama.h"

class Fila(int tamanho) {
private:
    //incluir
public:
    Fila(int tamanho);
    ~Fila();
    bool enqueue(Datagrama* d);
    Datagrama* dequeue();
    bool isEmpty();

    void imprimir();
}

#endif // FILA_H
