Writing a simple UNIX command interpreter

shell.h
This code defines various constants, structures, and function prototypes used in a simple shell program.

_atoi.c

This part of the code is a C program which defines four functions: interactive, is_delim, _isalpha, and _atoi. These functions are then used in other parts of the program for specific purposes.

builtin.c

This C code has three functions that are part of a shell program.
 1. #include "shell.h" -  is a preprocessor directive that includes the contents of the file "shell.h" in the C file
 2. _mycd - It takes a pointer to an info_t structure as an argument whose purpose is to change the current directory of the process.
 3. _myhelp - It also takes a pointer to an info_t structure as an argument whose purpose is to display a help message.

builtin1.c contains the following functions
1. myhistory - The function calls the print_list function passing in the history list contained in the info structure
2. unset_alias - The function sets an alias to a string. It searches for the position of the character in a str using the _strchr function.
3. set_alias - . It searches for the position of the character = in str using the _strchr function. If it does not find the character, it returns 1. If the character immediately after = is empty, it calls unset_alias function passing in info and str. Otherwise, it calls unset_alias function passing in info and str.
4. print alias - The function prints an alias string if the node is not NULL

environ.c
 The code consists of several functions that relate to manipulating and accessing environment variables

errors.c
This is a C code that defines several functions for outputting strings and characters to standard error and to other file descriptors

errors1.c
This is the C code that includes a header file called "shell.h".

exits.c
The function takes in three parameters:
1. dest is the destination string to be copied to
2. dest is the destination string to be copied to
3. n: the amount of characters to be copied.

getline.c
This part includes several functions related to getting input from the user through the command line interface

getenv.c
This code as part of a shell program, provides some functionality related to managing environment variables.

getinfo.c 
gets information on the shell using the commandline interface.

history.c
This part of the code implements a command history feature for a shell program. It includes functions for getting the history file location, writing history to a file, reading history from a file, building a linked list of history entries, and renumbering the history after changes.

lists.c
The code defines a linked list data structure in c and provides functions to manipulate it.

lists1.c
This defines a set of functions for manipulating a linked list data structure.

main.c
This part of the program includes the "shell.h" header file and defines the main() function, which is the entry point of the program.

memmory.c
This is a C language function bfree() that takes a pointer to a pointer (void **ptr) as its argument and frees the memory allocated to it.

parser.c
These are three C language functions, is_cmd(), dup_chars(), and find_path()that are related to finding and executing commands in a shell program.

realloc.c
Contains three function
1. memset function, which fills a block of memory with a given value
2. ffree function, which frees a string of strings.
3. _realloc function, which reallocates a block of memory

string.c
This code consist of four functions: _strlen(), _strcmp(), starts_with(), and _strcat(). These functions are defined in the header file shell.h and are intended for use in a shell program.

string1.c
These are several string manipulation functions used in a shell program

tokenizer.c
It defines two functions, strtow() and strtow2(), that split a string into an array of words based on a specified delimiter.

vars.c

