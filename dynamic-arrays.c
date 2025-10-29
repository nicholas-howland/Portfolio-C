#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
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
  for (int i = 0; i < n; i++) {
    arr[i] = i * 10;
  }
  int m;
  printf("Enter an additional number of elements to add to the end of the list: ");
  scanf("%d", &m);
  // reallocate the array to be how ever many times bigger the user asked them to be
  arr = realloc(arr, (n + m) * sizeof(int));
  for (int i = n; i < n + m; i++) {
    arr[i] = i * 10;
  }
  // print out the allocated memory
  for (int i = 0; i < n + m; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  free(arr);
  return 0;
}
