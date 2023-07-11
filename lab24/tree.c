#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "stackbin.h"
#include "stack.h"
#include "tree.h"

typedef struct TreeNode TreeNode;

struct TreeNode {
    TreeNode *parent, *left, *right;
    char value;
};

void treeCreate(Tree *tree) {
    tree->root= NULL;
    tree->size = 0;
}

size_t treeSize(Tree *tree) {
    return tree->size;
}

void treeFromPostfix(Tree *tree, Stack *postfix, StackBin *stack) {
    char ch;
    TreeNode **root = &tree->root;
    stackBinPush(stack, *root, 0);
    Pair pair;
    TreeNode *node = NULL;
    TreeNode *parent = NULL;

	while (!stackBinIsEmpty(stack)) {
		pair = stackBinPop(stack);
		parent = pair.node;
		bool isleft = pair.v;
        node = malloc(sizeof(TreeNode));
		node->parent = parent;
		node->value = stackPop(postfix);
        node->left = NULL;
        node->right = NULL;

		if (parent == NULL) {
			*root = node;
		} else if (isleft) {
			parent->left = node;
            tree->size++;
		} else {
			parent->right = node;
            tree->size++;
		}
		if (precedence(node->value) != -1) {
			stackBinPush(stack, node, 1);
			stackBinPush(stack, node, 0);
		}
	}
}

void nodePrint(TreeNode * node, size_t depth) {

    for (size_t i = 0; i < depth; ++i)
        printf(" ");
    printf("%c\n", node->value);
    if (node->left != NULL)
        nodePrint(node->left, depth + 1);
    if (node->right != NULL)
        nodePrint(node->right, depth + 1);

}

void treePrint(Tree * const tree) {
    bool check = treeSize(tree);
    if (!check)
        printf("Tree is empty\n");
    else
        nodePrint(tree->root, 0);

}

 
int Preorder(char ch, TreeNode * node, int flag) {
    
    if(node->value == '*' && flag == 0) {
            if(Preorder(ch, node->left, 0) == 0) {
                Preorder(ch, node->right, 0);
            }
           
    } else if(node->value == ch && flag == 0) {
           
               node->value = '!';
               ++flag;
               return 1;
               
           } else {
                 return 0;
             }             
}




void nodeFunc( TreeNode * node) {
    
  
    if(node->value == '*') {
        if(node->right->value == '*') {
            nodeFunc(node->right);
        } else {
              int flag = 0;
              TreeNode * node_1 = node->right;
              while(flag != 2 ) {
                  if(flag == 0) {
                       if(node_1->parent->value != '/') {
                            node_1 = node_1->parent;
                       } else { 
                             flag = 1;
                             node_1 = node_1->parent->left;
                         }
                  } 
                  if(flag ==1) {
                      if(Preorder(node->right->value, node_1, 0) == 1) {
                          node->right->value ='!';
                      }
                      ++flag;
                  }
              } 
          }  
     
         
        if(node->left->value == '*') {
            nodeFunc(node->left);
        } else {
              int flag = 0;
              TreeNode * node_1 = node->left;
              
              while(flag != 2 ) {
                  if(flag == 0) {
                       if(node_1->parent->value != '/') {
                            node_1 = node_1->parent;
                       } else { 
                             flag = 1;
                             node_1 = node_1->parent->left;
                         }
             
                  } 
                  if(flag == 1) {
                      if(Preorder(node->left->value, node_1, 0) == 1) {
                          
                          node->left->value ='!';
                      }
                      ++flag;
                  } 
              }
          }                 
          
        
    } else {
          int flag = 0;
          TreeNode * node_1 = node;
              
          while(flag != 2 ) {
              if(flag == 0) {
                  if(node_1->parent->value != '/') {
                      node_1 = node_1->parent;
                  } else { 
                        flag = 1;
                        node_1 = node_1->parent->left;
                    }
              } 
                  if(flag == 1) {
                      if(Preorder(node->value, node_1, 0) == 1) {                          
                          node->value ='!';
                      }
                      ++flag;                          
                  } 
          }
        	
      }
   
}

void nodeDelete1 (TreeNode * node) {
    
    TreeNode *copy = node;
    if (node->value == '*') {
        if (node->left->value == '!') {
            if (node->parent->right == node) {
                node->right->parent = node->parent;
                node->parent->right = node->right;
                copy = node->parent;
                free(node->left);
                free(node);
            } else {
                node->right->parent = node->parent;
                node->parent->left = node->right;
                copy = node->parent;
                free(node->left);
                free(node);
            }
        }
    }
    if (copy != NULL) {
        if (copy->left != NULL)
            nodeDelete1(copy->left);
        if (copy->right != NULL)
            nodeDelete1(copy->right);
    
    
    }
}

void nodeDelete2(TreeNode * node) {
    
    TreeNode *copy = node;
    if (node->value == '*') {
        if (node->right->value == '!') {
            if (node->parent->left == node) {
                node->left->parent = node->parent;
                node->parent->left = node->left;
                copy = node->parent;
                free(node->right);
                free(node);
            } else {
                node->left->parent = node->parent;
                node->parent->right = node->left;
                copy = node->parent;
                free(node->right);
                free(node);
            }
        }
    }
    if (copy != NULL) {
        if (copy->left != NULL)
            nodeDelete2(copy->left);
        if (copy->right != NULL)
            nodeDelete2 (copy->right);
    }

}

	
void nodeDelete3( TreeNode * node) {
     
        if(node->right->value == '!'){
            node->right->value ='1';
        }
        if(node->left->value == '!') {
            node->left->value = '1';
        }
    
}
int checkNode( TreeNode * node) {
     if(  node->value == '*') {
         if(node->right->value == '0') {
             return 1;
         } else if(node->right->value == '*') {
                    checkNode(node->right);
                }
         if(node->left->value == '0') { 
             return 1;
         } else if(node->left->value == '*') {
                    checkNode(node->left);
                }
     } else if(node->value == '0') {return 1;}
}

int treeCheck(Tree *tree) {
   if(checkNode(tree->root->right) == 1){
       return 1;
   } else if(checkNode(tree->root->left) == 1) {
              return 2;
          } else {
                return 0;
            }
    
}

bool treeF(Tree *tree) {

    nodeFunc( tree->root->right);
    nodeDelete1 (tree->root);
    nodeDelete2 (tree->root);
    nodeDelete3 (tree->root);
    
}

void treeInorder(Tree* tree) {
    TreeNode* node = tree->root;

    TreeNode* last = NULL;
    while (node != NULL) {
        if (last == node->parent) {
            if (node->left != NULL) {
                last = node;
                node = node->left;
                continue;
            }
            else
                last = NULL;
        }
        if (last == node->left) {
            printf("%c ", node->value);

            if (node->right != NULL) {
                last = node;
                node = node->right;
                continue;
            }
            else
                last = NULL;
        }
        if (last == node->right) {
            last = node;
            node = node->parent;
        }
    }
    printf("\n");
}

void treeDestroy(Tree *tree)  {
    TreeNode *node = tree->root;
    TreeNode *root = tree->root;
    while (root->left != NULL || root->right != NULL) {
        if (node->left != NULL)
            node = node->left;
        else if (node->right != NULL)
            node = node->right;
        else {
            if (node->parent->left == node) {
                node = node->parent;
                free(node->left);
                node->left = NULL;
                --tree->size;
            }
            else if (node->parent->right == node) {
                node = node->parent;
                free(node->right);
                node->right = NULL;
                --tree->size;
            }
        }
    }
    free(root);
    tree->root = NULL;
    --tree->size;
}

int nodeCount(TreeNode *node) {
    if (checkIfOperand(node->value)) {
        return node->value - '0';
    }
    if (node->value == '/') {
        return nodeCount(node->left) / nodeCount(node->right);
    }
    if (node->value == '*') {
        return nodeCount(node->left) * nodeCount(node->right);
    }
    if (node->value == '+') {
        return nodeCount(node->left) + nodeCount(node->right);
    }
    if (node->value == '-') {
        return nodeCount(node->left) - nodeCount(node->right);
    }
}

int treeCount(Tree *tree) {
    return nodeCount(tree->root);
}
