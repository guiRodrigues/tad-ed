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

    stack* pilha = CriaPilha(5);

    push(1, pilha);
    push(2, pilha);
    push(3, pilha);

    displayStack(pilha);

    pop(pilha);

    displayStack(pilha);

    return 0;
}