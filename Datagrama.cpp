#include "Datagrama.h"
#include <iostream>
#include <string>
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

int Datagrama::getOrigem() {
    return origem;
}

int Datagrama::getDestino() {
    return destino;
}

int Datagrama::getTtl() {
    return ttl;
}

string Datagrama::getDado() {
    return dado;
}

void Datagrama::processar() {
    ttl--;
}

bool Datagrama::ativo() {
    if (ttl>0) return true;
    return false;
}

void Datagrama::imprimir() {
    cout << ttl << endl;
}
