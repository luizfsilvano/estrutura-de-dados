#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
}lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
    struct registro *ant;
}registro;

// Casting das funções
void * cria_lista();
void * cria_registro();
void inserir_final(int valor, lista * l);
void inserir_inicio(int valor, lista * l);
void remover_registro(int valor, lista * l);
void mostrar_lista(lista * l);
void menu(lista * l);


int main () 
{
    lista * l = cria_lista();
    menu(l);
    return 0;
}

void * cria_lista() 
{
    lista *l = (lista *)malloc(sizeof(lista));
    l->qtd = 0;
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

void * cria_registro()
{
    registro *r = (registro *)malloc(sizeof(registro));
    r->valor = 0;
    r->prox = NULL;
    r->ant = NULL;
    return r;
}

void inserir_final(int valor, lista * l)
{   
    registro * novo = cria_registro();
    novo->valor = valor;
    // Se a lista estiver vazia
    if (l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
        l->qtd++;
        return;
    }

    // Se a lista não estiver vazia
    l->fim->prox = novo;
    novo->ant = l->fim;
    l->fim = novo;
    l->qtd++;
}

void inserir_inicio(int valor, lista * l)
{
    registro * novo = cria_registro();
    novo->valor = valor;
    // Se a lista estiver vazia
    if (l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
        l->qtd++;
        return;
    }

    // Se a lista não estiver vazia
    l->inicio->ant = novo;
    novo->prox = l->inicio;
    l->inicio = novo;
    l->qtd++;
}

void remover_registro(int valor, lista * l)
{
    registro * aux = l->inicio;
    registro * ant = NULL;

    while (aux != NULL && aux->valor != valor)
    {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        printf("Valor não encontrado\n");
        return;
    }

    if (aux == l->inicio)
    {
        l->inicio = aux->prox;
    }
    else
    {
        ant->prox = aux->prox;
    }

    if (aux == l->fim)
    {
        l->fim = ant;
    }
    else
    {
        aux->prox->ant = ant;
    }

    free(aux);
    l->qtd--;
}

void mostrar_lista(lista * l)
{       
    registro * aux = l->inicio;
    while (aux != NULL)
    {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}

void menu(lista * l)
{
    int opcao, valor;
    do
    {
        printf("\n\n1 - Inserir no início\n");
        printf("2 - Inserir no final\n");
        printf("3 - Remover\n");
        printf("4 - Mostrar\n");
        printf("5 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                inserir_inicio(valor, l);
                break;
            case 2:
                printf("Valor: ");
                scanf("%d", &valor);
                inserir_final(valor, l);
                break;
            case 3:
                printf("Valor: ");
                scanf("%d", &valor);
                remover_registro(valor, l);
                break;
            case 4:
                mostrar_lista(l);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida\n");
        }
    } while (opcao != 5);
}