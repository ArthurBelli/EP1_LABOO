#include "Roteador.h"
#include "Datagrama.h"
#include "TabelaDeRepasse.h"

Roteador::Roteador(int endereco) {
    //ctor
}

Roteador::~Roteador() {
    //dtor
}

TabelaDeRepasse* Roteador::getTabela() {
    //implementar
}

Fila* Roteador::getFila() {
    //implementar
}

int Roteador::getEndereco() {
    //implementar
}

void Roteador::receber(Datagrama* d) {
    //implementar
}

void Roteador::processar() {
    //implementar
}

string Roteador::getUltimoDadoRecebido() {
    //implementar
}

void Roteador::imprimir() {
    //implementar
}
