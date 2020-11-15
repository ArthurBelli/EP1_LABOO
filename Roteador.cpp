#include "Fila.h"
#include "Roteador.h"
#include "Datagrama.h"
#include "TabelaDeRepasse.h"
#define TAMANHO_FILA 3
#include <iostream>
#include <string>

using namespace std;

Roteador::Roteador(int endereco) {
   this->endereco = endereco;
   fila = new Fila(TAMANHO_FILA);
   tabela = new TabelaDeRepasse();
   chegouDestino = false;
}

Roteador::~Roteador() {
   delete fila;
   delete tabela;
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
    if (!fila->isEmpty()) {
        Datagrama *atual = new Datagrama(0,0,1,""); /*escrito com qualquer coisa só pra alocar dinamicamente*/
        atual = fila->dequeue();
        atual->processar();
        cout << "Roteador " << this->getEndereco() << endl;
        if(!atual->ativo()) {
            cout << "\tDestruido por TTL: Origem: " << atual->getOrigem() << ", Destino: " << atual->getDestino() << ", TTL: " << atual->getTtl()  << ", " << atual->getDado() << endl;
            delete atual;
        }
        else {
            if(atual->getDestino() == endereco) {
                ultimoDadoRecebido = atual->getDado();
                chegouDestino = true;
                cout << "\tRecebido: " << ultimoDadoRecebido << endl;
                delete atual;
            }
            else {
                if (tabela->getDestino(atual->getDestino()) != NULL) {
                    cout << "\tEnviado para " << tabela->getDestino(atual->getDestino())->getEndereco() << " Origem: " << atual->getOrigem() << ", Destino: " << atual->getDestino() << ", TTL: " << atual->getTtl() << ", " << atual->getDado() << endl;
                    tabela->getDestino(atual->getDestino())->receber(atual);
                }
                else cout << "Defina o roteador padrão!" << endl;
            }
        }
    }
}

string Roteador::getUltimoDadoRecebido() {
    if(fila->isEmpty() && !chegouDestino) return "";
    else return ultimoDadoRecebido;
}

void Roteador::imprimir() {
    cout << "roteador" << endl;
}

