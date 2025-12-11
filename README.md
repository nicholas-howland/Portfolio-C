# C Portfolio
C programming language portfolio created during a C and Unix programming college course. The following are programs that are contianed in this repo and their purposes.

## compile.sh
Simpler compile script that is easy to understand. Checks for the existance of bin and source directories as well as checking for a 00-template.c file. Creates files and directories as needed and then will compile the script with valgrind a super handy c compiler that will alert the developer to issues in the c code. flags are as follows:
-e \<file-name-without-extension\>  will edit and compile the file without 
-c \<file-name-without-extension\>  will compile source code for a file if it exists

## arrays.c
Using both indexes and pointers to traverse arrays

## dynamic-arrays.c
Creating dynamic arrays through the use of memalloc realloc and sentinal values as well as through the use of defined array lengths

## files.c
Working with files in c examples and basics

## input.c
Working with user input

## if-statements.c
Contains some if statement logic and variuble declarations.

## loops.c
Using loops like while and for to count numbers

## memory.c
Using malloc, realloc, and free functions when altering the size of arrays

## pointers.c
Using pointers to assign values to memory addresses, printing memory addresses of both pointer locations as well as destinations

## structs.c
Working with structs in c.

## windows-threading.c 
Windows threading example vibe coded, reference only.

## LinkedList
This is a directory with the code required to create a linked list that can be interfaced with via direct calls. Without any edits the user is thrown into a menu driven linked list interaction interface. The interaction interface allows the user to display the list, insert a new value at the end of the list, remove the first occurance of a value in the list, sort the list from least to greatist, clear the list, and quit out of the menu. It uses a .h and .c file in the subdirectory named LinkedList. The .c file is where all of the functions to create, delete, add to, remove from, and sort the linked list live.
