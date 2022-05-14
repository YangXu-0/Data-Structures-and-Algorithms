/*
- In worst cases, BST is extremely imbalanced and looks and behaves like a linked list
- If can keep balanced, can avoid O(n) runtime

AVL Trees
- Self-balancing BST
- Modify the insert and delete operation so that the BST stays balanced
    - Maintain a height of logn
    - Worst case insert, delete, search should be O(logn)
- To balance the tree we will:
    - Identify a height imbalance
    - Remedy the imbalance with rotation operations

Balance Factor
- The balance factor of a node is: (height of the right subtree) - (height of the left subtree)
- Height of a node is the number of edges from deepest leaf to that node
    - Leaf nodes have height 0, empty node can be treated as height-1
    - Height of a node will be (max height between the children)+ 1
- A tree is balanced if every node has a balance factor of (-1, 0 , 1)

Rotations
- We want to torate nodes to balance the tree and maintain BST property
    - After insert.delete ,check the balance factors
- Four possible balance violations, 4 possible rotation strategies
    - Right right violation, rotate left (single rotation)
    - Left left violation, rotate right (single rotation)
    - Right left violation, rotate right-left (double rotation)
    - Left, right violation, rotate left-rgith (double rotation)
- Outside imbalance: right right and left left violations
- Inside imbalance: right left, left right violations

AVL Tree - Runtime Complexity
- Notice that rotating doesn't depend on the number of nodes, n
- But we have to check that all the ancestors are balanced after an insert/delete, so a maximum of logn checks could be done
- Insert: O(logn)
- Delete: O(logn)
- Search: best O(1), worst O(logn)
*/