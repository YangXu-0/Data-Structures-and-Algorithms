/*
Stack pop vs Python pop
- Popping an element from a stack removes the element at the top
    - Should check if the stack is empty before popping
- Python pop removes element at a specific index or last by default
    - If index not in range, you get an exception

Need Pop/Dequeue
- Free memory
- Pop/dequeue when you are about to
    - About to process the next item or finished with item

- Stack implementation
    - Dynamic array
        - Right most element is the top of the stack
        - If resizing is needed, elements stay in the same index positions
        - Keep track of last element index and array size
    - Linked list
        - Front of the list is the top of the stack
            - Push/add to front, pop/remove from front
            - No need to keep traversing the list or keep track of the end of the list
    - Potential helper functions
        - Check if the stack is empty before popping
        - Array implementation: check if the stack is full before pushing


*/