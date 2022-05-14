/*
Heapify
- Restoring the heap property
    The swapping part of the insert and remove operations
- Insert: swap_up() to move newly inserted node into place
    - Also called bubble up, sift up, swim up, heapify up
- Remove: swap_down() to move rpelacement root into place
    - Also called bubble down, sift down, swim down, heapify down
- Doesn't necessarily have to be recursive

- Other terminology
    - Insert is sometimes also called push
    - Remove is sometimes also called delete, remove, pop

Heap Sort
Ex. sorting an array of n elements
1. Make a heap
    Option 1. create a new heap (not in place) -> O(nlogn)
        - Insert one element at a time (heapify up each time)
        - Notice leaf nodes tend to need more operations
    Option 2. heapify the array (in place) -> O(n) (don't need to derive for exam)
        - Heapify down the nodes from last leaf to root
        - Treat the leaves as heaps (no heapifying needed)
        - Notice the root tends to need more operations
2. Extract from the heap n times
    - Remove + heapify down, one element at a time
    - Assign to new array (not in place) or sorted section (in place)

Overall heapify + extractions is O(n + nlogn) -> O(nlogn)

Priority Queues
- A priority queue is a type of queue where higher priority elements can skip ahead for processing
- Recall queues: data structure following first in, first out (FIFO)
    - Enqueue at the back, dequeue at the front
    - Back and front of the queue are defined by implementation strategy
- We can use a heap to implement a priority queue
    - Add priority data to each node
- Options: sort by priority then arrival time, have separate heaps for each priority level and 
            sort each by arrival time, etc.
- Insertion of n elements -> O(nlogn), n elements * logn comparisons
    - Compared to linked list -> O(n^2), n elements * n comparisons
*/