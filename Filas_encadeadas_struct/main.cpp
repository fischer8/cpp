#include <iostream>
#include <stdlib.h>
#include <locale>
#include <cstring>
#include <string.h>
#include "FilaPedidos.h";

using namespace std;

#define NC 50
#define NClientes 100
#define N_Lojas 3

// structs definidas no arquivo FilaPedidos.h

TipoCliente atualiza_cliente(TipoCliente cliente) {
    int j = 0;
    while(j < 1 || j > 2){
        cout << "Seu bairro continua " << cliente.bairro << "? (1-sim/2-nao)";
        cin >> j;
        cin.ignore();
    }
    if(j == 1){
        return cliente;
    }
    if(j == 2){
        cout << "Digite o novo bairro: ";
        cin.getline(cliente.bairro, NC);
        return cliente;
    }

};

int localiza_loja(TipoLoja lojas[N_Lojas], char bairro[NC]) {
    int a = 0;
    for(a ; a < N_Lojas; a++) {
        if(strcmp(bairro, lojas[a].bairro) == 0){
            return a;
        }
    }
    return -1;
};

int procura_cliente(TipoCliente clientes[NClientes], char cpf[NC]) {
    int b = 0;
    for(b ; b< NClientes; b++) {
        if(strcmp(cpf, clientes[b].CPF) == 0 ){
            return b;
        }
    }
    return -1;
};



TipoMelhorPior melhor_pior_loja(TipoLoja lojas[N_Lojas]){
    int c = 0;
    TipoMelhorPior registro;

    for(c; c< N_Lojas; c++) {
        if(lojas[0].qtd_atendimento < lojas[c].qtd_atendimento){
            registro.melhor = lojas[c];
        }
        if(lojas[0].qtd_atendimento > lojas[c].qtd_atendimento){
            registro.pior = lojas[c];
        }
    }
    return registro;
};

int main()
{
    setlocale(LC_ALL, "");
    TipoLoja loja1 = {"Pompeia", 0};
    TipoLoja loja2 = {"Agua Branca",0};
    TipoLoja loja3 = {"Perdizes",0};
    TipoLoja lojas[N_Lojas] = {loja1,loja2,loja3};

    TipoFila ini1, fim1, ini2, fim2, ini3, fim3;
    init(&ini1, &fim1);
    init(&ini2, &fim2);
    init(&ini3, &fim3);

    TipoCliente clientes[NClientes];
    TipoMelhorPior registro;
    TipoPedido pedido;
    int n_clientes = 0, loja = -1, opcao, pos = 0, i;
    char bairro[NC], cpf[NC];

    do{
        cout << "\n\n**************** Sistema Atendimento ***************" << endl;
        cout << "\n 0- Sair\n 1- Recebe encomenda\n 2-Atender pedido \n";
        cout << " Digite opção: ";
        cin >> opcao;
        cin.ignore();
        switch(opcao){
            case 0:
                cout << "\n Atendendo as encomendas já encaminhadas para cada uma das lojas\n";
                show(ini1,fim1);
                show(ini2,fim2);
                show(ini3,fim3);
                cout << "\n Fechado o atendimento delivery...\n";
                break;
            case 1:
                cout << "Digite CPF do cliente: ";
                cin.getline(cpf,NC);
                if (n_clientes > 0){

                    pos = procura_cliente(clientes,cpf);

                    if (pos != -1){

                        TipoCliente cliente = clientes[pos];
                        clientes[pos] = atualiza_cliente(cliente);
                        pedido.cliente = clientes[pos];

                    }else{
                        cout << "Bairro: ";
                        cin.getline(clientes[n_clientes].bairro,NC);
                        strcpy(clientes[n_clientes].CPF,cpf);
                        pos = n_clientes;
                        n_clientes++;
                    }
                    }else{
                        strcpy(clientes[0].CPF,cpf);
                        cout << "Digite bairro: ";
                        cin.getline(clientes[0].bairro, NC);
                        pos = 0;
                        n_clientes++;
                    }
                pedido.cliente = clientes[pos];
                cout << "Faça seu pedido: ";
                cin.getline(pedido.encomenda,NC);

                strcpy(bairro, clientes[pos].bairro);
                loja = localiza_loja(lojas, bairro);

                switch (loja){

                    case 0:
                        enqueue(&ini1, &fim1, pedido);
                        cout << "Encomenda feita na unidade: " << lojas[loja].bairro<< endl;
                        lojas[loja].qtd_atendimento++;
                        break;
                    case 1:
                        enqueue(&ini2, &fim2, pedido);
                        cout << "Encomenda feita na unidade: " << lojas[loja].bairro<< endl;
                        lojas[loja].qtd_atendimento++;
                        break;
                    case 2:
                        enqueue(&ini3, &fim3, pedido);
                        cout << "Encomenda feita na unidade: " << lojas[loja].bairro<< endl;
                        lojas[loja].qtd_atendimento++;
                        break;
                    default:
                        cout << "\n *** Bairros atendidos pelo nosso delivery ***\n";
                        for (int i=0; i<N_Lojas;i++){
                            cout << lojas[i].bairro << endl;
                        }
                        cout << "Desculpe, ainda não entregamos em seu bairro \n";
                    }
                    break;
                case 2:
                    cout << "  Qual loja vai atender pedido agora?\n";
                    for (i=0; i<N_Lojas;i++){
                        cout << "\t" << i+1<< "] "<< lojas[i].bairro << endl;
                    }
                    cout << "Loja: ";
                    cin >> loja;

                    switch (loja){
                    case 1:
                        if(dequeue(&ini1, &fim1, &pedido)){
                            cout << "CPF: " << pedido.cliente.CPF << "\t Bairro: "<<pedido.cliente.bairro<<
                        "\n Encomenda: " << pedido.encomenda << endl;
                        }else{
                            cout << "Não há pedidos para essa loja \n";
                        }
                        break;
                    case 2:
                        if(dequeue(&ini2, &fim2, &pedido)){
                            cout << "CPF: " << pedido.cliente.CPF << "\t Bairro: "<<pedido.cliente.bairro<<
                        "\n Encomenda: " << pedido.encomenda << endl;
                        }else{
                            cout << "Não há pedidos para essa loja \n";
                        }
                        break;
                    case 3:
                        if(dequeue(&ini3, &fim3, &pedido)){
                            cout << "CPF: " << pedido.cliente.CPF << "\t Bairro: "<<pedido.cliente.bairro<<
                        "\n Encomenda: " << pedido.encomenda << endl;
                        }else{
                            cout << "Não há pedidos para essa loja \n";
                        }
                        break;
                    default:
                        cout << "Loja não existente\n";
                        break;
                    }
                default:
                    break;
                }
    }while (opcao!=0);
    registro = melhor_pior_loja(lojas);
    cout << "\n Finalizado ao atendimento de hoje\n";
    cout << "Loja com mais atendimentos hoje: " << registro.melhor.bairro << " com " << registro.melhor.qtd_atendimento << " atendimentos" << endl;
    cout << "Loja com menos atendimentos hoje: " << registro.pior.bairro << " com " << registro.pior.qtd_atendimento << " atendimentos"  << endl;

    return 0;
}
