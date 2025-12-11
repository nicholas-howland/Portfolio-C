#include "LinkedList.h"

Node* createNode(int); //prototype
int insertValue(LinkedList* list, int value);
int deleteValue(LinkedList* list, int value);
void sortList(LinkedList* list);
LinkedList* menu(LinkedList *list);

/*
additional requirements
- when creating the list prompt for values using a function named menu() with the following options
  - printList(LinkedList* list) // prints the list // done!
  - insertValue(LinkedList* list, int value); // inserts a value at the end of the list
  - deleteValue(LinkedList* list, int value); // deletes a value in the list if it exists
  - sortList(LinkedList* list); // sort the values in the list
  - clearlist(LinkedList* list); // clears the list // done!
  - quit by returning out of the loop; // exit the menu;


*/

LinkedList* menu(LinkedList *list){
    int exit=0;
    char choiceChar[4];
    int choice=0;
    int result=0; // returns a functions exit status

    while(exit==0){
        // make choice
        do {
            printf("Please enter a menu choice\n");
            printf("1) Display the list\n");
            printf("2) Insert a new value at the end of the list\n");
            printf("3) Remove a value in the list (removes the first occurance)\n");
            printf("4) Sort the list from smallest to greatist\n");
            printf("5) Clear the list\n");
            printf("6) Quit\n");
            printf("Choice --> ");
            fgets(choiceChar,sizeof(char)*4,stdin);
            choice=atoi(choiceChar);
        } while(choice < 0 || choice > 6);

        // handle choice
        if(choice == 6){
            exit=1;
            clearList(list);
            printf("Clearing the list and displaying checks\n");
            return list;
        } else if(choice == 5) {
            clearList(list);
        } else if(choice == 4) {
            sortList(list);
        } else if(choice == 3) {
            printf("Value to remove in list: ");
            fgets(choiceChar,sizeof(char)*4,stdin);
            result = removeFirstAppearance(list, atoi(choiceChar));
            if (result == REMOVE_FAILED) {
                printf("Value not found in list\n");
            }
        } else if(choice == 2) {
            printf("Value to add to end of list: ");
            fgets(choiceChar,sizeof(char)*4,stdin);
            addItemToEnd(list, atoi(choiceChar));
        } else if(choice == 1) {
            printf("Currently the list is: \n");
            printList(list);
        }
    }

}


// sort the linked list
void sortList(LinkedList* list){
    if (list->head == NULL) {
        return;
    }
    // create two nodes for traversal
    Node *swapNode=list->head;
    Node *tempNode=list->head;

    // while the swapnode is not at the end of the list then keep traversing
    while(swapNode != NULL){
        // iterate through the list until there is nothing to compare the node to
        while(tempNode->next != NULL){
            // if the tempNode is smaller than the
            if(tempNode->data > tempNode->next->data){
                int tempData=tempNode->data;
                tempNode->data=tempNode->next->data;
                tempNode->next->data=tempData;
            }
            tempNode=tempNode->next;
        }
        // swap traversal
        tempNode=list->head;
        swapNode=swapNode->next;
    }

}

/*
     Dynamically allocate a LinkedList and return the pointer
    The List's head pointer is NULL (there are no items in the list)

    Returns NULL if the allocation fails
*/

LinkedList* createList(void) {
  LinkedList * newLinkedList = malloc(sizeof(struct Node));
  newLinkedList->head=NULL;
// enter into the menu loop
  menu(newLinkedList);
  return newLinkedList;

}



/*
    Given a pointer to a linked list pointer (LinkedList**):
    1. Free all nodes (you can call clearList)
    2. Free the LinkedList struct itself
    3. Set the original pointer (*list) to NULL
*/
void deleteList(LinkedList** list) {
    if (list == NULL) {
        return;
    }
    if (*list == NULL) {
        return;
    }
    // you do the rest
    clearList(*list);
    free(*list);
    *list = NULL; //last line of the function
}

/*
    frees and removes ALL nodes in the list
*/
void clearList(LinkedList* list) {
    if (list == NULL) {
        return;
    }
    // while the head node is not Null
    Node *traversalNode = list->head;
    while(list->head->next != NULL){
    // create a recursive while loop to clear out the last node in the list
        // if the value after next is null then remove it and update the next pointer of the
        // current node to be null
        if(traversalNode->next->next == NULL){
            free(traversalNode->next);
            traversalNode->next = NULL;
            traversalNode=list->head;
        // if the next value is null then that means that we have reached the end of the list
        } else if(traversalNode->next==NULL){
            free(traversalNode);
            traversalNode=list->head;
        // otherwise continue traversal
        } else {
            traversalNode = traversalNode->next;
        }
    }

    free(traversalNode);
    list->head = NULL;
}

/*
    Given a linked list:
    create a new node with the given data and add it to the end of the list
*/
void addItemToEnd(LinkedList* list, int data) {
  if (list == NULL) {
        return;
  }

// start with the first node in the list
  Node *currentNode=list->head;

// if the head node is empty then create the head node
  if(currentNode==NULL){
    list->head=createNode(data);
    return;

// otherwise traverse the linked list until the next node with an empty value is found
  } else {
      // traverse the list
      while(currentNode->next != NULL){
        currentNode=currentNode->next;
      }
      // create a node at the end of the list
      currentNode->next = createNode(data);
  }
}
/*
    Given a linked list:
    create a new node with the given data and add it to the front of the list
    The new node then becomes the head of the list

*/
void insertItemInFront(LinkedList* list, int data) {
  if (list == NULL) {
        return;
  }
// start with the first node in the list
  Node *currentNode=list->head;

// if the head node is empty then create the head node
  if(currentNode==NULL){
    list->head=createNode(data);
    return;
  } else {
      // a couple more steps are done after traversing the list to add a value in front...

      // first we create a copy of the second to last node to the last node
      currentNode->next = createNode(currentNode->data);
      // next we move through the list from the front copying data forward as long as
      // the swapNode is not equal to the last node
      Node *swapNode = list->head;
      while(swapNode->next != currentNode->next){
          swapNode=swapNode->next;
      }
      // finally we update the head node with the desired value without creating a new node
      list->head->data = data;
  }

// debuggery
//  printf("HEADADDR: %p\n",&list->head->data);
//  printf("HEADDATA: %d\n",list->head->data);
//  printf("NEXTADDR: %p\n",&list->head->next->data);
//  printf("NEXTDATA: %d\n",list->head->next->data);

}

/*
    Given the linked list:
    If the value "data" is not already in the list, insert it into the front
    (you can use insertItemInFront)
    Then return UNIQUE_ADD_SUCCESS

    Otherwise, if the item is already in the list, return UNIQUE_ADD_FAILED and
   do nothing else Return UNIQUE_ADD_FAILED if the list pointer is NULL
*/
int insertIfItemNotInList(LinkedList* list, int data) {
    return UNIQUE_ADD_FAILED;
// TODO

}

/*
    Searches the list for "data", and if found, removes the first instance
    Returns REMOVE_SUCCESS if the item was removed, REMOVE_FAILED if not
    Returns REMOVE_FAILED if the list pointer is NULL
*/
int removeFirstAppearance(LinkedList* list, int data) {
// if the list is empty then return a REMOVE_FAILED
  if(list==NULL){
    return REMOVE_FAILED;
  }

  // get the first node
  Node *currentNode=list->head;
// if the head node contains the data we seek then remove it
  if(currentNode->data == data){
    list->head = list->head->next;
    free(currentNode);
    return REMOVE_SUCCESS;

// otherwise traverse the linked list until the next node with an empty value is found
  } else {
      // traverse the list
      while(currentNode->next != NULL){
        // if the next data in the list is the data we seek
        if(currentNode->next->data == data){
            // create a temporary node so we can save the pointer to the node after next
            Node *forDeletion = currentNode->next;
            // update the current nodes next pointer to be the node after next
            currentNode->next = currentNode->next->next;
            // properly free the node that was marked for deletion
            free(forDeletion);
            return REMOVE_SUCCESS;
        }
        currentNode=currentNode->next;
      }
      // create a node at the end of the list
  }

     return REMOVE_FAILED;
    }

/*
    Search the list and return if the item is in the list
    Returns ITEM_NOT_FOUND if the item is not in the list, or the list pointer
   == NULL returns ITEM_FOUND if the item is in the list
*/
int isItemInList(LinkedList* list, int data) {
    // if list does not exist then the item was not found
    if(list==NULL){
        return ITEM_NOT_FOUND;

    // otherwise traverse the list
    } else {
      // make a swap node
      Node *swapNode = list->head;
      // traverse the list
      while(swapNode->next){
          // if the swapNodes data is the data we seek then return ITEM_FOUND
          if(swapNode->data == data){
              return ITEM_FOUND;
          }
          swapNode=swapNode->next;
      }
    }
    // if the end of the list is reached without finding the data then return ITEM_NOT_FOUND
    return ITEM_NOT_FOUND;
}

/*
    This does not appear in the .h because it is a helper function
    You may use this if you'd like, so when you need a new node you can call
   this function otherwise you will be calling malloc in multiple places
*/
Node* createNode(int data) {
  Node *NewNode = malloc(sizeof(Node));
  NewNode->data = data;
  NewNode->next = NULL;
  return NewNode;
  }

// DO NOT MODIFY THESE PRINT FUNCTIONS
// THESE SHOULD BE THE ONLY PRINT FUNCTIONS THAT YOU CALL
void printList(LinkedList* list) {
    Node* cur = list->head;
    while (cur) {
        printNode(cur);
        cur = cur->next;
    }
}

void printNode(Node* node) { printf("%d\n", node->data); }
