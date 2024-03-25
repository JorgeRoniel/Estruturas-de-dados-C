#include <stdio.h>
#include <stdlib.h>

typedef struct Produto {
   int codigo;
   double valor;
} Produto;

Produto create(int codigo, double valor) {
   Produto novo_prod;
   novo_prod.codigo = codigo;
   novo_prod.valor = valor;


   return novo_prod;
}

void swap(Produto *a, Produto *b){
    Produto p = *a;
    *a = *b;
    *b = p;
}

int particao(Produto vetor[], int menor, int maior){
    int pivot = vetor[maior].codigo;
    int i = menor - 1;

    for(int j = menor; j <= maior - 1; j++){
        if(vetor[j].codigo < pivot){
            i++;
            swap(&vetor[i], &vetor[j]);
        }
    }
    swap(&vetor[i + 1], &vetor[maior]);
    return i + 1;
}

void quickSort(Produto vetor[], int menor, int maior){
    if(menor < maior){
        int pi = particao(vetor, menor, maior);
        quickSort(vetor, menor, pi - 1);
        quickSort(vetor, pi + 1, maior);
    }
}

void print(Produto produto) {
   printf("Produto: codigo - %i \nvalor - %f \n", produto.codigo, produto.valor);
}

void printAll(Produto vetor[], int n) {
   int i = 0;
   for (i = 0; i < n; i++) {
       print(vetor[i]);
   }
}

int main() {
   Produto prod[5];

   prod[0] = create(22, 100);
   prod[1] = create(1, 50);
   prod[2] = create(55, 189);
   prod[3] = create(100, 200);
   prod[4] = create(2, 320);

   printAll(prod, 5);
   quickSort(prod, 0, 4);
   printf("\n");
   printAll(prod, 5);
   return 0;
}
