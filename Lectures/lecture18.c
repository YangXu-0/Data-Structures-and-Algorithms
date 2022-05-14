/*
Implement a a complete binary tree using a dynamic array:
- Insert: append to array at index n (the current number of elements)
- Search : traverse the array to look for a value
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Struct for our complete binary tree
typedef struct bin_tree {
    int *tree;
    int size;
    int count;
} bin_tree;


// Initialize tree
bin_tree *plant_bt(int rval) {
    // allocate memory for tree
    bin_tree *bt = (bin_tree *)malloc(sizeof(bin_tree));

    //Setting the root and more
    bt->tree = (int *)malloc(sizeof(int));
    (bt->tree)[0] = rval;
    bt->size = 1;
    bt->count = 1;

    return bt;
}

// Insert value
void insert(bin_tree *bt, int val) {
    // Check if full
    if (bt->size == bt->count) {
        bt->tree = realloc(bt->tree, sizeof(int)*(bt->size)*2);
        bt->size = (bt->size)*2;
    }

    // Insert value
    (bt->tree)[bt->count] = val;
    (bt->count)++;

    return;
}

// Look for value
int search(bin_tree *bt, int val) {
    // iterate through array to look for value;
    for (int i = 0; i<(bt->count); i++) {
        if ((bt->tree)[i] == val) {
            printf("Found value");
            return 1;
        }
    }

    printf("Did not find value");
    return 0;
}

// Free tree
void free_bt(bin_tree **bt) {
    free((*bt)->tree);
    free((*bt));
    *bt = NULL;
}

int main() {
    return 0;
}