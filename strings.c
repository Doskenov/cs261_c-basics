#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  /*
   * Note that when initializing a string with a constant (i.e. with a string
   * "inside double quotes"), that string points to a location in read-only
   * memory and can't be modified.  The string should thus be declared as
   * const.  By doing this, trying to modify it, as in the commented-out line
   * below, becomes a compile-time error instead of a runtime error.
   */
  const char* name = "Lake Skywalker";
  // name[1] = 'u';
  printf("== name: %s\n", name);

  /*
   * To create strings we can manipulate, we can allocate memory for them
   * on the heap.  Note that strings in C are just arrays of characters.
   */
  int n = 64;
  char* str = malloc(n * sizeof(char));

  /*
   * strncpy() is a good function to use to copy the contents of one string
   * into another array.  Note that this is a better option than strcpy(),
   * since the latter doesn't allow us to limit the number of characters
   * copied like strncpy() does.  By limiting the number of characters copied
   * to only as many as we have allocated space for, we can protect ourselves
   * against buffer overflow attacks.
   */
  // strcpy(str, name);
  strncpy(str, name, n);
  str[1] = 'u';
  printf("== str: %s\n", str);

  /*
   * snprintf() is another function that's useful for initializing strings.
   * This function allows us to "print" content to a string in a manner similar
   * to the way we print to the console using printf().  snprintf() also limits
   * the number of characters "printed", similar to strncpy().
   */
  char* str2 = malloc(n * sizeof(char));
  snprintf(str2, n, "%s (%d)", str, 933111111);
  printf("== str2: %s\n", str2);

  /*
   * strlen() is another useful string function that returns the number of
   * printable characters in a string.  Note that this *does not* include the
   * terminating null character (\0).
   */
  printf("== strlen(str2): %lu\n", strlen(str2));

  free(str);
  free(str2);
}
