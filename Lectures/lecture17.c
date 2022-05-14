/*
Midterm review

Runtime
Ex. Inserting a value at index i of an n-element dynamic array. What is the runtime complexity?
Best -> when inserting at very end O(1) (assuming space remains)
Average -> middle? O(n-i+1) (+1 is from insertion step)
Worst -> insert at front and reallocate O(1+n+n-i+1) -> O(n) 2n grows faster than i so i is dropped (i is at most n)
* realloc, malloc, assume it takes constant time but state on exam



*/
