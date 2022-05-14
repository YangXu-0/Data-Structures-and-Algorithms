/*
Binary trees are a type of tree where every node has at most two children
- Binary search trees are a type of binary tree where:
    - The left descendants contain values smaller than the ancestor nodes
    - The right descendants contain values higher than the ancestor nodes
- All BSTs are BTs, not all BTs are BSTs

Insert
- Add a node to the BST, maintaining BST properly
1. Creat a new node
2. Start a root
    - If  the tree is empty, add new node as root -> return
    - Else, compare new node value with root value  
    - If new node value smaller, go left
    - Else if larger go right
3. Repeat step 2 with either the left or right child as new root (recursion)

Search
Check if a value exists in one of the BST nodes
1. Start at root
    - if the tree is empty -> return value does not exist
    - Else if the node contains the value -> return value found
    - Else, compare search value with root avalue
        - If search value is smaller, go left
        - Else search value is larger go right
2. Repeat step 1 with either the left or right child as new root (recursion)

Delete 
Check if a value exists in one of the BST nodes.. and delete it, maintaining a valid BST
Search for node to delete - start at root
    - If the tree is empty -> return without deleting
    - Else if the node contains the value -> delete and returns
    - Else, compare search value with root value
        - If search value is smaller, go left (recursion with left child)
        - If search value is larger, go right (recursion with right child)

Case 1: no children, delete and set node to null
Case 2: one child, replace node with child and delete node
Case 3: two children, find successor
    - Successor is the smallest/left-most node in right subtree
    - If successor is right child, replace node with right child
        - Link left child and delete node
    - If successor is not the right child 
        - Replace successor with its right child
        - Replace node with successor, linking both children

Common Pitfalls
- Losing nodes (and memory)
    - Unlinking the tree, overwriting pointers, free-ing too soon,
- Bad memory access
    -Trying to access left/right/value of free'd/null pointers/nodes
- Making a circular tree
    - Tends to result in infinite loops 

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

void insert_helper(Node **root, Node *new_node);
void insert_BST(Node **root, int value);

void insert_BST(Node **root, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root==NULL) {
        (*root) = new_node;
    }
    else if ((*root)->value > new_node->right) {
        insert_helper(&((*root)->left), new_node);
    }
    else {
        insert_helper(&((*root)->right), new_node);
    }
    return;
}


void insert_helper(Node **root, Node *new_node) {
    if (*root==NULL) {
        (*root) = new_node;
    }
    else if (1==1 /**/) {
        /***/
    }
    else {
        /***/
    }
}


Node *search_BST(Node *root, int search_val) {
    if (root==NULL) {
        return root;
    }
    if (root->value == search_val) {
        return root;
    }
    if (root->value < search_val) {
        return search_BST(root->right, search_val);
    }
    else {
        return search_BST(root->left, search_val);
    }
}


void delete_BST(Node **root, int search_value) {
    if((*root) == NULL) {
        return;
    }
    if ((*root)->value == search_value) {
        // Case 1: no children
        if ((*root)->left = NULL && (*root)->right == NULL) {
            free(*root);
            (*root) = NULL;
            return ;
        }
        // Case 2: 1 child
        else if ((*root)->left != NULL && (*root)->right==NULL) {
            Node *temp = (*root)->left;
            free(*root);
            *root = temp;
        }
        else if ((*root)->left != NULL && (*root)->right==NULL) {
            Node *temp = (*root)->right;
            free(*root);
            *root = temp;
        }
        // Case 3: 2 children
        else {
            Node *successor = get_successor((*root)->right);
            // Successor is immediate right child
            if ((*root)->right == successor) {
                successor->left = (*root)->left;
                free(*root);
                *root = successor;
                return;
            }
        }
    } 
}


int main() {


    return 0;
}