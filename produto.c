#include "produto.h"
#include <stdio.h>
#include <stdlib.h>

int i=0;

int buscarProduto(int numProduto, produto *ptrEstoque, int ID) {
    if(ptrEstoque[numProduto].id == ID){
        if(ID != 0){
            printf("Produto Encontrado: \n");
            printf("%-11s %-11s %14s %21s \n", "ID", "NOME", "PREÇO", "QUANTIDADE");
            
            printf("%-12d", ptrEstoque[numProduto].id);
            printf("%-10s", ptrEstoque[numProduto].nome);
            printf("%15.2f", ptrEstoque[numProduto].preco);
            printf("%15d\n", ptrEstoque[numProduto].quantidade);

            return 0;
        }
    }

    if(numProduto == 0){
        printf("Produto não encontrado!\n");
        return 0;
    }

    return buscarProduto(numProduto - 1, ptrEstoque, ID);
}

int listarProduto(int numProduto, produto *ptrEstoque){
    
    if(numProduto == 0)    
        return 0;

    printf("%-12d", ptrEstoque[numProduto-1].id);
    printf("%-10s", ptrEstoque[numProduto-1].nome);
    printf("%15.2f", ptrEstoque[numProduto-1].preco);
    printf("%15d\n", ptrEstoque[numProduto-1].quantidade);
    

    return listarProduto(numProduto-1, ptrEstoque);
}

int cadastrar_produtos(produto **estoque_produtos, int* tamanho_estoque, int* contador_id){   // **estoque_produtos é um ponteiro para ponteiro de produto(resumindo é o endereço do ponteiro que aponta para o vetor que tem os produtos), *tamanho_estoque é um ponteiro para inteiro, *contador_id é um ponteiro para inteiro
    
    int escolha;
    produto auxiliar,*temp;

    for(int k = 0; k < *tamanho_estoque; k++){
        
        if((*estoque_produtos)[k].id == 0){ // Verifica se o produto está vazio (id = 0 então vazio)
            
            printf("Digite o nome do produto:\n");   
            scanf(" %[^\n]", (*estoque_produtos)[k].nome);
            printf("Digite a quantidade do produto: ");
            scanf("%d", &(*estoque_produtos)[k].quantidade);
            (*contador_id)++;
            (*estoque_produtos)[k].id = *contador_id;
            printf("digite o preço do produto: \n");
            scanf("%f", &(*estoque_produtos)[k].preco);

            for(int i = 0 ; i < *tamanho_estoque; i++){  //ordena os produtos pelo preço em ordem crescente
                for(int j = 0; j < *tamanho_estoque; j++){
                    if(j + 1 < *tamanho_estoque && (*estoque_produtos)[j].id != 0 && (*estoque_produtos)[j+1].id != 0 ){ //evita que o codigo acesse memoria que não existe, evitando assim o erro de segmentação, e também evita que o codigo tente ordenar produtos vazios (id = 0)
                        if( (*estoque_produtos)[j].preco > (*estoque_produtos)[j+1].preco ){
                            auxiliar = (*estoque_produtos)[j];
                            (*estoque_produtos)[j] = (*estoque_produtos)[j+1];
                            (*estoque_produtos)[j+1] = auxiliar;
                        }  
                    }
                   
                }
            }
            return 0;
        }
    }
    printf("Estoque cheio, nao e possivel cadastrar mais produtos.\n-------- DESEJA AUMENTAR O ESTOQUE? --------\n/ 1 - SIM /\n/ 2 - NAO /\n/ 3 - CANCELAR (encerrar programa) / \n");
    scanf("%d", &escolha);
    switch (escolha) {
        case 1:
            temp = realloc((*estoque_produtos), (*tamanho_estoque + 1) * sizeof(produto)); //redimenciona o vetor de produtos para aumentar o tamanho do estoque em 1
            
            if(temp == NULL){
                printf("Erro ao alocar memoria \n");
                return 1;
            }
              
            *estoque_produtos = temp;                               //recebe o endereço do novo vetor alocado, que tem o tamanho do estoque aumentado em 1
            (*estoque_produtos)[*tamanho_estoque].id = 0;              // resetar o id do novo produto para 0, indicando que está vazio
            (*estoque_produtos)[*tamanho_estoque].quantidade = 0;
            (*estoque_produtos)[*tamanho_estoque].preco = 0;
             *tamanho_estoque += 1;
            cadastrar_produtos(estoque_produtos, tamanho_estoque, contador_id);
            return 0;
            break;
        case 2:
            return 0;
            break;
        case 3:
            printf("Operacao cancelada.\n");
            exit(0);
            break;
    }
}

int remover_produto (produto **estoque_produtos, int *tamanho_estoque){
    int remove;
    printf("Digite o id do produto que deseja remover:");
    scanf("%d", &remove);
    for(int i=0;i<*tamanho_estoque;i++){
        if((*estoque_produtos)[i].id==remove){
            for(int k=i;k<*tamanho_estoque-1;k++){
                (*estoque_produtos)[k]=(*estoque_produtos)[k+1];
            }
            (*tamanho_estoque)--;
            produto *ptr_temp=realloc(*estoque_produtos, *tamanho_estoque*sizeof(produto));
            if(ptr_temp==NULL && *tamanho_estoque > 0){
                printf("Erro ao realocar estoque.");
                return 1;
            }
            *(estoque_produtos)=ptr_temp;
            return 0;
        }
    }
    printf("\nID %d não encontrado.\n", remove);
    return 1;
}