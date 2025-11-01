/*
Created by Nicholas Howland
Fall 2025 in CSCD 240
Purpose: learning about memory allocation for arrays and memalloc, realloc and free functions
*/
// included libraries
#include <stdio.h>
#include <stdlib.h>

#define SENTINAL -1

// function to print the array based on a length supplied by the user
void printArrayByLen(int *arr[0], int arrLen){
  for (int i = 0; i < arrLen; i++) {
    printf("%d ", *(arr[0]+i));
  }
  printf("\n");
}

// function to print the array based on a sentinal value provided
// not set to the defined value of SENTINAL for interoperability
void printArrayBySentinal(int *arr[0], int sentinal){
  int i=0;
  while(*(arr[0]+i) != sentinal){
    printf("%d ", *(arr[0]+i));
    i++;
  }
  printf("\n");
}


void fillArray(int *location, int length, int startIndex){
  for (int i = 0; i < length; i++) {
    *(location+i+startIndex) = i * 10;
  }
  // reallocate the array to have one more index and assign a sentinal value to it
  // side note: sentinal values are one way to terminate arrays but you could do it
  // based on patterns which would allow for the sentinal value to be used if needed
  location = realloc(location, (length+1)*sizeof(int));
  *(location+length)=SENTINAL;
}


int main() {
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  // create the dynamic array by using the supplied number and allocating n*(the size of an intiger)
  int *arr = malloc(n * sizeof(int));
  // error handling
  if (!arr) {
    printf("Array failed to initialize");
    return 1;
  }
  // fill the array
  int m;
  printf("Enter an additional number of elements to add to the end of the list: ");
  scanf("%d", &m);
  // reallocate the array to be how ever many times bigger the user asked them to be
  arr = realloc(arr, (n + m) * sizeof(int));
  fillArray(arr,n+m,0);

  // print out the allocated memory using the custom function printArr(int arrLen);
  printf("Printing array by a defined length\n");
  printArrayByLen(&arr,n+m);
  printf("Printing array by finding the sentinal value of \\0\n");
  printArrayBySentinal(&arr,SENTINAL);

// assign the second value in the array to be the sentinal value
  printf("\n");
  printf("Changing the second value in the array to be the sentinal value.\n");
  arr[2]=SENTINAL;

// print the array using the two functions used previously
  printf("Printing array by the previously defined length, it will print the whole array\n regardless of what the sentinal value is or where it is found in the array\n");
  printArrayByLen(&arr,n+m);
  printf("Printing array by finding the sentinal value that was set and assigned to the array\n");
  printArrayBySentinal(&arr,SENTINAL);

  // be kind please rewind ( free up memory that is held by the array )
  free(arr);
  return 0;
}
