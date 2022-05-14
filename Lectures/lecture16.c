/*
- Binary search trees are a type of binary tree where:
    - The left descendants contain values smaller than the ancestor nodes
    - The right descendants contain values larger than the ancestor nodes
- All BSTs are BTs
- Not all BTs are BSTs

- When trying to find a value in a tree,
    - With normal trees you need to check values essentially randomly until you find it
    - But with binary trees, you can go by size of the node to choose if you go left or right
- Thinking about the worst case:
    - For an unsorted binary tree, you need to visit every node
        - For a linked list where the node of interest is the last node
    - For a binary search tree, you will visit height + 1 nodes
        - Visit one node per level from root to furthest leaf
        - +1 because the height counts edges not nodes
- If a tree is very unbalanced, the tree becomes a linked list
- This is true for unsorted binary trees and binary search trees

- Min/max heap
    - A type of complete binary tree
    - Must  satisfy the min/max heap property
        - For a min heap: all descendant nodes must have bigger values than their ancestors, root
          contains the minimum value
        - For a max heap: all descendant nodes must have smaller values than their ancestors, root
          contains the maximum value
    - To maintain heap properly
        - When removing, remove root and shuffle nodes
            - Heap sort!
        - When inserting, add to first available space and shuffle nodes
            - Priority queue!

- Binary trees using arrays
    - Indexing starting from 0:
        - If parent is at index n, left child is 2n+1, right child is 2n+2
        - Insert at size index
    - Indexing starting from 1:
        - If parent is index n, left child is 2n, right child is 2n+1
        - Insert at size + 1 index
    - Can do whichever basically
    - Leave empty spaces for gaps in tree so that it can be referenced later if needed
*/