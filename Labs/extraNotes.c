/*

- -l to link libraries
    -lm to link math.h
    -lc to link string.h
- when using headers, need to link the .c file containing the function as well
    - can only be one main function

Commands:
    - ceil - rounds up. math.h
    - floor - rounds down. math.h
    - pow(x, y) - x^y. math.h
    - strstr(const char *haystack, const char *needle) - finds the first occurance of needle in haystack.
                                                         returns pointer to occurance. strcasestr() is the
                                                         same but it ignores capitalization in both. string.h
    - strcat(string 1, string2) - concatenates 2 strings. string.h

- when reallocating memory in a function, need to pass in a pointer of a pointer to the block of memory
    - realloc might change the location so you need to reassign the pointer in the function
*/