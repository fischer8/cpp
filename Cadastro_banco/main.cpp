#include <iostream>
using namespace std;
#include<cstring>
#include<locale>

#define NC  30

struct cliente {
      char nome[NC];
      char endereco[NC];
      char cpf[NC];
      int num_conta, ano_abertura;
      float saldo;
  };
typedef struct cliente Tipo_Cliente;

int main() {
    setlocale(LC_ALL,"");
    Tipo_Cliente cliente;
    cout << "Nome: ";
    cin.getline(cliente.nome, NC);
    cout << "Endereço: ";
    cin.getline(cliente.endereco, NC);
    cout << "CPF: ";
    cin.getline(cliente.cpf, NC);
    cout << "Número da conta: ";
    cin >> cliente.num_conta;
    cout << "Ano de abertura da conta: ";
    cin >> cliente.ano_abertura;
    cout << "Saldo da conta: R$";
    cin >> cliente.saldo;

    cout << "\n\n **** Apresentação do Cliente do Banco ****\n ";
    cout << "\t Nome: " << cliente.nome << endl;
    cout << "\t Endereço: " << cliente.endereco << endl;
    cout << "\t CPF: " << cliente.cpf << endl;
    cout << "\t Número da Conta: " << cliente.num_conta << endl;
    cout << "\t Ano de abertura da conta: " << cliente.ano_abertura << endl;
    cout.precision(2);
    cout << "\t Saldo: " << fixed<< cliente.saldo << endl;
return 0;
}

