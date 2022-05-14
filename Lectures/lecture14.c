/*
Queue ADT
- FIFO
- No fixed implementation
- Linked list imp.
    - Enqueue at back, dequeue at front
    - Need a pointer to last node for enqueuing
    - dequeueing from back is more work than dequeueing from front
        - No need to keep traverse the list or keep track of the second last element
- Dynamic array
    - Enqueue at the right-most/larger index, dequeue from index 0
        - If resizing is needed, elements stay in the same index positions
        - Keep track of last element index and arrat suze
        - keep track of first element index, or shuffle elements left when dequeuing
- Potential helper functions
    - Check if the stack is empty before dequeuing
    - Array implementation: check if array is full before enqueuing

Adding Priority to Queues
- No set implementation for adding priority
    - Add priority variable to the struct definition
    - Could have nested linked list - each node is a priority tier linked list
        - Separate queues for each priority tier
        - Works best if the priority values are discrete, not continuous
    - Store the priority in another array, linked list, etc.
- after priority is added
    - Can either enqueue elements in sorted order
    - Can enqueue is unsorted order and find the high priority item when dequeueing

struct node {
    int data;
    int priority;
    struct node *next;
} // for linked list

struct elem {
    int value;
    int priority;
};  for array of structs

Tips for studing
- Focus on remembering the steps
    - How do you implement the different ypes of functions? (insert, push, etc.)
    - Do you need to allocate memory? How much do you need?
    - Where does the value get stored?
        - Do you need to dereference a pointer? index?
        - How do you access a field/member variable of a struct?
    - What needs to be updated and in what order?
        - Pointer, variables that track size/indexes, etc.
*/