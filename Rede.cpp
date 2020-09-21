#include "Rede.h"
#include "Roteador.h"
#include <iostream>
#include <string>

Rede::Rede(Roteador** roteadores, int quantidadeDeRoteadores) {
    this->quantidadeDeRoteadores = quantidadeDeRoteadores;
    rot = new Roteador*[quantidadeDeRoteadores];
    rot = roteadores;
}

Rede::~Rede() {
    delete[] rot;
}

Roteador* Rede::getRoteador(int endereco) {
    for(int i = 0; i < quantidadeDeRoteadores; i++)
        if (rot[i]->getEndereco() == endereco) return rot[i];
    return NULL;
}

void Rede::enviar(string texto, Roteador* origem, int destino, int ttl) {
    Datagrama* msg = new Datagrama(origem->getEndereco(), destino, ttl, texto);
    origem->receber(msg);
}

void Rede::passarTempo() {
    for(int i = 0; i< quantidadeDeRoteadores; i++) rot[i]->processar();
}

void Rede::imprimir() {
    //implementar
}
