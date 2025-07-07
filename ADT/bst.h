#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

typedef struct {
    BSTNode* root;
} BSTree;

void createBST(BSTree* tree);
bool isBSTEmpty(BSTree* tree);
BSTNode* insertBST(BSTNode* root, int value);
bool searchBST(BSTNode* root, int value);
BSTNode* deleteBST(BSTNode* root, int value);
void inorderTraversal(BSTNode* root);
void preorderTraversal(BSTNode* root);
void postorderTraversal(BSTNode* root);
int countBSTNodes(BSTNode* root);
void clearBST(BSTNode* root);

#endif
