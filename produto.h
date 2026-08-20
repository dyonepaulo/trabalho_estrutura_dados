#ifndef PRODUTO_H
#define PRODUTO_H
 
typedef struct {

    int id;
    char* nome[30];
    float preco;
    int quantidade;

} produto;

int buscarProduto(produto *ptr, int N, int ID);

int cadastrar_produtos(produto **estoque_produtos, int* tamanho_estoque, int* contador_id);

int listarProduto(int N, produto *ptr);

#endif 
