#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó de árvore binária
struct TreeNode
{
    int info;                   // Informação armazenada no nó
    struct TreeNode *left;      // Ponteiro para o filho esquerdo
    struct TreeNode *right;     // Ponteiro para o filho direito
};

// Função para criar um novo nó da árvore com uma informação específica
struct TreeNode *criarno(int info) {
    // Aloca memória para o novo nó
    struct TreeNode *newNode = (struct TreeNode  *)malloc(sizeof(struct TreeNode));

    // Verifica se a alocação de memória foi bem-sucedida
    if (newNode == NULL)
    {
        printf("deu ruim");     // Se falhou, exibe uma mensagem de erro
    } else {
        // Se a alocação de memória foi bem-sucedida, atribui a informação ao nó e define os ponteiros esquerdo e direito como NULL
        newNode->info = info;
        newNode->left = NULL;
        newNode->right = NULL;
    }

    return newNode;    // Retorna o ponteiro para o novo nó criado
}

// Função para inserir um novo nó na árvore
struct TreeNode *inserir (struct TreeNode *root, int newInfo) {
    if (root == NULL)   // Se a raiz for NULL, cria um novo nó com a informação dada
    {
        root = criarno(newInfo);
    } else {
        if (newInfo <= root ->info)     // Se a informação é menor ou igual à informação na raiz, insere à esquerda
        {
            root -> left = inserir(root -> left, newInfo);
        } else {                        // Caso contrário, insere à direita
            root -> right = inserir(root -> right, newInfo);
        }
    }
    return root;    // Retorna a raiz da árvore
}

// Função para percorrer a árvore em pré-ordem (raiz, esquerda, direita)
void preordem(struct TreeNode *root) {
    if (root != NULL) {
        printf("%i ", root->info);     // Imprime o valor do nó
        preordem(root->left);           // Percorre a subárvore esquerda
        preordem(root->right);          // Percorre a subárvore direita
    }
}

// Função para percorrer a árvore em ordem (esquerda, raiz, direita)
void emordem(struct TreeNode *root) {
    if (root != NULL) {
        emordem(root->left);            // Percorre a subárvore esquerda
        printf("%i ", root->info);      // Imprime o valor do nó
        emordem(root->right);           // Percorre a subárvore direita
    }
}

// Função para percorrer a árvore em pós-ordem (esquerda, direita, raiz)
void posordem(struct TreeNode *root) {
    if (root != NULL) {
        posordem(root->left);           // Percorre a subárvore esquerda
        posordem(root->right);          // Percorre a subárvore direita
        printf("%i ", root->info);      // Imprime o valor do nó
    }
}

// Função para buscar um valor na árvore
int buscar(struct TreeNode *root, int newInfo) {
    if(root == NULL) {
        return -1;                      // Se a árvore estiver vazia, retorna -1
    } else {
        if (root -> info == newInfo) {
            return root -> info;        // Se encontrar o valor, retorna o valor
        } else {
            if (newInfo < root -> info) {
                return buscar(root -> left, newInfo);   // Se o valor for menor, busca na subárvore esquerda
            } else {
                return buscar(root -> right, newInfo);  // Se o valor for maior, busca na subárvore direita
            }
        }
    }
}

// Função para remover um nó da árvore
struct TreeNode *remover (struct TreeNode *root, int newInfo)  {
    if(root == NULL) {
        printf("Valor não encontrado!");
        return NULL;                    // Se a árvore estiver vazia, retorna NULL
    } else {
        if(root -> info == newInfo) {      // Se encontrou o valor a ser removido
            if(root -> left == NULL && root -> right == NULL) {
                free(root);             // Se for um nó folha, libera a memória e retorna NULL
                return NULL;
            } else {
                if (root -> left == NULL || root -> right == NULL) {
                    struct TreeNode *aux;
                    if (root -> left != NULL) {
                        aux = root -> left;     // Se tiver um filho, substitui o nó a ser removido pelo filho
                    } else {
                        aux = root -> right;
                    }
                    free (root);
                    return aux;
                } else {
                    struct TreeNode *aux = root -> left;
                    while (aux -> right != NULL)
                    {
                        aux = aux -> right;         // Se tiver dois filhos, substitui o nó a ser removido pelo menor nó da subárvore direita
                    }
                    root -> info = aux -> info;
                    aux -> info = newInfo;
                    root -> left = remover(root -> left, newInfo);
                    return root;
                }
            }
        } else {
            if(newInfo < root -> info) {
                root -> left = remover (root -> left, newInfo);    // Se o valor a ser removido for menor, busca na subárvore esquerda
            } else {
                root -> left = remover (root -> right, newInfo);   // Se o valor a ser removido for maior, busca na subárvore direita
            }
            return root;
        }
    }
}

// Função principal
int main(void) {
    struct TreeNode *root = NULL;   // Inicializa a árvore como vazia
    int op, valor;

    // Menu de operações
    do {
        printf("\n--------------------------------------\n");
        printf("1 - Inserir um valor na árvore\n");
        printf("2 - Mostrar os valores da árvore em Pré-ordem\n");
        printf("3 - Mostrar os valores da árvore em Em-ordem\n");
        printf("4 - Mostrar os valores da árvore em Pós-ordem\n");
        printf("5 - Remover um nó pelo valor\n");
        printf("6 - Buscar um nó\n");
        printf("7 - Sair\n");
        printf("\n--------------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                {
                int valor;
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                root = inserir(root, valor);    // Insere um valor na árvore
                break;
                }
            case 2:
                printf("Valores da árvore em Pré-ordem: ");
                preordem(root);     // Mostra os valores da árvore em pré-ordem
                printf("\n");
                break;
            case 3:
                printf("Valores da árvore em Em-ordem: ");
                emordem(root);      // Mostra os valores da árvore em ordem
                printf("\n");
                break;
            case 4:
                printf("Valores da árvore em Pós-ordem: ");
                posordem(root);     // Mostra os valores da árvore em pós-ordem
                printf("\n");
                break;
            case 5:
                printf("Qual valor você deseja remover: ");
                scanf("%d", &valor);
                remover(root, valor);   // Remove um nó da árvore
                break;
            case 6:
                printf("Qual valor você deseja buscar: ");
                scanf("%d", &valor);
                printf("Resultado da busca: %d\n", buscar(root, valor));   // Busca um valor na árvore
            case 7:
                printf("Obrigado por utilizar o programa!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

    } while (op != 7);  // Loop até que a opção "7 - Sair" seja escolhida

    return 0;
}
