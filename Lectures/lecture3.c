/*
- declare an array with: data_type name[number_of_elements]
    - access the elements of the array by indexing like in python
    - zero indexed
        -indexes range from 0 to number of elements - 1
    - can declare array with initialization
        - leave the [] blank, put elements after equals sign in {}
            - int my_array[] = { 1, 2, 3, 4 }
    - aliasing when passing arrays into function still exists

- can use #define to define vars as well
    - replaces the var for the value in the code during the preprocessing step
        - Ex. #define ARR_LENGTH 5
            - bypasses type declaration

- no string data type in C
    - stored as character arrays that end with the '\0' null character
        - null character has integer value 0, evaluates to False
            - when declaring array manually, need to leave space for null character (won't add automatically)
    - "" is used for strings, '' is used for chars
    - can also declare with a pointer
        - ex. char* my_ptr = "hello world"; called a string literal or a string constant
        - pointer method is immutable, array method is mutable
    - character pointers can point to character arrays (mutable string)

<string.h>
- char* indicates the string will be modified by the function
    - const char* indicates it is okay to use a string literal (won't be modified)
    - ex. char* strcpy(char* s1, const char* s2);
commands:
    - char* strcpy(char* s1, const char* s2)
        - copies s2 into s1 (doesn't check the size of s1)
    - size_t strlen(const char* s);
        - Returns the length of string s (not including null character)
        - size_t is an unsigned int
    - char* strcat(char* s1, const char* s2);
        - copies s2 to end of s1 (doesn't check size of s1)
    - int strcmp(cosnt char* s1, const char* s2);
        - Returns an integer that indicates if s1 is >, =, or > compared to s2
        - Comparison is based on lexicographical order (dictionary order) and ASCII
            - ASCII table space < digits < uppercase letters < lowercase letters

- when looping through character arrays, it is possible to loop onto the null character so be careful
    - especially with while loops

- to convert between char ints and ints, can subtract by '0' (or 48)


*/