#include <iostream>
using namespace std;
#include<cstring>
#include<locale>

#define MAX 3000
#define NC 50

struct livro {
    char titulo[NC];
    char genero[NC];
    float preco;
  };
typedef struct livro TipoLivro;

int main(){
    int i, res=0 , n=0;
    float menor=0;

    TipoLivro livros[MAX];
    TipoLivro oferta[1];

    do{
        cout << "Titulo: ";
        cin.getline(livros[n].titulo, NC);
        cout << "Genero: ";
        cin.getline(livros[n].genero, NC);
        cout << "Preco: ";
        cin >> livros[n].preco;
        n++;
        cout <<"Deseja cadastrar mais um livro? (1-sim/2-não)";
        cin >> res;
        cin.ignore();
    } while(n<MAX && res == 1);

    cout << "Todos livros cadastrados: " << endl;
    for (i=0; i<n; i++) {
        cout << livros[i].titulo << endl;
        cout << livros[i].genero << endl;
        cout << livros[i].preco << endl;

        if (livros[i].preco < menor){
            menor = livros[i].preco;
            strcpy(oferta[1].titulo, livros[i].titulo);
            oferta[1].preco = livros[i].preco;
            strcpy(oferta[1].genero, livros[i].genero);
        }}

    cout << "\n Livros policiais com preço até R$40,00\n";
    for (i=0; i<n; i++){

        if (livros[i].preco< 40 && livros[i].genero == "Policial"){
        cout << livros[i].titulo << endl;
        cout << livros[i].genero << endl;
        cout << livros[i].preco << endl;
        }}

        cout << "A melhor oferta é:" << endl;
        cout << oferta[1].titulo << endl;
        cout << oferta[1].genero << endl;
        cout << oferta[1].preco << endl;


    return 0;
}


