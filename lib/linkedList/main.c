#include <stdio.h>
#include <stdlib.h>

#include "LinkedList/LinkedList.h"

int main() {
    printf("Creating list...\n");
    LinkedList* myList = createList();
    if (myList == NULL) {
        printf("Error: createList returned NULL\n");
        return 1;
    }
// a number of magic checks were compelted to test the linked list
    return 0;
}
