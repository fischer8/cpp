#include <iostream>
#include <locale>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

#define N_EMPRESAS 100
#define N_REGIOES 40
#define NC 30
#define NC_LINHA 120
#define N 40

/*******************************************************************
TAREFA 1
*******************************************************************/

struct empresa_estoques
{
    int codEmpresa, codRegiao;
    float papel, metal, vidro, plastico;
};
typedef struct empresa_estoques TipoEmpresas;

struct codigos_transporte
{
    char empresa_transporte[NC];
    int codRegiao;
};
typedef struct codigos_transporte TipoCodTransporte;

/*******************************************************************
TAREFA 2
********************************************************************/

int sequencial2(TipoEmpresas empresas[N_EMPRESAS], int input)
{
    int pos;
    for (int i = 0; i < 39; i++)
    {
        if (empresas[i].codEmpresa == input)
        {
            pos = i;
        }
    }
    return pos;
}

/******************************************************************************
TAREFA 3
*******************************************************************************/

void sequencial3(TipoEmpresas empresas[N_EMPRESAS])
{    cout << "\n\n\n\n" << endl;
    int cod;
    for (int i = 0; i < 38; i++)
    {
        if (empresas[i].papel >= 75)
        {
            cod = empresas[i].codEmpresa;
            cout << "Empresa cod:" << cod << " está cheia de papel \n";
        }
        if (empresas[i].metal >= 75)
        {
            cod = empresas[i].codEmpresa;
            cout << "Empresa cod:" << cod << " está cheia de metal \n";
        }
        if (empresas[i].vidro >= 75)
        {
            cod = empresas[i].codEmpresa;
            cout << "Empresa cod:" << cod << " está cheia de vidro \n";
        }
        if (empresas[i].plastico >= 75)
        {
            cod = empresas[i].codEmpresa;
            cout << "Empresa cod:" << cod << " está cheia de plastico \n";
        }
    }
}

/******************************************************************************
TAREFA 4
*******************************************************************************/

void bubbleSort(TipoEmpresas empresas[N_EMPRESAS], int material)
{
    int i, j;
    for (i = 37; i != 0; i--)
        for (j = 37; j != 0; j--)
            switch(material){
            case 1:
                if (empresas[j].metal > empresas[j - 1].metal){
                    swap(empresas[j - 1],empresas[j]);
                }
                break;
            case 2:
                if (empresas[j].plastico > empresas[j - 1].plastico){
                    swap(empresas[j - 1],empresas[j]);
                }
                break;
            case 3:
                if (empresas[j].papel > empresas[j - 1].papel) {
                    swap(empresas[j - 1],empresas[j]);
                }
                break;
            case 4:
                if (empresas[j].vidro > empresas[j - 1].vidro){
                    swap(empresas[j - 1],empresas[j]);
                }
                break;
            default:
                cout << "opcao invalida\n";
                break;
            }
    for (int i = 0; i < 5; i++)
    {
        switch(material){
            case 1:
                cout << "A empresa " << empresas[i].codEmpresa << " esta com "
                << empresas[i].metal << "%" << " da capacidade para metal" << endl;
                break;
            case 2:
                cout << "A empresa " << empresas[i].codEmpresa << " esta com "
                << empresas[i].plastico << "%" << " da capacidade para plastico" << endl;
                break;
            case 3:
                cout << "A empresa " << empresas[i].codEmpresa << " esta com "
                << empresas[i].papel << "%" << " da capacidade para papel" << endl;
                break;
            case 4:
                cout << "A empresa " << empresas[i].codEmpresa << " esta com "
                << empresas[i].vidro << "%" << " da capacidade para vidro" << endl;
                break;
            default:
                cout << "opcao invalida\n";
                break;
            }
    }
}

int main()
{

    setlocale(LC_ALL, "");
    FILE *arq;

    TipoCodTransporte transportes[N_REGIOES];
    TipoEmpresas empresas[N_EMPRESAS];

    int nt, ne, resp;
    char aux[NC_LINHA];

    arq = fopen("codRegiaoTransp.txt", "rt");
    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
        return -1;
    }
    else
    {
        nt = 0;
        fgets(aux, NC_LINHA, arq);
        cout << aux << endl;
        while (fscanf(arq, "%i%s", &transportes[nt].codRegiao, transportes[nt].empresa_transporte) != EOF)
        {
            cout << transportes[nt].codRegiao << " \t\t" << transportes[nt].empresa_transporte << endl;
            nt++;
        }
        fclose(arq);
        arq = fopen("estocagemDia.txt", "rt");
        if (arq == NULL)
        {
            printf("Problemas na abertura do arquivo\n");
            return -1;
        }
        else
        {
            ne = 0;
            cout << "\n**********************  estocagemDia.txt **********************\n";
            fgets(aux, NC_LINHA, arq);
            cout << aux << endl;
            while (fscanf(arq, "%i%i%f%f%f%f", &empresas[ne].codEmpresa, &empresas[ne].codRegiao, &empresas[ne].papel, &empresas[ne].metal,
                          &empresas[ne].vidro, &empresas[ne].plastico) != EOF)
            {
                cout << "\t" << empresas[ne].codEmpresa << "\t\t\t\t\t" << empresas[ne].codRegiao
                     << "\t\t" << empresas[ne].papel << "\t\t" << empresas[ne].metal
                     << "\t\t" << empresas[ne].vidro << "\t\t" << empresas[ne].plastico << endl;
                ne++;
            }
            fclose(arq);

            /******************************************************************************************
            TAREFA 5

               Chama a fun��o desenvolvida na TAREFA 3 para obter todos os registros de empresas que
               precisam de transporte de carga a fim de identificar e apresentar as transportadoras que
               devem ser acionadas
           *******************************************************************************************/

            sequencial3(empresas);

            do
            {
                cout << "\n\n1) Analisar os estoques de uma determinada empresa (selecionada pelo codigo).\n";
                cout << "2) Apresentar os 5 registros com os maiores valores de porcentagem de ocupacao de um tipo de residuo.\n";
                cout << "3) Encerrar programa.\n";
                cout << "\t Digite a opcao desejada: ";
                cin >> resp;
                cin.ignore();
                switch (resp)
                {
                case 1:
                    /******************************************************************************************
                     TAREFA 6
                    *******************************************************************************************/
                    int input, posicao;
                    cout << "\nInforme o codigo da empresa desejada ";
                    cin >> input;
                    cin.ignore();
                    posicao = sequencial2(empresas, input);
                    cout << "Codigo da região: " << empresas[posicao].codRegiao << endl;
                    cout << "Quantidade de papel: " << empresas[posicao].papel << endl;
                    cout << "Quatidade de metal: " << empresas[posicao].metal << endl;
                    cout << "Quantidade de vidro: " << empresas[posicao].vidro << "\n";
                    cout << "Quantidade de plastico: " << empresas[posicao].plastico << endl;
                    break;
                case 2:
                    /******************************************************************************************
                     TAREFA 7
                    *******************************************************************************************/
                    int material;
                    cout <<"\n Deseja verificar qual material? \n1 para metal \n2 para plastico \n3 para papel \n4 para vidro" << endl;
                    cin >> material;
                    cout << "\n\n";
                    bubbleSort(empresas, material);
                    break;
                case 3:
                    cout << "Encerrando o programa!\n\n";
                    break;
                default:
                    cout << "opcao invalida\n";
                }
            } while (resp != 3);
        }
    }
    return 0;
}

