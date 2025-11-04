/*
Created by Nicholas Howland
Fall 2025 in CSCD 240
Purpose: to understand structs.
*/
// included libraries
#include <stdio.h>

// create a simple strut

struct bestStruct {
  int number;
  int letter;
};

// can nest structs within structs
struct Owner {
  char firstName[30];
  char lastName[30];
};

// super structure
struct Car {
  char car[30];
  int year;
  struct Owner owner;// nested structure
};

// main execution area
int main(void) {
  // initialize the struct
  struct bestStruct s1;
  // pointer to s1
  struct bestStruct *ptr = &s1;
  // initialize the structs in a different way
  struct bestStruct s2 = {61,'A'};
  // assign values to struct vars
  s1.number = 62;
  s1.letter = 'B';
  printf("Number in s1: %d\n",s1.number);
  printf("String in s1: %c\n",s1.letter);
  printf("\n");
  printf("Number in s2: %d\n",s2.number);
  printf("String in s2: %c\n",s2.letter);
  printf("\n");
  // use dereferenced pointer to the original struct
  ptr->number=63; // using an arrow is the exact same as (*ptr).number but simpler
  ptr->letter='C';
  printf("Number in s1: %d\n",s1.number);
  printf("String in s1: %c\n",s1.letter);
  printf("\n");

  // set up the nested structure
  struct Owner person1 = {"Alice","Rabbit"};
  struct Car car1 = {"BMW",1999,person1};
  printf("Owner Name %s %s\n",car1.owner.firstName,car1.owner.lastName);
  printf("Car: %s (%d)\n",car1.car,car1.year);
  printf("\n");
  printf("\n");


  return 0;
}
