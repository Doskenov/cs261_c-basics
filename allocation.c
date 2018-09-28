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
}
