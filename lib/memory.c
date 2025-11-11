/*
Created by Nicholas Howland
Fall 2025 in CSCD 240
Purpose:
*/
// included libraries
#include <stdio.h>
#include <stdlib.h>

// will update the value in the memory address that n resides similar to globlal scope
void update(int *n) {
    *n = *n + 10;
}

// main execution area
int main(void) {
        int arr[4] = {0,1,2,3};
        printf("size of 4 element integer array: %ld\n",sizeof(arr));
        int integer=0;
        printf("size of a regular integer : %ld\n",sizeof(integer));
        printf("Size of each element in the array: %ld\n",(sizeof(arr)/sizeof(arr[0])));

/*
Note on memory allocation with malloc and realloc, always use a static variuble to define the length of
arrays technically you can just keep writing to the array but it will cause problems
*/

// create an array that will be malloced
        int length =4;
        int *allocArr = malloc(length*sizeof(int));
// print the address of the newly created int array
        printf("return address of allocArray of realloc 0x0000%xd \n",allocArr);
// add values one to 4 to the malloced array
        for (int i = 0; i < length; i++) *(allocArr+i) = i + 1;

// the following is an example of a crash because the memory is being dereferenced and values are assigned directly
//        for (int i = 0; i < length+2; i++) *(allocArr+i) = i + 1;
// another crash example
//        for (int i = 0; i < length+2; i++) allocArr[i] = i + 1;

        printf("Size of array created using malloc: %ld\nContents of the array: ",sizeof(allocArr));
// print out the values
        for (int i = 0; i < length; i++) printf("%d ",allocArr[i]);
        printf("\n");

// change the length of the array and reallocate the memeory to reflect the new length
        length = 20;
// reallocate the array
        allocArr=realloc(allocArr,length*sizeof(int));
// print the memory address of the reallocated array
        printf("return address of allocArray of realloc 0x0000%xd \n",allocArr);
// fill the array again with the number of values allowed by the new length using an array assignment and a
// direct assignment
        for (int i = 0; i < length; i++) allocArr[i] = i + 1;
        for (int i = 0; i < length; i++) *(allocArr+i) = i + 1;
        printf("Contents of the array: ",sizeof(allocArr));
// print the values in the new array
        for (int i = 0; i < length; i++) printf("%d ",allocArr[i]);
        printf("\n");
        free(allocArr);
        return 0;
}
