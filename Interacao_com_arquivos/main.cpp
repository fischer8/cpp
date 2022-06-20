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

void sequencial2(TipoEmpresas empresas[N_EMPRESAS], int input)
{
    int papel, metal, vidro, plastico;
    for (int i = 0; i < 39; i++)
    {
        if (empresas[i].codEmpresa == input)
        {
            metal = empresas[i].metal;
            papel = empresas[i].papel;
            vidro = empresas[i].vidro;
            plastico = empresas[i].plastico;
            cout << "\nA empresa " << input << " esta com " << metal << "%"
                 << " da capacidade para metal";
            cout << "\nA empresa " << input << " esta com " << papel << "%"
                 << " da capacidade para papel";
            cout << "\nA empresa " << input << " esta com " << plastico << "%"
                 << " da capacidade para plastico";
            cout << "\nA empresa " << input << " esta com " << vidro << "%"
                 << " da capacidade para vidro\n\n";
        }
    }
}

/******************************************************************************
TAREFA 3
*******************************************************************************/

void sequencial3(TipoEmpresas empresas[N_EMPRESAS])
{
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
    if (material == 1)
    {
        for (i = 0; i < 38; i++)
            for (j = 0; j < 37 - i; j++)
                if (empresas[j].metal > empresas[j + 1].metal)
                    swap(empresas[j + 1].metal,empresas[j].metal);
        
    }
    if (material == 2)
    {
        for (i = 0; i < 38; i++)
            for (j = 0; j < 37 - i; j++)
                if (empresas[j].plastico > empresas[j + 1].plastico)
                    swap(empresas[j + 1].plastico,empresas[j].plastico);
        
    }
    if (material == 3)
    {
        for (i = 0; i < 38; i++)
            for (j = 0; j < 37 - i; j++)
                if (empresas[j].papel > empresas[j + 1].papel)
                    swap(empresas[j + 1].papel,empresas[j].papel);
        
    }
    if (material == 4)
    {
        for (i = 0; i < 38; i++)
            for (j = 0; j < 37 - i; j++)
                if (empresas[j].vidro > empresas[j + 1].vidro)
                    swap(empresas[j + 1].vidro, empresas[j].vidro);
        
    }

    int metal, papel, vidro, plastico,cod;
    for (int i = 0; i < 5; i++)
    {
        cod = empresas[i].codEmpresa;
        metal = empresas[i].metal;
        papel = empresas[i].papel;
        vidro = empresas[i].vidro;
        plastico = empresas[i].plastico;
        cout << "\nA empresa " << cod << " esta com " << metal << "%"
             << " da capacidade para metal";
        cout << "\nA empresa " << cod << " esta com " << papel << "%"
             << " da capacidade para papel";
        cout << "\nA empresa " << cod << " esta com " << plastico << "%"
             << " da capacidade para plastico";
        cout << "\nA empresa " << cod << " esta com " << vidro << "%"
             << " da capacidade para vidro\n\n";
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
                int n = 0;
                cout << "1) Analisar os estoques de uma determinada empresa (selecionada pelo c�digo).\n";
                cout << "2) Apresentar os 5 registros com os maiores valores de porcentagem de ocupa��o de um tipo de res�duo.\n";
                cout << "3) Encerrar programa.\n";
                cout << "\t Digite a op��o desejada: ";
                cin >> resp;
                cin.ignore();
                switch (resp)
                {
                case 1:
                    /******************************************************************************************
                     TAREFA 6
                    *******************************************************************************************/
                    int input;
                    cout << "\nInforme o codigo da empresa desejada ";
                    cin >> input;
                    sequencial2(empresas, input);

                    system("pause");
                    break;
                case 2:
                    /******************************************************************************************
                     TAREFA 7
                    *******************************************************************************************/
                    int material;
                    cout << "\n Deseja verificar qual material? \n1 para metal \n2 para plastico \n3 para papel \n4 para vidro";
                    cin >> material;            
                    bubbleSort(empresas, material);
                    break;
                case 3:
                    cout << "Encerrando o programa!\n\n";
                    break;
                default:
                    cout << "op��o inv�lida\n";
                }
            } while (resp != 3);
        }
    }
    return 0;
}
