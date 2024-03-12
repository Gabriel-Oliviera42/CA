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


int main(void) {
    struct TreeNode *root = NULL;
    root = inserir(root, 10);
    root = inserir(root, 5);
    root = inserir(root, 7);
    root = inserir(root, 12);
    root = inserir(root, 14);
    root = inserir(root, 4);
    root = inserir(root, 17);
    root = inserir(root, 13);
    
    printf("Pré-ordem: ");
    preordem (root);
    printf("\n");

    printf("Em-ordem: ");
    emordem (root);
    printf("\n");

    printf("Pós-ordem: ");
    posordem (root);
    printf("\n");

    return 0;
}