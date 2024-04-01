#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    int qtd;
    struct registro *topo;
} pilha;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

// Casting das funções

void * cria_pilha();
void * cria_registro();
void push(int valor, pilha * p);
void pop(pilha * p);
void stack_pop(pilha * p);
void is_empty(pilha * p);
void menu(pilha * p);



int main ()
{   
    pilha *p = cria_pilha();
    menu(p);
    return 0;
}

void * cria_pilha()
{
    pilha *p = (pilha *) calloc(1, sizeof(pilha));
    p->qtd = 0;
    p->topo = NULL;
    return p;
}

void * cria_registro()
{
    registro * novo = (registro *) calloc(1, sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}

void push(int valor, pilha * p)
{
    registro * novo = cria_registro();
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
    p->qtd++;
}

void stack_pop(pilha * p)
{
    if (p->topo == NULL)
    {
        printf("A pilha está vazia!\n");
        return;
    }

    printf("Valor do topo: %d\n", p->topo->valor);
}

void pop(pilha * p)
{
    if (p->topo == NULL)
    {
        printf("A pilha está vazia!\n");
        return;
    }

    registro *aux = p->topo;
    p->topo = aux->prox;
    free(aux);
    p->qtd--;
}

void is_empty(pilha * p)
{
    if (p->topo == NULL)
    {
        printf("A pilha está vazia!\n");
    }
    else
    {
        printf("A pilha não está vazia!\n");
    }
}


void menu (pilha * p)
{
    int opcao, valor;
    do
    {
        printf("\n\n1 - Push\n2 - Pop\n3 - Stack Pop\n4 - isEmpty\n5 - Sair\n\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                printf("\n\nDigite o valor a ser inserido: ");
                scanf("%d", &valor);
                push(valor, p);
                break;
            case 2:
                pop(p);
                break;
            case 3:
                stack_pop(p);
                break;
            case 4:
                is_empty(p);
                break;
            case 5:
                printf("\n\nSaindo...\n\n");
                break;
            default:
                printf("\n\nOpção inválida\n\n");
                break;
        }
    } while (opcao != 5);

}
