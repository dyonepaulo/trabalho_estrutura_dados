#include <stdio.h>
#include "produto.c"
#include <stdlib.h>

int main(){

    int opcao,condicao_sair = 0, tamanho_estoque = 5, contador_id = 1009, id;
    produto (*estoque_produtos) = calloc(tamanho_estoque, sizeof(produto));
    float valor_estoque = 0;

    if(estoque_produtos == NULL){
        printf("Erro ao alocar memoria \n");
        return 1;
    }

    while(condicao_sair != 7){

        printf("\n\n----------------------------------------------------- O que deseja? -----------------------------------------------------\n\n"
            "CADASTRAR PRODUTO"
            "\tREMOVER PRODUTO"
            "\t\tLISTAR TODOS OS PRODUTOS"
            "\tBUSCAR PRODUTO POR ID"
            "\t\tSAIR\n");

        printf("Digite 1"
            "\t\tDigite 2"
            "\t\tDigite 3"
            "\t\t\tDigite 4"
            "\t\t\tDigite 5\n\n"
            "| VALOR TOTAL DO ESTOQUE: R$ %.2f |\n\n",
            calcular_estoque(estoque_produtos, tamanho_estoque-1, valor_estoque));

        if(scanf("%d", &opcao) == 0){

            printf("OPÇÃO INVÁLIDA.\n\n\n\n\n\n");
            while(getchar() != '\n'); 

        }else{

            switch (opcao)
            {
                case 1: 
                    printf("CADASTRAR PRODUTO selecionado.\n");
                    cadastrar_produtos(&estoque_produtos, &tamanho_estoque, &contador_id);
                    break;
                case 2: 
                    printf("REMOVER PRODUTO selecionado.\n");
                    remover_produto(&estoque_produtos, &tamanho_estoque);
                    break;
                case 3: 
                    printf("LISTAR TODOS OS PRODUTOS selecionado.\n");
                    printf("%-11s %-11s %14s %21s \n", "ID", "NOME", "PREÇO", "QUANTIDADE");
                    listarProduto(tamanho_estoque, estoque_produtos);
                    break; 
                case 4:
                    printf("BUSCAR PRODUTO POR ID selecionado.\n"
                        "Digite o ID do produto que deseja buscar: ");
                    scanf("%d", &id);
                    buscarProduto(tamanho_estoque-1, estoque_produtos, id);
                    break;
                case 5:
                    printf("SAIR selecionado (PROGRAMA ENCERRADO).\n");
                    condicao_sair = 7;
                    break; 
                default:
                    printf("OPÇÃO INVÁLIDA.\n\n\n\n\n\n");
                    break;
            }
        }
    }
    free(estoque_produtos);
    return 0;
}
