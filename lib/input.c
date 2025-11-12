#include <stdio.h>
#include <stdlib.h>

// main execution area
int main(void) {

// Example of semi-safe input  
  char test[10];
  printf("%s\n",fgets(test,sizeof(test),stdin));
  // clear buffer that is being streamed to functions through stdin
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
  // continue getting input
  printf("%s\n",fgets(test,sizeof(test),stdin));


}
