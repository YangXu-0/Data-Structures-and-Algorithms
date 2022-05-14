/*
- Modern computer storage built with transistors --> base-2 number systerm
- A transistor is a tiny electrical switch that has two states: {ON, OFF}
    - Alternatively, with ON = 1 and OFF = 0 the states of a single transistor can be declared as {1, 0}
- 3456 base 10 = 110110000000 base 2 -- (1 x 2^11) + (1 x 2^10) + (1 x 10^8) + (1 x 10^7)
    - Base 2 has coefficients of 0 or 1
    - Goes all the way to num^0 (for 1s)
- Each digit in binary or base 2 representation is called a bit
- DEFINITION: least-significant bit (LSB or right-most bit) is the digit that is the co-efficient of 2^0
- DEFINITION: most-significant bit (MSB or left-most bit) is the digit that is the co-efficient of highest power of 2 used
- Data stored in bits
    - Numeric data
    - ASCII and UTF-8 are encoding standards used to represent text as numbers
- The file system
    - DEFINITION: directories contain other directories and files
        - Parent directory - big directory containing other directories
        - Child directory - directory in the big directory
        - Descendant - inside another directory
        - Ancestor - big directory
    - DEFINITION: files are ordered sequences of bits that store data
    - All file systems have a root directory that is the ancestor to all directories
    - Path - location of file or directory, relative path - location relative to a particular directory, absolute path - path from root
    - . - represents directly currently in

- SSH
    - ssh <utorid>@remote.ecf.utoronto.ca
    - Enter password, it won't show as a security feature
    - Commands:
        - whoami - prints user
        - hostname - prints host
        - pwd - prints absolute path of the present working directory
        - ls <path> - list directories and files in path. no argument --> current directory
        - cd <path> - change directory to path. no argument --> home directory
        - mkdir <path> - make a new directory at the absolute or relative path indicated in <path>
        - rmdir or rm -d <path> - delete a directory or file
            - rm -r <path> to delete non-empty directories
        - touch [filename] - creates a file
            - can also be used to adjust access, change, and modification times
        - nano - basic text editor
            - ctrl + O to save, ctrl + x to exit
        - ctrl + d to exit session

    - Directory symbols:
        - ~ home directory
        - / root directory
        - . current directory
        - .. parent directory

*/