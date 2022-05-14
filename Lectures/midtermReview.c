/*
Things to memorize:
    string.h commands:
        - char* strcpy(char* s1, const char* s2)
            - copies s2 into s1 (doesn't check the size of s1)
        - size_t strlen(const char* s);
            - Returns the length of string s (not including null character)
            - size_t is an unsigned int
        - char* strcat(char* s1, const char* s2);
            - copies s2 to end of s1 (doesn't check size of s1)
        - int strcmp(const char* s1, const char* s2);
            - Returns an integer that indicates if s1 is >, =, or > compared to s2
            - Comparison is based on lexicographical order (dictionary order) and ASCII
                - ASCII table space < digits < uppercase letters < lowercase letters
            - returns 0 if strings are equal
            - >0 if first non-matching char in str1 is greater than str2
            - <0 if first non-matching char in str1 is smaller than str2

Notes:
- All variables declared in loops and if-else blocks are local to those blocks
    - Even i
    - Will cease to exist on next iteration or once the block finishes
- Arrays generally decay into pointers but not always
    - Ex. when it is the argument to the sizeof operator
    - Decays when passed in as a parameter
- Remember to add null character to char arrays
- Storing string in array --> char array. Storing array with char pointer --> string literal (or string constant)
    - Pointer method is immutable, array method is mutable
    - Character pointers can point to character arrays (mutable string)
- to convert between char ints and ints, can subtract by '0' (or 48)
- Big O notation defines an upper bound for the runtime complexity
- Omega notation defines lower bound
- Theta notation defines upper and lower bounds
- Quick sort worst case vs best case is due to number of levels
- Avoid using the indirection operator on an uninitialized pointer variable
- Cannot make array starter pointer point to a different list
- If pointer is a null pointer, realloc becomes a malloc call. If size 0, becomes a free call
- Passing a structure variable to a function makes a copy of the structure variable (and all of its members)
- atoi and atof return 0 for "0" and for not a number
    - need isdigit(int character) from ctype
        - returns non-zero integer for numeric characters
        - returns 0 for non-numeric characters
- For adts, need to be careful of pushing to full arrays or popping from empty arrays
- Don't forget, values can be assigned to structs with {}
- When dividing, remember that / can return an int or a float depending on what data types are involved
- w writes freshly (overwrites everything), a appends to the end (works even with blank file)
- be careful of file position pointers, especially when using multiple modes at the same time
    - ex. a+ --> fgets sets position to first line, fputs sets position to last line, so any additional
      fputs will read nothing
- be careful with iterating through dynamic arrays of pointers (don't dereference before adding i)
- if there is a combination of & and *, order does matter and it's from inside out
- when you create a struct var, set all values before accessing, even if you have to set it to NULL or smth

- Is popping from an array actually just copying everything to another one except the one you don't want?

Practice:
- Recursion                                         (done)
- Operations with files                             (done)
- Try and implement all the sorting algorithms      (done)
- Complexity analysis
- Do questions in lecture                           (done)

Questions:
1. What are directives?
*2. What are the different data types, what are their required memory, and what is their
   format specifier?
3. How do you choose the number of digits to display for floats when using format specifer?
4. What is integer overflow and how does it change between unsigned and signed ints?
*5. What is operator precedence? (lecture 2)
6. How are if-else blocks different from Python?
7. Is 0 true or false? Other number? NULL?
8. How does putting ++ before and after change the result?
9. How do you use header files?
10. How do you use define and what is unique about it?
11. What is important to note about passing in parameters for the string.h library?
*12. What are static arrays?
*13. For the following sorting algorthims, state how it works, best case run complexity, and worst case run complexity:
    Insertion sort, selection sort, bubble sort, merge sort, quick sort?
14. In general what are the fastest run times for best case and worst case?
15. What if the arrays were of different lengths in merge sort?
16. What is the runtime complexity of comparing 2 strings?
17. What is the indirection operator and what does it do?
*18. What is pointer arithmetic? What is the difference between *array_ptr and my_array[0]?
19. How do you allocate and free memory? What library are these functions a part of? What does void * mean? 
    What is returned if memory is not allocated?
20. What happens to the memory block during realloc? What does it return if fail?
21. How do you create a dynamic array of dynamic arrays?
*22. What are the 2 ways of declaring a structure? What are the differences?
*23. How do you use a pointer to create an instance of a struct?
24. What are the two ways of accessing attributes in a struct?
25. What are streams? How do you access them? What are the standard streams from stdio.h?
26. How do you open and close a file?
27. How do you read and write to a file? What do these functions (including the ones above) return?
*28. What do fputc, fputs, fgetc, and fgets do? What do you need to pass in? What do they return
29. What is a data structure?
30. How do you set up linked lists? What do you have to be careful about with next? What operations are there generally? 
    What do you have to be careful about? What is their O?
31. What are the pros and cons for linked lists vs arrays?
32. What does getline, atoi, and atof do? What libraries are they from?
33. How can you implement linked list functions with recursion?
34. What is an abstract data type? What are stacks and queues? What are the operations for each?
35. What is the O for these operations?
36. What are priority queues and circular queues?
*/