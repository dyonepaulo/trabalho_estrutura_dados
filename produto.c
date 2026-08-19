#include "produto.h"
#include <stdio.h>
#include <stdlib.h>

int i=0;

int buscarProduto(produto *ptr, int N, int ID) {
    if(ptr[N].id == ID){
        printf("Produto Encontrado: \n");
        printf("\t\t\tID\t\tNOME\t\tPREÇO\t\tQUANTIDADE\n");
        printf("\t\t\t%d\t\t", ptr[N].id);
        printf("%s", ptr[N].nome);
        printf("\t\t%.2f\t\t", ptr[N].preco);
        printf("%d\n", ptr[N].quantidade);

        return 0;
    }

    if(N == 0){
        printf("Produto não encontrado!\n");
        return 0;
    }

    return buscarProduto(ptr, N-1, ID);
}

int listarProduto(int N){
    int resultado;

    if(N==0){
        return 0;
    }

    printf("\tID\t\tNOME\t\tPREÇO\t\tQUANTIDADE\n");
    printf("\t%d\t\t", ptr[N-1].id);
    printf("%s", ptr[N-1].nome);
    printf("\t\t%.2f\t\t", ptr[N-1].preco);
    printf("%d\n", ptr[N-1].quantidade);
    

    return listarProduto(N-1);
}


int main() {
    int n = 3;
    int id;

    ptr = (produto *)malloc(n * sizeof(produto));

    if (ptr == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        return 1;
    }

    for(i=0;i<n;i++){
        scanf("%d", &(ptr[i].id));
        scanf("%s", &ptr[i].nome);
        scanf("%f", &(ptr[i].preco));
        scanf("%d", &(ptr[i].quantidade));
    }

    printf("Digite o ID do produto: ");
    scanf("%d", &id);
    
    /*
    PARA TESTAR A OUTRA FUNÇÃO 
    printf("\tID\t\tNOME\t\tPREÇO\t\tQUANTIDADE\n");
    listarProduto(n);
    */
    
    buscarProduto(ptr, n, id);


    free(ptr);
    return 0;
}
