/*
Heapsort: sorting alg that uses a heap
Heapify: restore the heap property

Deletion steps: remove root, replace with last node, heapify down
Best case: no/minimal heapifying down, O(1) if constant as n->infinite
    - All nodes contain the same value
    - One operation heapify needed - the new root is in the correct place after one swap with it's child
- Common pitfalls:
    - Losing nodes( and memory)
        - Unlinking trees, overwriting pointers, freeing too soon
    - Bad memory access
        - Trying to access the left/right/value of free'd/null points/nodes
    - Making a circular tree
        - Tends to result in infinite loops
- Case 3: node to be deleted has two children
    - Could have replaced the deleted node with its predecessor
    - Predecessor is the largest/right-most node in the left subtree
        - Replace predecessor with it's left child

BST Operations - Runtime Complexity
- Insert
    - best case: O(1) root has one child empty and this is where we insert
    - worst case: O(n) completely unbalanced tree (looks like a linked list) and we insert at the end of the chain
- Search
    - Best case: O(1) root contains the value we're looking for
    - Worst case: O(n) completely unbalanced tree (looks like a linked list) and the node we're looking for
                  isn't in the tree or is the last node
- Delete
    - Search for node to delete: O(1) or O(n)
    - Deleting when node is found
        - Best case: O(1) node has 0-1 children
        - Worst case: O(h) node has two children and the predecessor is located h nodes away (h = height of right subtree)

Binary Tree Traversal
                0
            1       2
          3   4   5   6

    -Depth first searching
        - Explore a branch fully before back-tracking and doing further exploration
    - Pre-order: current/root, recurse left, recurse right
        - Visitiation order: 0, 1, 3, 4, 2, 5, 6
    - Post-order: recurse left, recurse right, current/root
        - Visitation order: 3, 4, 1, 5, 6, 2, 0
    - In-order: recurse left, current/root, recurse right
        - Visitation order: 3, 1, 4, 0, 5, 2, 6


Breadth First Search
- Visitation order: 0, 1, 2, 3, 4, 5, 6
- Explore nodes at a certain depth before moving to the next depth level
- Use a queue to keep track of discovered nodes to be explored
- Start by enqueueing the root node
    - Dequeue and mark dequeue-ed node as visited
    - Enqueue node's left and right children (if any exist)
    - Repeat dequeue/enqueue steps until no nodes in left queue
*/

#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

void delete_BST(Node **root, int search_value) {
    if((*root) == NULL) {
        return;
    }
    if ((*root)->value == search_value) {
        // Case 1: no children
        if ((*root)->left = NULL && (*root)->right == NULL) {
            free(*root);
            (*root) = NULL;
            return;
        }
        // Case 2: 1 child
        else if ((*root)->left != NULL && (*root)->right==NULL) {
            Node *temp = (*root)->left;
            free(*root);
            *root = temp;
            return;
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
            else { // successor is not the immediate right
                (*root)->value = successor->value;
                delete_BST(&((*root)->right), successor->value);
                return;
            }
        }
    }

    if ((*root)->value < search_value) {
        delete_BST(&((*root)->right), search_value);
    }
    else {
        delete_BST(&((*root)->left), search_value);
    }
}

Node *get_successor(Node * root) {
    if (root->left == NULL) {
        return root;
    }
    else {
        return get_successoro(root->left);
    }
}

void print_preorder(Node * root) {
    if (root==NULL) {
        return;
    }
    // current
    printf("%d ", root->value);
    //recurse left
    print_preorder(root->left);
    //recurse right
    print_preorder(root->right);
    return;
}

void print_postorder(Node * root) {
    if (root==NULL) {
        return;
    }
    //recurse left
    print_postorder(root->left);
    //recurse right
    print_postorder(root->right);
    // current
    printf("%d ", root->value);
    return;
}