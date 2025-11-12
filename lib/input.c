#include <stdio.h>
#include <stdlib.h>

// ### Start of input checking and additional definitions

// none of these values should be used directly for reusibility
#define ERRORSENTINAL -1000000000 // in general this will be the error sentinal value as it is one out of range
#define MINVALUE -999999999 // this is the minimum value a number in the list can be set to
#define MAXVALUE 999999999 // this is the maximum value a number in the list can be set to
#define MAXARRLEN 9 // this is the maximum length of the character array that is used to buffer stdin if changed will cause problems
#define MAXLISTLEN 100// this is the maximum length of the list the user can make

// supply a value and an acceptable min value up to a maximum value only uses
// the value no user input
int returnSafeInt(int value, int min, int max){
    if(value<min || value > max){
        printf("Value out of range %d to %d\n",min,max);
        return ERRORSENTINAL;
    } else {
        return value;
    }
}

int getSafeIntFromKeyboard(){
    char test[MAXARRLEN+1];// made one int larger in order to ensure that all numbers are processed
    int trueSize=0;
    fgets(test,sizeof(test),stdin);
    int size=sizeof(test);// adjust for integer addressing

    // detect a buffer overflow attempt only read the first chars that were entered into
    // the input
    while(trueSize<size && test[trueSize]!=10){
    // check to see if there is a newline character at the current place in the array
        trueSize++;
        if(trueSize>=size){
        // if the new truesize value is larger than the actual size of the array
        // but a newline has not been detected enter a for loop until the newline
        // character is read
            int c; while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }
    return atoi(test);
}
// get a number from the user but pass it through the returnSafeInt function
// based off of a ERRORSENTINAL value provided at the beginning of the file
int getSafeInt(int min, int max){
// first check the value to make sure its safe
    int value=getSafeIntFromKeyboard();
    int isSafe = returnSafeInt(value,min,max);
// if the value is not safe loop until the user enters a safe number
    while(isSafe == ERRORSENTINAL){
        printf("Please enter a number between %d and %d :",min,max);
        value=value=getSafeIntFromKeyboard();
        isSafe = returnSafeInt(value,min,max);
    }
    int overflowCatch=0;
    printf("\nINT: %d SIZE: %d OVERFLOW DETECT: %d (should be zero)\n",isSafe, sizeof(isSafe)),overflowCatch;
    return isSafe;
}

// ### End of custom input checking functions

// main execution area
int main(void) {
   int x = getIntSafely(1,10);
// continue getting input to test for buffer overflows
   printf("returned value: %d\nIf you can enter stuff here then the buffer overflow was mitigated\n",x);
   char test[2];
   fgets(test,sizeof(test),stdin);
}
