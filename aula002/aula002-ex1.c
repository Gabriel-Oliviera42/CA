#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int info;
    struct TreeNode *left;
    struct TreeNode *right; // aponta pra esquerda
};

// Função para criar o nó da arvore
struct TreeNode *criarno(int info) {
    struct TreeNode *newNode = (struct TreeNode  *)malloc(sizeof(struct TreeNode));

    if (newNode == NULL)
    {
        printf("deu ruim");
    } else {
        newNode->info = info;
        newNode->left = NULL;
        newNode->right = NULL;
    }

    return newNode;    
}

// Função para inserir um item na arvore
struct TreeNode *inserir (struct TreeNode *root, int newInfo) {
    if (root == NULL)
    {
        root = criarno(newInfo);
    } else {
        if (newInfo <= root ->info)
        {
            root -> left = inserir(root -> left, newInfo);
        } else {
            root -> right = inserir(root -> right, newInfo);
        }
        
    }
    return root;    
}

void preordem(struct TreeNode *root) {
    if (root != NULL) {
        printf("%i ", root->info); // Imprime o valor do nó
        preordem(root->left); // Percorre a subárvore esquerda (entra no nó a esquerda e repete a função)
        preordem(root->right); // Percorre a subárvore direita (entra no nó a direita e repete a função)
    }
}

void emordem(struct TreeNode *root) {
    if (root != NULL) {
        emordem(root->left); // Percorre a subárvore esquerda (entra no nó a esquerda e repete a função)
        printf("%i ", root->info); // Imprime o valor do nó
        emordem(root->right); // Percorre a subárvore direita (entra no nó a direita e repete a função)
    }
}

void posordem(struct TreeNode *root) {
    if (root != NULL) {
        posordem(root->left); // Percorre a subárvore esquerda (entra no nó a esquerda e repete a função)
        posordem(root->right); // Percorre a subárvore direita (entra no nó a direita e repete a função)
        printf("%i ", root->info); // Imprime o valor do nó
    }
}

void removerno(struct TreeNode *root, int newInfo) {
    if (root != NULL) {
        if (root -> info == newInfo) {
            if (root -> left == NULL && root -> right == NULL) { // caso seja uma folha
                root->info = NULL;
            } else if (root -> left == NULL || root -> right == NULL) {
                if (root -> left != NULL) { // filho a esqueda
                    int guarda = root -> right;
                } else { // filho a direita

                }
            }
        } else if (root -> info < newInfo) {
            removerno(root -> right, newInfo);
        } else {
            removerno(root -> left, newInfo);
        }
    }
}



/*
1. No programa que foi desenvolvido demostrando a estrutura de dados árvore. Implemente as
seguintes funcionalidades:
• (a) Remoção de um nó;
◦ Dica: Temos três casos: remoção de um nó sem filhos, remoção de um nó com um filho
e remoção de um nó com dois filhos.
• (b) Busca;
◦ Dado um valor, retornar o nó que contém esse valor.
• (c) Menu para chamar as funções criadas;

*/

int main(void) {
    struct TreeNode *root = NULL;
    int op;

    do
    {
        printf("escolha uma opção: ");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
        int valor;
            printf("------------------------------------------------------------------------------------");
            printf("1 - Inserir um valor na arvore (se não houver elementos na arvore, cria a arvore)\n2 - Mostra os valores da arvore em Pré-ordem\n3 - Mostra os valores da arvore em Em-ordem\n4 - Mostra os valores da arvore em Pós-ordem\n5 - Remove um nó pelo valor\n6 - Busca um nó\n 7 - sair\n");
            printf("------------------------------------------------------------------------------------");
            printf("coloque o valor a ser inserido: ");
            scanf("%d",&valor);
            root = inserir(root, valor);
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;  
        case 5:
            /* code */
            break;
        case 6:
            printf("Qual valor você deseja buscar: ");
            scanf("%d",&valor);
            printf("Resultado da busca: %d", buscar(root, valor));
            break;
        case 7:
            printf("Obrigado por vir");
            break;    
        default:
            break;
        }

    } while (op != 7);
    


    return 0;
}