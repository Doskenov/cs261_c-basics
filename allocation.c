#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main() {
  /*
   * Use malloc() to allocate space for a single integer on the heap.  We use
   * sizeof() to tell us how many bytes an element of a particular data type
   * needs.
   */
  int* i = malloc(sizeof(int));
  printf("== sizeof(int): %lu\n", sizeof(int));

  /*
   * Update the value stored at the memory address pointed to by i by
   * dereferencing i.
   */
  *i = 24;
  printf("== *i: %d\n", *i);

  /*
   * We can also use malloc() to dynamically allocate memory for a struct.
   * Note that to access the fields of a struct when we have a pointer to
   * that struct, we need to dereference the pointer.  The arrow operator
   * (i.e. ->) both dereferences a struct pointer and accesses one of its
   * fields.
   */
  struct student* s = malloc(sizeof(struct student));
  s->gpa = 4.0;
  s->id = 933333333;
  s->name = "Han Solo";
  printf("== %s (%d): %f\n", s->name, s->id, s->gpa);

  /*
   * We can also use malloc() to allocate memory on the heap for an array.
   * Here, we dynamically allocate an array of 32 integers and initialize
   * the values of the elements of the array.
   */
  int j, n = 32;
  int* nums = malloc(n * sizeof(int));
  for (j = 0; j < n; j++) {
    nums[j] = j * j;
  }

  /*
   * Here, we're printing different values associated with our array.  Note
   * that both nums and &nums[0] are the same address.  Specifically, they
   * both point to the beginning of the chunk of memory we allocated above.
   * In particular, note that we can dereference nums itself to modify the
   * value of nums[0].  We can use pointer arithmetic to do something similar
   * to other elements of the array.
   */
  printf("== nums: %p\n", nums);
  printf("== &nums[0]: %p\n", &nums[0]);
  printf("== &nums[10]: %p\n", &nums[10]);
  *nums = 1000000;
  printf("== nums[0]: %d\n", nums[0]);
  *(nums + 10) = 2000000;
  printf("== nums[10]: %d\n", nums[10]);

  /*
   * We allocate an array of structs the same way as we allocate an array
   * of ints, multiplying the size of the struct by the number we want to
   * allocate, and passing the resulting number of bytes to malloc.
   *
   * We can access the fields of the elements of an array of structs using the
   * dot operator, as below.
   */
  int m = 64;
  struct student* students = malloc(m* sizeof(struct student));
  for (j = 0; j < m; j++) {
    students[j].name = "Luke Skywalker";
    students[j].standing = 1;
    students[j].gpa = 4.0;
  }
  printf("\n\n");
  printf("students[4].name: %s\n", students[4].name);

  /*
   * A 2D array is actually represented as a 1D array of 1D arrays, i.e. a
   * pointer to an array of pointers, each of which points to a 1D array of
   * elements.  To allocate a 2D array, we need to allocate memory for the
   * outer 1D array of pointers, and then allocate a 1D array for each of
   * those pointers to point to.
   *
   * Here's how it would look to allocate an m x n array of ints.
   */
  int** matrix = malloc(m * sizeof(int*));
  for (j = 0; j < m; j++) {
    matrix[j] = malloc(n * sizeof(int));
  }

  free(i);
  free(s);
  free(nums);
  free(students);

  /*
   * In order to free the memory allocated to our 2D array, we need to reverse
   * what we did to allocate it.  Specifically, we need to free each of the
   * inner 1D arrays of ints before we free the outer 1D array of pointers.
   */
  for (j = 0; j < m; j++) {
    free(matrix[j]);
  }
  free(matrix);
}
