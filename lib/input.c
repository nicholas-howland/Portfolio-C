#include <stdio.h>
#include <stdlib.h>

int getIntSafely(){
// get int safely function
    char test[10];// it is one biger than we need it because the \0 char will always be the last one
    int trueSize=0;
    fgets(test,sizeof(test),stdin);
    int size=sizeof(test)-1;// adjust for integer addressing

    // detect a buffer overflow attempt only read the first chars that were entered into
    // the input
    while(trueSize<size && test[trueSize]!=10){
    // check to see if there is a newline character at the current place in the array
        trueSize++;
        if(trueSize>=size){
        // if the new truesize value is larger than the actual size of the array
        // enter a for loop until the newline character is read
            int c; while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }

// print out some stats about the new array including its integer value if possible
    printf("size of array: %d\n",sizeof(test));
    printf("last char: %c\n",test[size-1]);
    printf("last decimal: %d\n",test[size-1]);
    // atoi will convert chars to ints up to the first non decimal character
    printf("string to int: %d\n",atoi(test));
    printf("True size of array: %d\n",trueSize);
    return atoi(test);
}

// main execution area
int main(void) {
   int x = getIntSafely();
// continue getting input to test for buffer overflows
   printf("returned value: %d\nIf you can enter stuff here then the buffer overflow was mitigated\n",x);
   char test[2];
   fgets(test,sizeof(test),stdin);
}
