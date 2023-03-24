#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node TreeNode;
struct tree_node {
  int data;
  TreeNode *left, *right;
};

// função que adiciona um elemento à árvore, assim se o elemento
// for maior que a raiz ele vai para a direita e se for menor para
// a esquerda e assim por diante.

TreeNode*
inserir(TreeNode* a, int x){
    TreeNode* n = (TreeNode*)malloc(sizeof(TreeNode));
    if(a == NULL){
         TreeNode* novo = (TreeNode*)malloc(sizeof(TreeNode));;
         novo->data = x;
         novo->left = NULL;
         novo->right = NULL;
         n = 0;
    }
    else{
        if (x == a->data){
             n = 1;
        }
        if(x > a->data){
             n = inserir(a->right , x);
        }
        if(x < a->data){
             n = inserir(a->left , x);
        }
    }
    return n;
}
