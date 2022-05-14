/*
Struct exercises in slides

- When initializing the string arrays, it's basically 1 char per space (1 byte) and the +1 for the null char
- Remember string literals "" are not supposed to be modified

- Streams refer to sources of input or destinations for output
- Access streams using a file pointer (FILE *)
- Standard streams from stdio.h are
    - stdout, stderr - outputs to screen
    - stdin - inputs from keyboard
- Can open as streams to read from or write to
- Opening a file as a file stream
    - FILE *fopen(const char *filename, const char *mode);
        - Use / or \\ for file paths
        - Modes: "r" read, "w" write, "a" append
        - Returns FILE* to use the file as a stream
        - Returns a null pointer if the file can't be opened (missing, errors, etc.)
- Closing a file
    - int fclose(FILE *stream);
        - Returns 0 if successful, otherwise returns EOF (negative integer constant) as error code

- Writing
    - int printf(const char *format, ...);
        - Writes a formatted string (format) to stdout
    - int fprintf(FILE *stream, const char *format, ...);
        - Writes a formatted string to a file stream
    
- Reading
    - int scanf(const char *format, ...);
    - int fscanf(FILE *stream, const char *format, ...);
        - Reads a formatted string (format) to a file stream
    - when passing in the variable, it needs to be a pointer to the variable
        - can use &

- Returns number of characters written, number of items read
    - Returns EOF if error occured when writing/reading

- Output
    - int fputc(int c, FILE *stream);
        - Write one char to a file stream, returns the written character
    - int fputs(const char *s, FILE *stream);
        - Write a string s to a file stream

- Input
    - int fgetc(FILE *stream);
        - Read and return one char from a file stream, returns non-negative number
    - char *fgets(char *s, int n, FILE *stream);
        - Read a string until either a newline character or n-1 characters + '\0' from a file 
          stream and store in s

- Errors and end-of-file will return EOF
    - fgets() will return a null pointer

- Add space in front of %c in scanf to get rid of white space
    - scanf(" %c", ...)

- Reading and writing practice in files

- Linux commands for files:
    - cat filename.txt - list contents of filename.txt
    - cat -n file.txt - list contents of file.txt with line numbers
    - cat file1.txt file2.txt - list contents of file1.txt and file2.txt
    - cat > newfile.txt - create newfile.txt, enter contents, ctrl+D to save
    - cat file.txt > copy.txt - output file.txt contents to copy.txt, old content overwritten
    - cat >> new.txt - append to new.txt, enter contents, ctrl+D to save
    - man cat - manual page for help on using cat
    - less file.txt - list contents of file.txt
                        up/down keys to scroll lines
                        b/space to scroll pages
                        g/Ng/G to go to first/Nth/last page
                        h for help
                        q to exit
    - less file1.txt file2.txt - list contents of file1.txt and file2.txt
    - less -N file.txt - list contents with line numbers
    - less +n file.txt - list line n of file.txt
    - less +/string file.txt - list line of file.txt containing string, n to find next, N to previous
    - cat file1.txt file2.txt | less    # piping
        - sends results of first command to second command
*/