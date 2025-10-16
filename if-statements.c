// include libraries
#include <stdio.h>

// define a configuration value that will relpace all instances of VALUE
#define VALUE 20

int main(void) {
        // set a constant value
        const int value = VALUE;
        if (value < 10) { // if the value is less than 10
                printf("Value is less than 10\n");
        } else if (value > 10) { // if the value is greater than 10
                printf("Value is more than 10\n");
        } else { // by definition if the value is neither
                 //greater nor less than 10 it must be equal to 10
                printf("Value is 10!\n");
        }
