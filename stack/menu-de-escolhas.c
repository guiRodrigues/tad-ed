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

typedef struct Stack{
    int top;
    int tam;
    int* array;
}stack;

stack* CriaPilha(int n){
    stack* pilha = malloc(sizeof(stack)); // * ?
    pilha->tam = n;
    pilha->top = -1;
    pilha->array = (int*) malloc(pilha->tam * sizeof(int));
    return pilha;
}
// macro ??

int estaCheia(stack* pilha){
    return pilha->top == pilha->tam-1;
}

int estaVazia(stack* pilha){
    return pilha->top == -1;
}

int topo(stack* pilha){
    return pilha->array[pilha->top];
}

void push(int item, stack* pilha){
    if (estaCheia(pilha))
        return;
    // ++pilha->top já faz o incremento do topo
    pilha->array[++pilha->top] = item;
    printf("\n%d adicionado à lista!", item);
}

void pop(stack* pilha){
    if (estaVazia(pilha))
        return;
    int lastTop = pilha->array[pilha->top];
    pilha->array[pilha->top--];
    printf("\n%d removido da lista", lastTop);
}

void displayStack(stack* pilha){
    printf("\n[ ");
    for (int i=0; i<=pilha->top; i++)
        printf("%d ", pilha->array[i]);
    printf("]\n");
}

int main(){

    int response, n, item;
    stack* pilha;
    while (1){
        printf("\nMAKE YOUR CHOICE:\n1-criar, 2-inserir, 3-remover, 4-consulta topo, 5- cheia, 6 vazia, 7-encerrar\n");
        scanf("%d", &response); // & ?

        switch (response)
        {
            case 1:
                printf("Qual o tamanho da pilha?\n");
                scanf("%d", &n);
                pilha = CriaPilha(n);
                break;
            case 2:
                printf("Qual o valor a ser inserido?\n");
                scanf("%d", &item);
                push(item, pilha);
                break;
            case 3:
                pop(pilha);
                break;
            case 4:
                printf("O topo da pilha é %d\n", topo(pilha));
                break;
            case 5:
                printf("%d\n", estaCheia(pilha));
                break;
            case 6:
                printf("%d\n", estaVazia(pilha));
                break;
            case 7:
                break;
            default:
                break;
        }

    }

    return 0;
}