/*
Created by Nicholas Howland
Fall 2025 in CSCD 240
Purpose: learning about memory pointers
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
        printf("\n############# True Memory Addresses\n");
        printf("True memory address of x: %p\n",&x);
        printf("True memory address of p: %p\n",&p);
        printf("True memory address of l: %p\n",&l);

        printf("\n############# Stored Memory Addresses\n");
        printf("Address stored in p: %p\n",p);
        printf("Address stored in l: %p\n",l);

        printf("\n############# Value of x in each variuble\n");
        printf("x: %d\n",x);
        printf("p: %d\n",*p);
        printf("l: %d\n",**l);

        printf("\n############# Calling the Value by manual pointers\n");
        // manual memory traversal
        printf("Value of l by using the index of x %d\n\n", *(p+4) );

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
}
