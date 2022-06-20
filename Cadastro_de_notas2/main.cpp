#include <iostream>
using namespace std;
#include <cstring>
#include <locale>
#define NP 10
#define NC 100
#define QT 4

struct componentes
{
  int CPF[NP];
  string nome[NC];
};

struct projeto
{
  string nomeDoProjeto[NC], URL[NC];
  float media[NP], avaliador1[NP], avaliador2[NP], avaliador3[NP], investimento[NC];
  struct componentes componente[QT];
};
typedef struct projeto projetoss;

void bubbleSort(projetoss projetos[NP], int NN)
{
  for (int i = 0; i < NN; i++)
  {
    for (int l = 0; l < (NN - i - 1); l++)
    {
      if (projetos[l].investimento[l] > projetos[l + 1].investimento[l + 1])
      {
        string temp1 = projetos[l].nomeDoProjeto[l];
        projetos[l].nomeDoProjeto[l] = projetos[l + 1].nomeDoProjeto[l + 1];
        projetos[l + 1].nomeDoProjeto[l + 1] = temp1;

        temp1 = projetos[l].URL[l];
        projetos[l].URL[l] = projetos[l + 1].URL[l + 1];
        projetos[l + 1].URL[l + 1] = temp1;

        float temp2 = projetos[l].media[l];
        projetos[l].media[l] = projetos[l + 1].media[l + 1];
        projetos[l + 1].media[l + 1] = temp2;

        temp2 = projetos[l].avaliador1[l];
        projetos[l].avaliador1[l] = projetos[l + 1].avaliador1[l + 1];
        projetos[l + 1].avaliador1[l + 1] = temp2;

        temp2 = projetos[l].avaliador2[l];
        projetos[l].avaliador2[l] = projetos[l + 1].avaliador2[l + 1];
        projetos[l + 1].avaliador2[l + 1] = temp2;

        temp2 = projetos[l].avaliador3[l];
        projetos[l].avaliador3[l] = projetos[l + 1].avaliador3[l + 1];
        projetos[l + 1].avaliador3[l + 1] = temp2;

        temp2 = projetos[l].investimento[l];
        projetos[l].investimento[l] = projetos[l + 1].investimento[l + 1];
        projetos[l + 1].investimento[l + 1] = temp2;

        int temp3 = projetos[l].componente->CPF[l];
        projetos[l].componente->CPF[l] = projetos[l + 1].componente->CPF[l + 1];
        projetos[l + 1].componente->CPF[l + 1] = temp3;

        string temp4 = projetos[l].componente->nome[l];
        projetos[l].componente->nome[l] = projetos[l + 1].componente->nome[l + 1];
        projetos[l + 1].componente->nome[l + 1] = temp4;
      }
    }
  }
};

int main()
{
  setlocale(LC_ALL, "");
  projetoss projetos[NP];

  float a1, a2, a3, maior = 0;
  int i, a, n = 0, j = 0, m = 0, resp = 0, index1, index2 = 0, NN = 0, escolha = 0;

  do
  {
    NN++;
    cout << "\n Informe o nome para o projeto " << n << endl;
    cin >> projetos[n].nomeDoProjeto[n];
    cout << "Informe a URL: " << endl;
    cin >> projetos[n].URL[n];
    cout << "\n Informe o investimento para o projeto " << projetos[n].nomeDoProjeto[n] << endl;
    cin >> projetos[n].investimento[n];

    cout << "Informe a nota 1 do projeto " << projetos[n].nomeDoProjeto[n] << endl;
    cin >> projetos[n].avaliador1[n];
    cout << "Informe a nota 2 do projeto " << projetos[n].nomeDoProjeto[n] << endl;
    cin >> projetos[n].avaliador2[n];
    cout << "Informe a nota 3 do projeto " << projetos[n].nomeDoProjeto[n] << endl;
    cin >> projetos[n].avaliador3[n];

    a1 = projetos[n].avaliador1[n];
    a2 = projetos[n].avaliador2[n];
    a3 = projetos[n].avaliador3[n];

    projetos[n].media[n] = (a1 + a2 + a3) / 3;

    do
    {
      cout << "\n Informe o CPF do componente " << j << endl;
      cin >> projetos[n].componente->CPF[j];
      cout << "\n Informe o nome do componente " << j << endl;
      cin >> projetos[n].componente->nome[j];
      j++;
      m++;
      cout << "\nDeseja cadastrar mais um componente? (1-sim/2-não) \n";
      cin >> resp;
    } while (resp == 1);
    j = 0;

    if (m < 4)
    {
      for (int i = 0; i < m; i++)
      {
        projetos[n].componente->CPF[i] = 0;
      }
    }

    n++;
    if (n < NP)
    {
      cout << "\n Deseja cadastrar mais um projeto? (1-sim/2-não)";
    }
    cin >> resp;
    cin.ignore();
    a = n;
  } while (n < NP && resp == 1);

  for (i = 0; i < a; i++)
  {
    cout << "\nNome do projeto: " << projetos[i].nomeDoProjeto[i] << endl;
    cout << "Media: " << projetos[i].media[i];
  }

  bubbleSort(projetos, NN);

  for (int i = 0; i < 5; i++)
  {
    projetos[i].media[i] += 0.5;
    if (projetos[i].media[i] > 10)
    {
      projetos[i].media[i] = 10;
    }
  }

  cout << endl
       << "\n\nDepois de adicionar meio ponto:";
  for (i = 0; i < a; i++)
  {
    cout << "\nNome do projeto: " << projetos[i].nomeDoProjeto[i] << endl;
    cout << "Media: " << projetos[i].media[i];
  }

  for (i = 0; i < n; i++)
  {
    if (projetos[i].media[i] == maior)
    {
      index2 = i;
    }
    else if (projetos[i].media[i] > maior)
    {
      maior = projetos[i].media[i];
      index1 = i;
    }
  }

  if (index2 > 0)
  {
    cout << "\n\nMais de uma maior nota detectada por favor dê o voto de minerva:";
    cout << "\nProjeto " << projetos[index1].nomeDoProjeto[index1] << "/ Média: " << projetos[index1].media[index1] << endl;
    cout << "Url: " << projetos[index1].URL[index1] << endl;
    cout << "Investimento: " << projetos[index1].investimento[index1];
    cout << "\nNota 1: " << projetos[index1].avaliador1[index1];
    cout << "\nNota 2: " << projetos[index1].avaliador2[index1];
    cout << "\nNota 3: " << projetos[index1].avaliador3[index1];
    cout << "\n\n";
    cout << "\nProjeto " << projetos[index2].nomeDoProjeto[index2] << "/ Média: " << projetos[index2].media[index2] << endl;
    cout << "Url: " << projetos[index2].URL[index2] << endl;
    cout << "Investimento: " << projetos[index2].investimento[index2];
    cout << "\nNota 1: " << projetos[index2].avaliador1[index2];
    cout << "\nNota 2: " << projetos[index2].avaliador2[index2];
    cout << "\nNota 3: " << projetos[index2].avaliador3[index2];

    cout << "\n\n\nDigite 1 para escolher o projeto " << projetos[index1].nomeDoProjeto[index1] << endl
         << " ou 2 para escolher o projeto " << projetos[index2].nomeDoProjeto[index2] << endl;
    cin >> escolha;
  }
  else
  {
    cout << "\nProjeto com a maior nota: " << endl;
    cout << "\nProjeto " << projetos[index1].nomeDoProjeto[index1] << "/ Média: " << projetos[index1].media[index1] << endl;
    cout << "Url: " << projetos[index1].URL[index1] << endl;
    cout << "Investimento: " << projetos[index1].investimento[index1];
    cout << "\nNota 1: " << projetos[index1].avaliador1[index1];
    cout << "\nNota 2: " << projetos[index1].avaliador2[index1];
    cout << "\nNota 3: " << projetos[index1].avaliador3[index1];
    cout << "\nCPF do componente 1 :" << projetos[index1].componente->CPF[index1];
    cout << "\nCPF do componente 2 :" << projetos[index1].componente->CPF[index1 + 1];
    cout << "\nCPF do componente 3 :" << projetos[index1].componente->CPF[index1 + 2];
    cout << "\nCPF do componente 4 :" << projetos[index1].componente->CPF[index1 + 3];
    return 0;
  }
  if (escolha == 1)
  {
    cout << "\nProjeto com a maior nota: " << endl;
    cout << "\nProjeto " << projetos[index1].nomeDoProjeto[index1] << "/ Média: " << projetos[index1].media[index1] << endl;
    cout << "Url: " << projetos[index1].URL[index1] << endl;
    cout << "Investimento: " << projetos[index1].investimento[index1];
    cout << "\nNota 1: " << projetos[index1].avaliador1[index1];
    cout << "\nNota 2: " << projetos[index1].avaliador2[index1];
    cout << "\nNota 3: " << projetos[index1].avaliador3[index1];
    cout << "\nCPF do componente 1 :" << projetos[index1].componente->CPF[index1];
    cout << "\nCPF do componente 2 :" << projetos[index1].componente->CPF[index1 + 1];
    cout << "\nCPF do componente 3 :" << projetos[index1].componente->CPF[index1 + 2];
    cout << "\nCPF do componente 4 :" << projetos[index1].componente->CPF[index1 + 3];
  }
  else if (escolha == 2)
  {
    cout << "\nProjeto " << projetos[index2].nomeDoProjeto[index2] << "/ Média: " << projetos[index2].media[index2] << endl;
    cout << "Url: " << projetos[index2].URL[index2] << endl;
    cout << "Investimento: " << projetos[index2].investimento[index2];
    cout << "\nNota 1: " << projetos[index2].avaliador1[index2];
    cout << "\nNota 2: " << projetos[index2].avaliador2[index2];
    cout << "\nNota 3: " << projetos[index2].avaliador3[index2];
    cout << "\nCPF do componente 1 :" << projetos[index2].componente->CPF[index2];
    cout << "\nCPF do componente 2 :" << projetos[index2].componente->CPF[index2 + 1];
    cout << "\nCPF do componente 3 :" << projetos[index2].componente->CPF[index2 + 2];
    cout << "\nCPF do componente 4 :" << projetos[index2].componente->CPF[index2 + 3];
  }
  return 0;
}
