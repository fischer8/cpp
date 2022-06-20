/*
Tiago Toledo Oliveira – RM88070
Henrique Fischer Ruiz – RM87352
Renan Honda Espirito Santo – RM89196
Rodrigo Yuji Sakaguchi – RM88010
*/

#include <iostream>
using namespace std;
#include<cstring>
#include<locale>
#define NP 9
#define NC 100

struct projeto {
      string URL[NC];
      string CPF[NP];
      float media[NP], avaliador1[NP], avaliador2[NP], avaliador3[NP];
  };
typedef struct projeto projetos;

int main() {
    setlocale(LC_ALL,"");
    projetos projetos[NP];
    float a1, a2, a3, maior=0;
    int i, a, n=0, resp=0, index1;

    do{
        cout << "\n Informe o CPF para o projeto " << n << endl;
        cin >> projetos[n].CPF[n];
        cout << "Informe a URL: " << endl;
        cin >> projetos[n].URL[n];
        n++;
        if (n<NP){
        cout <<"\n Deseja cadastrar mais um projeto? (1-sim/2-não)";
        }
        cin >> resp;
        cin.ignore();
        a=n;
    } while(n<NP && resp == 1);
    n=0;
    cout << "\n Vamos cadastrar as notas \n" << endl;
    do{
        cout << "Nota 1 do projeto " << n << endl;
        cin >> projetos[n].avaliador1[n];
        cout << "Nota 2 do projeto " << n << endl;
        cin >> projetos[n].avaliador2[n];
        cout << "Nota 3 do projeto " << n << endl;
        cin >> projetos[n].avaliador3[n];

        a1 = projetos[n].avaliador1[n];
        a2 = projetos[n].avaliador2[n];
        a3 = projetos[n].avaliador3[n];

        projetos[n].media[n]=(a1+a2+a3)/3;

        n++;
        if (n<a){
        cout <<"Deseja cadastrar mais uma nota? (1-sim/2-não) \n";
        cin >> resp;
        cin.ignore();
        }

    } while (n<a && resp == 1);

    for (i=0; i<a; i++){
        cout << "\n Média do projeto " << i << endl;
        cout << projetos[i].media[i] << endl;
    }

    for (i=0; i<n; i++){
        if (projetos[i].media[i] > maior){
            maior = projetos[i].media[i];
            index1 = i;
        }
    }

    cout << "\n Projeto com a maior nota: " << endl;
    cout << "\n Projeto " << index1 << " Com nota média de " << projetos[index1].media[index1] << endl;
    cout << "CPF " << projetos[index1].CPF[index1] << endl;
    cout << "URL " << projetos[index1].URL[index1] << endl;

return 0;
}


