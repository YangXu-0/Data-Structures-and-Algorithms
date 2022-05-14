/*
a
*/

#include <stdlib.h>

typedef struct Node {
    int cargo;
    int height; // intialize to 0 for leaf nodes or calc as needed
    struct Node *left;
    struct Node *right;
} Node;


/* When to rotate?
    After each recursive insert/delete call check for an imbalance (<-1 or >1 difference between subtrees)
    if yes - do rotation, update the heights of rotated nodes
    if no - just update the height (if part of struct)
*/


// left left violation, rotate right
void rotate_right(Node **root) {
    Node *X = *root;
    Node *Y = X->right;
    X->left = Y->right;
    Y->right = X;
    *root = Y;
    update_height(X); // order matters here, Y right now is parent of X
    update_height(Y);
}

// left left or left right violation
void rebalance_right(Node **root) {
    //if left right violation, rotate left child first
    if ((*root)->left->right->height > (*root)->left->left->height) {
        rotate_left(&((*root)->left));
    }
    rotate_right(root);
}
