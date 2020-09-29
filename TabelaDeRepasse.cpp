#include "TabelaDeRepasse.h"
#include "Roteador.h"
#define MAXIMO_TABELA 5
#include <iostream>

using namespace std;
class Roteador;

TabelaDeRepasse::TabelaDeRepasse() {
    vetRot = new Roteador*[MAXIMO_TABELA];
    vetEnd = new int[MAXIMO_TABELA];
    rotPadrao = NULL;
    for (int i = 0; i < MAXIMO_TABELA; i++) {
        vetRot[i] = NULL;
        vetEnd[i] = 0;
    } // vetores ao serem criados ficam [NULL, NULL, NULL, ...] e [0,0,0,..] respectivamente
}

TabelaDeRepasse::~TabelaDeRepasse() {
    delete[] vetRot;
    delete[] vetEnd;
}

bool TabelaDeRepasse::mapear(int endereco, Roteador* adjacente) {
    int i = 0;
    while (vetRot[i] != NULL && vetEnd[i] != 0) {
        i++;
        if (i == MAXIMO_TABELA) {
            cout << "Erro no mapeamento: tabela cheia" << endl;
            return false;
        }
    }
    if ((vetRot[i] == NULL && vetEnd[i] != 0) || (vetRot[i] != NULL && vetEnd[i] == 0)) {
        cout << "Erro no mapeamento: vetores desalinhados" << endl;
        return false;
    } else {
        vetRot[i] = adjacente;
        vetEnd[i] = endereco;
        return true;
    }
}

Roteador** TabelaDeRepasse::getAdjacentes() {
    Roteador** adjacentes;
    int quantAdj = this->getQuantidadeDeAdjacentes();
    adjacentes = new Roteador*[quantAdj];
    for (int i = 0; i < quantAdj; i++) adjacentes[i] = vetRot[i];
    return adjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes() {
    int contOcupado = 0; //contador de quantas casas ocupadas tem no vetor
    for (int i = 0; i < MAXIMO_TABELA; i++) {
        if (vetRot[i] != NULL) contOcupado++;
    }
    return contOcupado;
}

void TabelaDeRepasse::setPadrao(Roteador* padrao) {
    rotPadrao = padrao;
}

Roteador* TabelaDeRepasse::getDestino(int endereco) {
    int i;
    int k = -1;
    for (i = 0; i < MAXIMO_TABELA; i++) {
        if (endereco == vetEnd[i]) k = i;
    }
    if (k != -1) return vetRot[k];
    else return rotPadrao;
}

void TabelaDeRepasse::imprimir() {
    Roteador** adjacentes = this->getAdjacentes();
    int quantAdj,i;
    quantAdj = this->getQuantidadeDeAdjacentes();
    cout << "vetRot: {";
    for (i=0; i<MAXIMO_TABELA; i++) cout << vetRot[i] <<", ";
    cout << "}"<<endl;
    cout << "vetEnd: {";
    for (i=0; i<MAXIMO_TABELA; i++) cout << vetEnd[i] <<", ";
    cout << "}"<< endl;
}
