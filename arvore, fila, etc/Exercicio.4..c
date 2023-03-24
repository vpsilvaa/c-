#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node TreeNode;
struct tree_node {
  int data;
  TreeNode *left, *right;
};

// A fun��o procura nos n�s da �rvore o valor passado como par�metro,
// se o valor estiver na �rvore, ela retorna o n� onde est� o valor.
TreeNode*
buscar(TreeNode* a, int x){
     TreeNode* n = (TreeNode*)malloc(sizeof(TreeNode));
     if(a == NULL){
        return NULL;
     }
     else if (x == a->data){
        return a;
     }
     n = buscar(a->left, x);
     if (n == NULL){
         n = buscar(a->right, x);
     }
     return n;
}
