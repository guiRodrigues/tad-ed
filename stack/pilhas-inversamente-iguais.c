#include <stdio.h>
#include <stdlib.h>

/*

Elementos da pilha
    tam: número máximo de elementos na pilha
    topo: ı́ndice para o topo da pilha

Operações
    CriaPilha: criação de uma pilha sequencial
    Top: consulta o topo da pilha sequencial
    Empilha: inclusão de um elemento em uma pilha sequencial
    Desempilha: exclusão de um elemento em uma pilha sequencial

Passos para a criação da stack (pilha)
- criar uma estrutura que represente a pilha
- criar uma função que crie uma pilha
- criar uma função que verifique se a pilha está cheia
- criar uma função que verifique se está vazia
- criar uma função que adicione um item à lista
- criar uma função que remova um item da lista
*/

typedef struct Stack
{
    int top;
    int tam;
    int *array;
} stack;

stack *CriaPilha(int n)
{
    stack *pilha = malloc(sizeof(stack)); // * ?
    pilha->tam = n;
    pilha->top = -1;
    pilha->array = (int *)malloc(pilha->tam * sizeof(int));
    return pilha;
}
// macro ??

int estaCheia(stack *pilha)
{
    return pilha->top == pilha->tam - 1;
}

int estaVazia(stack *pilha)
{
    return pilha->top == -1;
}

void push(int item, stack *pilha)
{
    if (estaCheia(pilha))
        return;
    // ++pilha->top já faz o incremento do topo
    pilha->array[++pilha->top] = item;
    printf("\n%d adicionado à lista!", item);
}

int pop(stack *pilha)
{
    if (estaVazia(pilha))
        return -1;
    return pilha->array[pilha->top--];
}

void displayStack(stack *pilha)
{
    printf("\n[ ");
    for (int i = 0; i <= pilha->top; i++)
        printf("%d ", pilha->array[i]);
    printf("]\n");
}

void preenchePilha(stack *pilha)
{
    char response;
    int item;
    for (int i = 0; i < pilha->tam; i++)
    {
        printf("Deseja inserir um elemento?\n");
        scanf(" %c", &response);
        if (response == 'y')
        {
            scanf("%d", &item);
            push(item, pilha);
        }
        else
        {
            break;
        }
    }
}

int comparaPilhas(stack *p1, stack *p2)
{
    if (p1->tam != p2->tam || p1->top != p2->top)
        return -1;
    for (int i = 0; i <= p1->tam; i++)
        if (p1->array[i] != p2->array[i])
            return -1;
    return 1;
}

stack *revertePilha(stack *pilha)
{
    // criar o array auxiliar
    stack* pilhaR;
    int *elementos = (int*) malloc(pilha->top * sizeof(int));
    int aux = pilha->top;
    for (int i=0; i<=pilha->top; i++){
        elementos[i] = pop(pilha);
    }

    for (int i=aux; i>=0; i--){
        push(elementos[i], pilhaR);
    }

    return pilhaR;
}

int main()
{

    int n;

    printf("\nDigite o tamanho da primeira pilha:\n");
    scanf("%d", &n);
    stack *pilha1 = CriaPilha(n);
    printf("\nAgora, preencha ela:\n");
    preenchePilha(pilha1);

    printf("\nDigite o tamanho da segunda pilha:\n");
    scanf("%d", &n);
    stack *pilha2 = CriaPilha(n);
    printf("\nAgora, preencha ela:\n");
    preenchePilha(pilha2);

    displayStack(pilha1);
    displayStack(pilha2);

    stack* pilhaRevertida = revertePilha(pilha2);
    displayStack(pilhaRevertida);

    // const char *relacao = comparaPilhas(pilha1, pilha2) == -1 ? "diferentes" : "iguais";

    // printf("\nAs prilhas são %s.", relacao);

    return 0;
}