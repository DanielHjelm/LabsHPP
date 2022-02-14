#include <stdio.h>
  
// Inline function in C
static inline int foo(int integer)
{
    return integer*integer*integer;
}

int bar(int integer) {
    return integer*integer*integer;
}
  
// Driver code
int main()
{
    int ret;
  
    // Inline function call
    // ret = foo(50);

    //Regular function call
    ret = bar(50);
  
    printf("Output is: %d\n", ret);
    return 0;
}