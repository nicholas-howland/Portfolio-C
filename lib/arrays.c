#include <stdio.h>

/*
array starts at the base memory location
and increments upward from there. Negative
and postiive values can be called but may
cause crashes.
*/

#define NEW_ARR_SIZE 10

int main(void) {
        // can only define an array size with a #define preprocessor
        int newArray[NEW_ARR_SIZE];
        for(int i; i < NEW_ARR_SIZE; i++) {
                newArray[i]=i+1;
        }

        printf("Array contents: ");
        for(int i; i < NEW_ARR_SIZE; i++) {
                printf("%d ",newArray[i]);
        }
        printf("\n");
        // 0x%08 wants 8 digits wide with 0s as fillers
        // x option says print in hexadecimal
        printf("Base addr: 0x%08x\n",newArray);
        printf("Base addr: 0x%08x\n",newArray[0]);
        printf("Base addr: 0x%08x\n",newArray[NEW_ARR_SIZE-1]);


        // xor for giggles
        printf("\nXOR Logic\n");
        int a = 8;
        a = a ^ 1;
        printf("        00010000\n");
        printf("        10000000\n");
        printf("\n      10010000\n");

        printf("8 XOR 1: %d\n",a);
        a = a ^ 8;
        printf("        10010000\n");
        printf("        00010000\n");
        printf("\n      10000000\n");
        printf("9 XOR 8: %d\n",a);


        return 0;

}
