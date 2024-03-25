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
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->tamanho = 0;

    return lista;
}

// insere no começo
void inserir(Lista *lista, int valor){
    No *novo_no = (No*) malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->prox = lista->inicio;
    lista->inicio = novo_no;
    lista->tamanho++;
}

void inserirNoFim(Lista *lista, int valor){
    No *no, *novo_no = (No*) malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->prox = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo_no;
    }else{
        no = lista->inicio;
        while(no->prox != NULL){
            no = no->prox;
        }
        no->prox = novo_no;
    }
    lista->tamanho++;
}

void imprimir(Lista *lista){
    No *inicio = lista->inicio;
    while(inicio != NULL){
        printf("%d \n", inicio->valor);
        inicio = inicio->prox;
    }
}
int main(){
    Lista *l1;
    l1 = criarLista();
    
    for (int  i = 0; i < 10; i++){
        inserirNoFim(l1, i);
    }
    

    imprimir(l1);
    
    return 0;
}