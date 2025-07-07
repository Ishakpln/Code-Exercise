#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void createBST(BSTree* tree) {
    tree->root = NULL;
}

bool isBSTEmpty(BSTree* tree) {
    return tree->root == NULL;
}

BSTNode* createBSTNode(int value) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

BSTNode* insertBST(BSTNode* root, int value) {
    if (root == NULL) {
        return createBSTNode(value);
    }

    if (value < root->data) {
        root->left = insertBST(root->left, value);
    } else if (value > root->data) {
        root->right = insertBST(root->right, value);
    }

    return root;
}

bool searchBST(BSTNode* root, int value) {
    if (root == NULL) {
        return false;
    }

    if (value == root->data) {
        return true;
    } else if (value < root->data) {
        return searchBST(root->left, value);
    } else {
        return searchBST(root->right, value);
    }
}

BSTNode* findMin(BSTNode* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

BSTNode* deleteBST(BSTNode* root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (value < root->data) {
        root->left = deleteBST(root->left, value);
    } else if (value > root->data) {
        root->right = deleteBST(root->right, value);
    } else {
        // found node
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        } else {
            BSTNode* successor = findMin(root->right);
            root->data = successor->data;
            root->right = deleteBST(root->right, successor->data);
        }
    }

    return root;
}

void inorderTraversal(BSTNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(BSTNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(BSTNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int countBSTNodes(BSTNode* root) {
    if (root == NULL) return 0;
    return 1 + countBSTNodes(root->left) + countBSTNodes(root->right);
}

void clearBST(BSTNode* root) {
    if (root != NULL) {
        clearBST(root->left);
        clearBST(root->right);
        free(root);
    }
}
