// if not defined then define the nodes and prototypes
#ifndef CONFIG_VAR
#define CONFIG_VAR

#include <stdio.h>
#include <stdlib.h>

#define REMOVE_SUCCESS 0
#define REMOVE_FAILED 1

#define UNIQUE_ADD_SUCCESS 0
#define UNIQUE_ADD_FAILED 1

#define ITEM_NOT_FOUND 0
#define ITEM_FOUND 1

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;


LinkedList* createList(void);
void deleteList(LinkedList**);
void clearList(LinkedList*);

void addItemToEnd(LinkedList*, int);
void insertItemInFront(LinkedList*, int);
int insertIfItemNotInList(LinkedList*, int);
int removeFirstAppearance(LinkedList*, int);
int isItemInList(LinkedList*, int);

void printList(LinkedList*);
void printNode(Node*);

#endif
