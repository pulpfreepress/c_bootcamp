/* Demonstrate pointers. */

#include <stdio.h>

int main(){
    int a = 3;
    int* a_ptr = &a;

    printf("a = %d\n", a);
    printf("address of a = %p\n", &a);

    printf("a_ptr = %p\n", a_ptr);
    printf("address of a_ptr = %p\n", &a_ptr);
    
    printf("a = %d\n", *a_ptr);
    printf("address of a = %p\n", a_ptr);
    return 0;
}