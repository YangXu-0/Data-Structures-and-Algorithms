/*
Abstract Data Types
- Classification of data structures
- For each ADT, behaviour is defined but not implementation

- Recall linked lists
    - A chain of linked node structs
        - Each node contains data and a pointer to the next node
        - Variations in implementation i.e. node structure 
    - Insertion, deletion, indexing behaviour is defined

Stacks
- ADT that follow last in first out (LIFO) order
- Operations:
    - Peek - read the top element
    - Pop - remove the top element
    - Push - add element to the top
- Implementation
    - Linked list
        - Add to front, remove from front
        - Add to back, remove from back
    - Dynamic array
        - Add to end, remove from end
        - Add to front, remove from front

Queues
- ADT that follow first in, first out (FIFO) order (or last in, last out (LILO))
- Operations:
    - Peek - read the front element
    - Dequeue - remove element at the front
    - Enqueue - add element to the back
- Implementation:
    - Linked list
        - Add to back, remove from front
            - Add: traverse or use tail pointer
        - Add to front, remove from back
            - Remove: traverse or use previous node pointers
    - Dynamic array
        - Add to back, remove from front
        - Add to front, remove from back
        - In both cases, shuffle elements when modifying the front
            - Or loop the queue around

- Runtime Complexity
    - Stacks
        - Linked list - operations using the head pointer/front of list as the top
            - All operations O(1)
            - If don't have last pointer, need to walk through which becomes O(n)
        - Dynamic array - operations and tracking with the last element index as top
            - Peek, pop, push, are all O(1)
            - If need to resize
                - If need to copy all elements to another location, will be O(n)

    - Queue
        - Linked list - enqueue at back, dequeue at front
            - Peek and dequeue are O(1), enqueue is O(n) (if no pointer)
            - Add tail pointer to make enqueue O(1)
        - Dynamic array - enqueue at back, keeping track of last element index
            - Peek, push are O(1), pop is O(n) - if don't have to resize
            - Pop can be O(1) if you track the front index and don't shuffle elements or resize

- Both stacks and queues can operate at O(1)
- Use stacks
    - When prioritizing the most recent data
    - E.g. function call stack, displaying notifications, undo typing
- Use queues
    - When there is an ordered line-up
    - E.g. allocating memory, customer service, data processing
    - Priority queues
        - Every element has a priority value
        - Dequeue by priority, then FIFO order
    - Circular queues
        - Back of queue loops to front
*/