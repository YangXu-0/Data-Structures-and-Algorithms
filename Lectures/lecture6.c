/*
- When a variable is declared, there is a unique place in computer memory (memory address) for storing the 
  variable's value
    Ex. 
    int x = 5
    x is an integer variable
    the value of 5 will be stored at the memory address of x

- Pointer variables store a memory address as their value
    - Declaring a pointer variable looks like this
        data_type *pointer_variable_name;
    Ex:
        int *y;   y stores the address of an int 
        int **z   stores the address of an int * (pointers to pointers)

- the address operator & gives the memory address of a variable
- &variable_name gives the address of variable_name
Ex.
    int x = 5;
    int *y = &x;
    int **z = &y;
- Use the %p format specifier to specify memory addresses

- * is used to declare a pointer variable and is also used as an indirection operator
  to store the value stored at a memory address (de-referencing)
Ex.
    printf("The value stored at &x is :%d\n", x);
    printf("The value stored at &x is :%d\n", *y);
    printf("The value stored at &x is :%d\n", **z);

    printf("The value stored at &x is :%d\n", *(&x)); this works too but why

- Indirection operator (*) allows us to change the value stored at the memory address the pointer points to
    - The values on each side needs to match (typing)
- Avoid using the indirection operator on an uninitialized pointer variable
    Ex.
    int *y;                    no initial value assigned
    printf("%d\n", *y);        undefined behaviour
    *y = 5;                    undefined behvaiour

- Common question on exams is to trace the code (example on slides)

- Passing an integer as an argument to a function:
    - The function gets a copy of the value of the integer variable
    - To modify the original variable, we have to return and assign the new value
- Passing an integer point variable as an argument to a function:
    - The function gets a copy of the memory address stored in the pointer
    - We can modify the value at the memory address
    - Basically you can change the value now

- We can pass char arrays to string.h functions that expect char * because array variable names
  are pointers to the first element of the array
    Ex.
    int my_array[] = {1, 2, 3, 4, 5};
    *my_array = 5;   is the same as my_array[0] = 5
    int *array_ptr = my_array;    don't need to use &
                                  int *array_ptr = &my_array[0]
- Cannot assign new values to array variable names
    - Cannot make them point to a new memory address (basically can't reassign them to a different list)

- We can add/subtract integers to/from pointers to access other elemnts
    - If array_ptr points to my_array[j], then array_ptr + k points to my_array[j + k]
- can iterate through array elements with loops with i++ :
    - my_array[i], *(my_array+i), or *(array_ptr+1)

- We can subtract points to get the distance (unit = number of elements)

- Dynamic memory/storage allocation
    - Refers to allocating memory during program execution
        - Normally memory for variables is static
            - Automatically freed as functions return
        - Dynamically allocated memory can shrink/grow in size throughout the program
            - Is reserved and lingers until we free it ourselves
            - Keep track of any allocated memory until it is freed (have a pointer or something)
    - Allocating memory:
        - Allows us to make arrays, etc. that can change size (recall Python's list.append())
        - Allows us to return the addresses of new values generated in a function
    - Freeing memory:
        - Free any allocated memory before the program ends to avoid memory leaks
        - Do not try to access memory that has already been freed

#include <stdlib.h>
- void *malloc(size_t size);
    - Allocates a block of (uninitialized memory), size specifies the block size)
- void *calloc(size_t nmemb, size_t size);
    - Allocates the memory, nmemb * size, each initialized to 0

- return type void * meants it returns to a generic pointer (memory address) that you can cast to int *, char *, etc.
- If a memory block can't be allocated, a null pointer is returned
    - Good habit to have an if statement to check for this before use

- void *realloc(void *ptr, size_t size);
    - Resizes the block of memory to pointed to by ptr
    - ptr should point to a memory block from prior malloc(), calloc(), realloc()
        - If ptr is a null pointer, this becomes a malloc() call
    - New size of the memory block will be size
        - If size is 0, this becomes a free() call
        - Expanding: no initialization of added memory, data may be copied to another area of memory (remember
          to updated any points to original *ptr)
        - Shrinking: done in-place, no movement of data, update points to be safe

-void free(void *ptr);
    - Frees the memory block ptr points to. Nothing happens if ptr is a null pointer

- be careful of order of operations when using pointers
- cannot add pointers 
- cannot divide or multiply pointers
*/