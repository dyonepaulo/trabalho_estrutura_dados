#include <stdio.h>

int main(){

  int opcao,condicao_sair = 0;
    
    while(condicao_sair != 7){

        

    }

    printf(" --------------------------------------------- O que deseja? ---------------------------------------------\n\n"
        "CADASTRAR PRODUTO"
        "\tREMOVER PRODUTO"
        "\t\tLISTAR TODOS OS PRODUTOS"
        "\tBUSCAR PRODUTO POR ID\n");

    printf("Digite 1"
        "\t\tDigite 2"
        "\t\tDigite 3"
        "\t\t\tDigite 4\n\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1: 
        printf("CADASTRAR PRODUTO selecionado.\n");
        break;
    case 2: 
        printf("REMOVER PRODUTO selecionado.\n");
        break;
    case 3: 
        printf("LISTAR TODOS OS PRODUTOS selecionado.\n");
        printf("%-11s %-11s %14s %21s \n", "ID", "NOME", "PREÇO", "QUANTIDADE");
        break; 
    case 4:
        printf("BUSCAR PRODUTO POR ID selecionado.\n");
        break; 
    default:
        printf("OPÇÃO INVÁLIDA.\n");
        break;
        
    }
    return 0;
}

