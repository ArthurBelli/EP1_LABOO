#include "Datagrama.h"
#include <iostream>

using namespace std;

Datagrama::Datagrama(int origem, int destino, int ttl, string dado) {
    this->origem = origem;
    this->destino = destino;
    this->ttl = ttl;
    this->dado = dado;

}

Datagrama::~Datagrama() {
    cout << "Datagrama destruido" << endl;
}

Datagrama::int getOrigem() {
    return origem;
}

Datagrama::int getDestino() {
    return destino;
}

Datagrama::int getTtl() {
    return ttl;
}

Datagrama::string getDado() {
    return dado;
}

Datagrama::void processar() {
    ttl--;
    return ttl;
}

Datagrama::bool ativo() {
    if (ttl>0) return true;
    return false;
}

Datagrama::void imprimir() {
    cout << ttl << endl;
}
