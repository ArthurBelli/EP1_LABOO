#include "Fila.h"
#include "Roteador.h"
#include "Datagrama.h"
#include "TabelaDeRepasse.h"
#define TAMANHO_FILA 3
#include <iostream>


Roteador::Roteador(int endereco) {
   this->endereco = endereco;
   fila = new Fila(TAMANHO_FILA);
   tabela = new TabelaDeRepasse();
}

Roteador::~Roteador() {
    fila->~Fila();
    tabela->~TabelaDeRepasse();
}

TabelaDeRepasse* Roteador::getTabela() {
    return tabela;
}

Fila* Roteador::getFila() {
    return fila;
}

int Roteador::getEndereco() {
    return endereco;
}

void Roteador::receber(Datagrama* d) {
    if (!fila->enqueue(d)) cout << "\tFila em " << endereco << " estourou" << endl;
}

void Roteador::processar() {
    Datagrama *atual = fila->dequeue();
    atual->processar();
    if(!fila->isEmpty()) {
        if(!atual->ativo()) atual->~Datagrama();
        else if(atual->getDestino() == endereco) {
            ultimoDadoRecebido = atual->getDado();
            atual->~Datagrama();
        } else {
            if(tabela->getDestino(atual->getDestino()) != NULL)
                tabela->getDestino(atual->getDestino())->receber(atual);
            else atual->~Datagrama();
        }
    }
}

string Roteador::getUltimoDadoRecebido() {
    if(fila->isEmpty()) return "";
    else return ultimoDadoRecebido;
}

void Roteador::imprimir() {
    //implementar
}
