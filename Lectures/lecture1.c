// Use C because fast, permissive, industry standard

// Must have a main() function for execution

// Python is an interpreted language, C is a compiled language
/* To run C code, need a compiler (gcc) to automate:
        - Preprocessing: making modification(s) to the program
        - Compiling the program to generate an executable file
        - Linking any extra code needed, e.g. libraries
*/

// Start with directives (preprocessor commands that start with #) (#include <stdio.h> for printf())
// Statements end with a semicolon
// return returns a value and ends the function

// is a single line comment
/* is a multi line comment */

/* Compiling
    - gcc filename.c -o filename
    - ./filename (exe)
*/

// Function definition structure: return_type function_name(parameter_type parameter_name) {
//                                      function_body_statement;
//                                }

/*
- C is a strictly typed language, need to declare variables (name and data type) before use
- Remember to initialize vars by assigning starting values
- Data types are defined by the C standard but specifics depend on OS and hardware

Type        Memory Required     Use                             Format Specifier
---------------------------------------------------------------------------------------
char        1 byte              Characters (and strings)        %c (%s for strings)
int         4 bytes             Integer numbers                 %d
float       4 bytes             Floating point numbers          %f  --  %f .numf to specify decimal places
double      8 bytes             Floating point numbers          %lf
                                (more precision)

- arg to printf() is a formatted string --> output is sent to stdout and viewable on screen
- can print values and vars using format specifier as placeholders printf(string, var/value)
    - Many formatting options vailable
        - Ex. %.2f to display 2 decimal places
- \n for new line

- all letters are stored as numbers (ascii)
    - when casting, it will just convert between

- implicit casting --> when you assign one datatype to a different format specifier
- explicit casting --> when you use a command; (data_type) value

- '' for chars, "" for strings

- signed (default) - can indicate if integer is positive or negative
    - Left-most bit of a signed integer is used to indicate if integer is +ve (0) or -ve (1)
- unsigned integers can only store positive values, but can store larger values


- overflow - when you exceed the maximum integer length
    - unsigned 32 bit int --> max is 4,294,967,295 --> circles around to 0
    - signed 32 bit int --> max is 2,147,483,647 --> might circle around, might just be error, depends on compiler

*/

#include <stdio.h>

int main(int argc, char **argv) {   /* args are optional */
    printf("fuck codelite\n");
    return 0;
}

