#include <stdio.h>
#include <stdlib.h>

typedef struct registro
{
    int valor;
    struct registro *proximo;
} registro;

typedef struct lista
{
    int qtd;
    registro *inicio;
} lista;

mostrarLista(lista *l, int qtd)
{
    printf("\n\nQuantidade de itens na lista: %d\n\n", qtd);
    registro *r = l->inicio;
    while (r != NULL)
    {
        printf("valor: %d\n\n", r->valor);
        r = r->proximo;
    }
}

lista *criarLista()
{
    lista *l = (lista *)malloc(sizeof(lista));
    l->qtd = 0;
    l->inicio = NULL;
    return l;
}

registro *criarRegistro()
{
    registro *r = (registro *)malloc(sizeof(registro));
    r->valor = 0;
    r->proximo = NULL;
    return r;
}

void inserirOrdenado(lista *l, int valor)
{
    registro *novo = criarRegistro();
    registro *aux, *ant;

    novo->valor = valor;

    aux = l->inicio;
    ant = NULL;

    if (l->inicio == NULL || novo->valor < aux->valor)
    {
        novo->proximo = l->inicio;
        l->inicio = novo;
        return;
    }
    else
    {
        while (aux != NULL && novo->valor > aux->valor)
        {
            ant = aux;
            aux = aux->proximo;
        }

        novo->proximo = aux;
        ant->proximo = novo;

    }
    l->qtd++;
}

void remover(lista *l, int valor)
{
    registro *aux = NULL, *ex = l->inicio;

    if (l->inicio == NULL)
    {
        printf("\n\nNão existem registros nessa lista!\n\n");
        return;
    }
    while (ex != NULL && ex->valor != valor)
    {
        aux = ex;
        ex = ex->proximo;
    }

    if (ex == NULL)
    {
        printf("\nValor não encontrado!\n");
        return;
    }

    if (aux == NULL)
    {
        l->inicio = ex->proximo;
    }
    else
    {
        aux->proximo = ex->proximo;
    }

    free(ex);
    l->qtd--;
}

void menu()
{
    int opcao;
    int rodando = 1;
    lista *l = criarLista();
    while (rodando == 1)
    {
        printf("1 - Inserir ordenado\n");
        printf("2 - Mostrar lista\n");
        printf("3 - Remover\n");
        printf("6 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nInsira o valor do registro: ");
            int valor;
            scanf("%d", &valor);
            inserirOrdenado(l, valor);
            break;
        case 2:
            mostrarLista(l, l->qtd);
            break;
        case 3:
            printf("\nDigite o valor que quer remover: ");
            scanf("%d", &valor);
            remover(l, valor);
            break;
        case 6:
            rodando = 0;
            break;
        }
    }
}

int main()
{

    menu();

    return 0;
}
