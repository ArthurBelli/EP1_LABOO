#include "Datagrama.h"
#include "Fila.h"
#include "TabelaDeRepasse.h"
#include "Roteador.h"
#include "Rede.h"
#define QUANTIDADE_DE_ROTEADORES 6

#include <iostream>
#include <string>

using namespace std;

void Menu0(int &opcao);
void Menu1(int &origem, int &destino, int &ttl, string &mensagem);
void mensagensRoteadores(Roteador** vetRot);

int main() {
    /*setup da rede, dos roteadores e da tabela*/
    int i;
    Roteador** vetRot = new Roteador*[QUANTIDADE_DE_ROTEADORES];
    /*roteador, posicao no vetor e tabela do r1*/
    Roteador* r1 = new Roteador(1);
    vetRot[0] = r1;
    /*roteador, posicao no vetor e tabela do r2*/
    Roteador* r2 = new Roteador(2);
    vetRot[1] = r2;
    /*roteador, posicao no vetor e tabela do r3*/
    Roteador* r3 = new Roteador(3);
    vetRot[2] = r3;
    /*roteador, posicao no vetor e tabela do r4*/
    Roteador* r4 = new Roteador(4);
    vetRot[3] = r4;
    /*roteador, posicao no vetor e tabela do r5*/
    Roteador* r5 = new Roteador(5);
    vetRot[4] = r5;
    /*roteador, posicao no vetor e tabela do r6*/
    Roteador* r6 = new Roteador(6);
    vetRot[5] = r6;

    /*mapeamento das tabelas*/
    r1->getTabela()->mapear(4,r4);
    r1->getTabela()->setPadrao(r2);

    r2->getTabela()->mapear(1,r1);
    r2->getTabela()->mapear(3,r3);
    r2->getTabela()->setPadrao(r5);

    r3->getTabela()->mapear(6,r6);
    r3->getTabela()->setPadrao(r2);

    r4->getTabela()->mapear(1,r1);
    r4->getTabela()->setPadrao(r5);

    r5->getTabela()->mapear(4,r4);
    r5->getTabela()->mapear(6,r6);
    r5->getTabela()->setPadrao(r2);

    r6->getTabela()->mapear(3,r3);
    r6->getTabela()->setPadrao(r5);

    Rede* rede = new Rede(vetRot, QUANTIDADE_DE_ROTEADORES);





    int opcao=0;

    while (opcao != 3) {
        if (opcao == 0) Menu0(opcao);

        if (opcao == 1) {
            int origem, destino, ttl;
            string mensagem;
            Menu1(origem, destino, ttl, mensagem);
            if (rede->getRoteador(origem) == NULL) {
                cout << "Erro: origem desconhecida" << endl;
                opcao = 0;
            }
            rede->enviar(mensagem, rede->getRoteador(origem), destino, ttl);
            while (rede->getRoteador(destino)->getUltimoDadoRecebido() != mensagem) rede->passarTempo(); //esse while vai pra opcao 2 provavelmente (talvez n como while)






        } else {
            //magica 2
        }
    }
    return 0;
}

void Menu0(int &opcao) {
    cout << "Simulador de Rede" << endl;
    cout << "---" << endl;
    cout << "1) Enviar um datagrama" << endl;
    cout << "2) Passar tempo" << endl;
    cout << "3) Sair" << endl << "Esolha uma opcao: ";
    cin >> opcao;
}

void Menu1(int &origem, int &destino, int &ttl, string &mensagem) {
    cout << "Endereco do roteador de origem: " << endl;
    cin >> origem;
    cout << "Endereco de destino: " << endl;
    cin >> destino;
    cout << "TTL: " << endl;
    cin >> ttl;
    cout << "Mensagem: " << endl;
    cin >> mensagem;
}

void mensagensRoteadores(Roteador** vetRot) { //funcao de teste, pode apagar se quiser
    int i;
    for (i = 0; i<QUANTIDADE_DE_ROTEADORES; i++) {
        cout << "Roteador " << i+1 << ": " << vetRot[i]->getUltimoDadoRecebido() << endl;
    }

}