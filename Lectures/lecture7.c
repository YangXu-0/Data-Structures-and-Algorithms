/*
int** x = (int **)malloc(sizeof(int*) * 5);
for (int i=0; i<5; i++) {
    *(x+i) = (int *)calloc(2, sizeof(int));
}

    - ^ creates a calloc pointer in each space of the initial malloc
    - need 6 free calls, 1 for malloc and 5 for calloc
    - malloc pointer is stored in int** since each space is a pointer space

- when reallocating in a function, you need to pass in a double pointer to memory since you
  need to reassign the pointer since realloc may adjust the address

- Structure variables
    - Allow us to group variables as a new data type
    Ex. Declaring and initializing a pricetag struct
struct pricetag {
    double price;
    double sale_price;
    char item_name[100];
}; // don't forget the ;
struct pricetag new_item = {10.99, 4.99, "Shelf"};  // same order

    Ex. declaring and initializing a price tag structure using typedef
typedef struct {
    double price;
    double sale_price;
    char item_name[100];
} pricetag;
pricetag new_item = {10.99, 4.99, "Shelf"};  // same order

- Can also initialize and access the structure members using .
    struct pricetag new_item;
    new_item.sale_price = 0.25;

- Passing a structure variable to a function makes a copy of the structure variable (and all of its members)
- It is often more efficient to pass a pointer to a structure variable
    struct pricetag *ptag_ptr;
    ptag_ptr = malloc(sizeof(struct pricetag)); // not sizeof(ptag_ptr)
    (*ptag_ptr).sale_price = 0.15;
        or
    ptag_ptr->sale_price = 0.15;

- Structs are passed outside of main
- Structs are also copied when passed into functions, need to pass in pointer to change
- Structs are mutable
- When creating structs with pointers, need to cast the memory type for some reason
*/