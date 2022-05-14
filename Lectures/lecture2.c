/*
fprintf(stdout, text) - basically specifies where the output goes but using stdout is the same thing

operators:
    - basically the same
    - && for and
    - || for or

++var increments the var before its value is used
var++ increments the var after its value is used

&, |, &, <<, >> are bit operators and are not the same as the other ones

Operator precedence:
    1. ++, --
    2. *, /, %
    3. +, -
    4. =, *=, /=, +=, -=
    Brackets always first

If statements:
    if (expression) {
        statement
    }
    else if (expression) {
        statement
    }
    else {
        statement
    }

- Every number is true except for 0
    - NULL is also false

for (initialize; termination; operation at end of iteration) {
    statements
}
    can move for conditions outside but why
    can define i outside of for loop so it wont disappear after loop is done
        variables declared when initializing for loop will only be declared in the scope of the for loop

while (expression) {
    statements
}

n = p++ + 2; both values change, p increments after assignment
n = ++p + 2; both balues change, p increments before assignment

functions must be defined before their use
    - full definition above the main() function
    - prototype above main() function, definition below main()

    - if there are multiple c file, we put the prototype in header file and have the full definition in another .c file
        - prototype is just function declaration but instead of {}, it's ;
        - #include "header_filename.h"
            - <> instead of "" for header files of C standard libraries
        - need to add the file containing the function when compiling
            - order doesn't matter, just have 1 main function

- variables declared in loops or conditionals go out of scope apparently??

- void functions just have a "return;"

*/


#include <stdio.h>

int main(int argc, char **argv) {   /* args are optional */
    printf("fuck codelite\n");
    return 0;
}

