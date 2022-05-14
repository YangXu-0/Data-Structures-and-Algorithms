/*
Trees
- Linked lists, stacks, and queues are linear data structures
    - Nodes are sequential

- Trees are hierarchical data strucutres, storing data nonlinearly
    - Nodes are connected by edges
    - Pass a pointer to root of the tree
        root->left or root->right
        root->left->left or root->left->right
    - Can be implemented with arrays
        - Indexing nodes is more complicated

Terminology
- Nodes are connected by edges
    - Parent nodes contain edges to children nodes
- Every node except the root node has exactly 1 parent node
    - Must be exactly 1 root
- Every node has zero or more children nodes
    - Nodes with zero children are called leaf nodes
- Parentage defines the ancestor-descendant relationship
    - All nodes are descendants of the root
- Node depth/level is the number of edges between a node and the root
    - Root has 0 depth
- Height of a node is the number of edges from the node to the deepest leaf
    - Longest path from the node to a leaf
    - Height of a tree is the height of the root
    - Height of a leaf is 0
    - Height of an empty tree is treated as -1
- Subtree - basically sub trees

- binary trees - a type of tree
    - Every nodes has at most two children
- Complete binary trees - every level except the last is completely filled
    - Last level is filled starting from the left
- Balanced binary tree
    - Difference between the height of left and right subtree for each node is either 0 or 1



*/