#define NC 50

using namespace std;

struct registro_loja {
    char bairro[NC];
    int qtd_atendimento;
};
typedef struct registro_loja TipoLoja;

struct melhor_pior {
    TipoLoja melhor;
    TipoLoja pior;
};
typedef struct melhor_pior TipoMelhorPior;

struct registro_cliente {
    char CPF[NC];
    char bairro[NC];
};
typedef struct registro_cliente TipoCliente;

struct registro_pedido {
    TipoCliente cliente;
    char encomenda[NC];
};
typedef struct registro_pedido TipoPedido;

struct no{
    TipoPedido dado;
    struct no* prox;
};

typedef struct no* TipoFila;


void init(TipoFila *ini, TipoFila *fim)
{
*ini  = NULL;
*fim = NULL;
}


int isEmpty(TipoFila ini, TipoFila fim){
if ((ini == NULL) && (fim == NULL) )
	return(1);
else
	return(0);
}

void enqueue( TipoFila *ini, TipoFila *fim, TipoPedido v)
{
TipoFila novo;
novo=(TipoFila ) malloc (sizeof(struct no));
if (novo==NULL)
	 cout << "Fila Cheia \n";
else  {
	 novo->dado=v;
	 novo->prox=NULL;
	 if (isEmpty(*ini, *fim)){
	     *ini = novo;
	     }
	 else{
	     (*fim)->prox= novo;
	     }
    *fim = novo;
	}
}

int dequeue (TipoFila *ini, TipoFila *fim, TipoPedido *v){
    TipoFila aux = *ini;
    if (isEmpty(*ini, *fim))
        	  return 0;
    else{
        *v = aux->dado;
        *ini = aux->prox;
        if (*ini == NULL)
            *fim = NULL;
        free(aux);
        return 1;
    }
}

int first (TipoFila ini, TipoFila fim, TipoPedido *v){

    if (isEmpty(ini, fim))
        return 0;
    else{
        *v = ini->dado;
        return 1;
    }
}

void show(TipoFila ini, TipoFila fim){
    TipoFila aux = ini;
    while (aux!=NULL){
        cout << "\nCPF: " << aux->dado.cliente.CPF;
        cout << "\t Bairro: " << aux->dado.cliente.bairro;
        cout << "\t Encomenda: " << aux->dado.encomenda << endl;

        aux = aux->prox;
    }
}
