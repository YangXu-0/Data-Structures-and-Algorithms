/*
What about deleting?
- Reduce node count by 1 (this is sufficient for a complete binary tree)
- Consider reducing the size(realloc() less memory) if the count is below a certain threshold
- Remember to check for an empty tree before deleting
- Write this function as an excercise

What about an incomplete binary tree?
- Need to decide how to best represent an empty node (some value ex. 0, -1)
    - If there is no appropriate value, may need to have a separate array to keep track of used indices
    - A lot of space will be wasted to maintain parent-child indexing

Runtime Complexity
- For compelete binary trees implemented as a dynamic array:
    - Insertion best case O(1)
    - Insertion worst case O(n)
    - Deletion best case O(1)
    - Deletion worst case O(n)

Min/Max Heap
- A type of complete binary tree
- Must satisfy the min/max heap property
    - For a min heap: all descendant nodes must have bigger values than their ancestors, root contains the min val
    - For a max heap: all descendant nodes must have smaller values, root contains max val
- To remain heap properly:
    - When removing, remove the root and shuffle nodes
        - Heap sort
    - When inserting, add to first available space and shuffle nodes
        - Priority queue

Min Heap Operations
- Insert
    - Insert at next available node position (maintain completeness)
    - Swap leaf with parent if necessary (maintain heap property)
- Remove
    - Remove the root and replace with last node (maintain completeness)
    - Swap root node with children if necessary (maintain heap property)

Insert - insert at next available node, swap leaf with parent if necessary
    -  Parent of node at index n is (n-1)/2, work with ints to round right child
    - Helper func: swap_up(tree index)
Remove - remove the root and replace with the last node, swap root node with children if necessary
    - For node at index n, left child is 2n+1, right child is 2n+2
    - Helper function: swap_down(tree, index)
Other potential helper funcs on slides as excercises

For a min\max Heap Implemented with Dynamic Array
- Peek -> O(1)
- Insertion
	- Best case: O(1) enough space in array and heap property is maintained right away
	- Worst case: O(n) not enough space in array and realloc() moves every element to a new memory block
		- Maintaining heap property is O(logn), swap through the height of the tree
- Remove
	- Best-case: O(1) duplicate values in the heap, new root is a child of the original root + minimal swaps needed to restore heap property
	- Worst-case: O(logn) swap through the height of the tree
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

// Insert value
void insert(bin_tree *bt, int val) {
    // check if full
    if (bt->size == bt->count) {
        bt->tree = realloc(bt->tree, sizeof(int)*(bt->size)*2);
        bt->size = (bt->size)*2;
    }
    // insert value
    (bt->tree)[bt->count] = val;
    swap_up(bt, bt->count);
    (bt->count)++;
}


void swap_up(bin_tree *bt, int cindex) {
    // check if no parent to check
    if (cindex == 0) {
        return;
    }
    int pindex = (cindex-1)/2;
    if((bt->tree)[pindex] > (bt->tree)[cindex]) {
        int temp = (bt->tree)[pindex];
        (bt->tree)[cindex] = temp;
        swap_up(bt, pindex);
    }
    
    // if don't need to swap
    return;
}


//remove min
void remove_min(bin_tree *bt) {
    printf("%d was removed\n", (bt->tree)[0]);
    (bt->count)--;
    (bt->tree)[0] = (bt->tree)[bt->count];
    swap_down(bt, 0);
}


void swap_down(bin_tree *bt, int pindex) {
    // stop at leaf node
    int lindex = pindex*2+1;
    if (lindex >= bt->count) {
        return;
    }
    // swap with smaller child
    int rindex = lindex+1, cindex = lindex;
    if (rindex <= bt->count) {
        if ((bt->tree)[rindex] < (bt->tree)[lindex]) {
            cindex = rindex;
        }
    }
    if((bt->tree)[pindex] > (bt->tree)[cindex]) {
        int temp = (bt->tree)[pindex];
        (bt->tree)[pindex] = (bt->tree)[cindex];
        (bt->tree)[cindex] = temp;
        swap_down(bt, cindex);
    }

    return;
}

int main() {
    return 0;
}