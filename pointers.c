
/*
Created by Nicholas Howland
Fall 2025 in CSCD 240
Purpose: messing with pointers
*/
// included libraries
#include <stdio.h>

void update(int *n){
        *n = *n*10;
}

// main execution area
int main(void) {
        printf("Working with pointers!\n");

        int x = 42;
        int *p = &x;
        int **l = &p;

        printf("True memory address of x: %p\n",&x);
        printf("True memory address of p: %p\n",&p);
        printf("True memory address of l: %p\n",&l);


        printf("Address stored in p of x: %p\n",p);
        // an * will de-reference the variuble p and get the pointer to x
        printf("Value stored in x using a pointer: %d\n\n",*p);

        // must use two * because this is a pointer to a pointer

        // manual memory traversal
        printf("Vallue of l by using the index of x %d\n", *(p+4) );

        int arr[5] ={1,2,3,4,5};
        int *ptr = arr;
        // calling the array by the pointer
        for ( int i =0; i <5; i++){
                printf("Value in array at <%p> %d\n",(ptr+i),*(ptr+i));
        }

        for ( int i =0; i <5; i++){
                update(&arr[i]);
                printf("Upadted value in array at <%p> %d\n",(ptr+i),*(ptr+i));
        }

        return 0;
