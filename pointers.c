#include <stdio.h>
#include "student.h"

/*
 * We can use pointers to accomplish the same effect as pass-py-reference in
 * C++.  If we pass a pointer to a value (i.e. the memory address where that
 * value is stored), we can update the underlying value from within a function
 * (using a pointer), and the update will affect that value in the calling
 * function.
 */
void make_it_32(int* it) {
    *it = 32;
}

void foo(int x) {
    printf("== x: %d\n", x);
}

int main() {
    /*
     * Declare an integer variable and a pointer to an integer.  Initialize
     * the pointer to point to the memory location occupied by the original
     * integer.
     */
    int i = 16;
    int* i_ptr = &i;

    /*
     * Print the value of our integer, the value of our pointer, and the
     * memory address of the integer, the latter two of which will be the same.
     * Also, dereference i_ptr (i.e. *i_ptr) to see the value stored at the
     * memory address held in i_ptr.  Also, print the memory address where i_ptr
     * itself lives, which is different than the address value it stores (which
     * is the address of i).
     */
    printf("== i: %d\n", i);
    printf("== i_ptr: %p\n", i_ptr);
    printf("== &i: %p\n", &i);
    printf("== *i_ptr: %d\n", *i_ptr);
    printf("== &i_ptr: %d\n", &i_ptr);

    /*
     * Dereference i_ptr (i.e. *i_ptr) to update the value stored at the memory
     * address held in i_ptr.  Note that this updates the value of i itself.
     * However, the memory addresses where i and i_ptr themselves live do not
     * change.
     */
    *i_ptr = 8;
    printf("\n\n");
    printf("== i: %d\n", i);
    printf("== i_ptr: %p\n", i_ptr);
    printf("== &i: %p\n", &i);
    printf("== *i_ptr: %d\n", *i_ptr);
    printf("== &i_ptr: %d\n", &i_ptr);

    /*
     * Demonstrate how we can simulate pass-by-reference by passing the address
     * of i into our make_it_32() function.  When this function returns, the
     * value of i will be changed to 32.  Note that we could also pass i_ptr as
     * the argument to make_it_32() here and it would have the same effect.
     */
    make_it_32(&i);
    // make_it_32(i_ptr);
    printf("\n\n");
    printf("== i: %d\n", i);
    printf("== i_ptr: %p\n", i_ptr);
    printf("== &i: %p\n", &i);
    printf("== *i_ptr: %d\n", *i_ptr);
    printf("== &i_ptr: %d\n", &i_ptr);

    foo(2+4);

    /*
     * Create a new student struct and a pointer to that struct.  We can
     * set and access the fields of the struct via the pointer using the
     * arrow operator (->).
     */
    struct student s = {.name = "Leia Organa", .id = 933222222};
    struct student* s_ptr = &s;
    (*s_ptr).gpa = 4.0;
    s_ptr->gpa = 4.0;
    printf("== %s (%d): %f\n", s_ptr->name, s_ptr->id, s_ptr->gpa);

}
