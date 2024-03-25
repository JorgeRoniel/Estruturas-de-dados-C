#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
} No;

typedef struct lista{
    No *inicio;
    int tamanho;
} Lista;

Lista *criarLista(){
    Lista *lista;
    lista->inicio = NULL;
    lista->tamanho = 0;

    return lista;
}

void inserir(Lista *lista, int valor){
    No *novo_no = (No*) malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->prox = lista->inicio;
    lista->inicio = novo_no;
    lista->tamanho++;
}

void imprimir(Lista *lista){
    No *inicio = lista->inicio;
    while(inicio != NULL){
        printf("%d \n", inicio->valor);
        inicio = inicio->prox;
    }
}